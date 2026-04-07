#include "common.h"
#include "elf.h"
#include "debug.h"

func_array_t func_array = {.count = 0};

static int func_cmp(const void *a, const void *b) { // compare by start_addr
    const func_t *fa = (const func_t *)a;
    const func_t *fb = (const func_t *)b;
    if (fa->start_addr < fb->start_addr) return -1;
    if (fa->start_addr > fb->start_addr) return 1;
    return 0;
}

static void func_array_sort(void) { // sort by start_addr, for binary search
    if (func_array.count <= 1) {
        return;
    }
    qsort(func_array.arr, func_array.count, sizeof(func_array.arr[0]), func_cmp);
}

static void func_array_push(const char *str, uint32_t start_addr, uint32_t end_addr) {
    assert(end_addr >= start_addr);  // size must be >= 0
    int count = func_array.count;
    Assert(count < MAX_FUNC_NUM, "ftrace: func_array out of bound");

    size_t max_name_len = sizeof(func_array.arr[count].name) - 1;
    size_t name_len = strnlen(str, max_name_len + 1);
    Assert(name_len <= max_name_len,
        "ftrace: symbol name is too long (%zu), max allowed is %zu", name_len, max_name_len);

    memcpy(func_array.arr[count].name, str, name_len);
    func_array.arr[count].name[name_len] = '\0';

    func_array.arr[count].start_addr = start_addr;
    func_array.arr[count].end_addr = end_addr;
    func_array.count++;
}

int func_array_search(char *name, uint32_t addr, bool *is_func_entry) {
    assert(name != NULL);
    assert(is_func_entry != NULL);
    int left = 0, right = func_array.count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        const func_t *f = &func_array.arr[mid];
        if (f->start_addr == f->end_addr) {  // size == 0: only match the entry point
            if (addr < f->start_addr) {
                right = mid - 1;
            }
            else if (addr > f->start_addr) {
                left = mid + 1;
            }
            else {
                strcpy(name, f->name);
                *is_func_entry = true;
                return 1;
            }
        }
        else if (addr < f->start_addr) {
            right = mid - 1;
        }
        else if (addr >= f->end_addr) {
            left = mid + 1;
        }
        else {            
            strcpy(name, func_array.arr[mid].name);
            *is_func_entry = (addr == f->start_addr);
            return 1;
        }
    }
    *is_func_entry = false;
    return 0;
}

static void ftrace_load_elf(const char *elf_file) {
    FILE *fp = fopen(elf_file, "rb");
    Assert(fp != NULL, "ftrace: cannot open ELF file '%s'", elf_file);

    Elf32_Ehdr eh32;

    size_t nread = fread(&eh32, 1, sizeof(eh32), fp);
    Assert(nread == sizeof(eh32), "ftrace: short read of ELF32 header from '%s'", elf_file);

    // check magic number
    Assert(eh32.e_ident[EI_MAG0] == ELFMAG0 &&
         eh32.e_ident[EI_MAG1] == ELFMAG1 &&
         eh32.e_ident[EI_MAG2] == ELFMAG2 &&
         eh32.e_ident[EI_MAG3] == ELFMAG3,
         "ftrace: bad ELF magic in '%s'", elf_file);

    Elf32_Shdr *sh_table = static_cast<Elf32_Shdr*>(malloc(eh32.e_shentsize * eh32.e_shnum));  // section header table
    Assert(sh_table != NULL, "ftrace: cannot allocate memory for ELF section header table");

    int ret;
    ret = fseek(fp, eh32.e_shoff, SEEK_SET);
    Assert(ret == 0, "ftrace: fseek to section header table failed for '%s'", elf_file);

    nread = fread(sh_table, eh32.e_shentsize, eh32.e_shnum, fp);
    Assert(nread == eh32.e_shnum, "ftrace: short read of ELF section header table from '%s'", elf_file);

    // Read shstrtab
    Elf32_Shdr *shstrtab_entry = &sh_table[eh32.e_shstrndx];
    ret = fseek(fp, shstrtab_entry->sh_offset, SEEK_SET);
    Assert(ret == 0, "ftrace: fseek to shstrtab section failed");

    char *shstrtab = static_cast<char*>(malloc(shstrtab_entry->sh_size));
    assert(shstrtab);
    nread = fread(shstrtab, shstrtab_entry->sh_size, 1, fp);
    Assert(nread == 1, "ftrace: short read of ELF shstrtab section");

    Elf32_Shdr *strtab_entry = NULL, *symtab_entry = NULL;

    // find entries of strtab and symtab in sh_table
    for(int i = 0; i < eh32.e_shnum; i++) {
        Elf32_Shdr *sh_entry = &sh_table[i];
        if(sh_entry->sh_type == SHT_STRTAB) {
            char *section_name = shstrtab + sh_entry->sh_name;
            if(strcmp(section_name, ".strtab") == 0) {
                strtab_entry = sh_entry;
            }
        }
        else if(sh_entry->sh_type == SHT_SYMTAB) {
            char *section_name = shstrtab + sh_entry->sh_name;
            if(strcmp(section_name, ".symtab") == 0) {
                symtab_entry = sh_entry;
            }
        }
    }
    Assert((strtab_entry != NULL) && (symtab_entry != NULL), "ftrace: fail to find section header entry of strtab and symtab");

    // Read strtab
    ret = fseek(fp, strtab_entry->sh_offset, SEEK_SET);
    Assert(ret == 0, "ftrace: fseek to strtab section failed");
    char *strtab = static_cast<char*>(malloc(strtab_entry->sh_size));
    assert(strtab);
    nread = fread(strtab, strtab_entry->sh_size, 1, fp);
    Assert(nread == 1, "ftrace: short read of ELF strtab section");

    // Read symtab
    Elf32_Sym *symtab = static_cast<Elf32_Sym*>(malloc(symtab_entry->sh_size));
    assert(symtab);
    ret = fseek(fp, symtab_entry->sh_offset, SEEK_SET);
    Assert(ret == 0, "ftrace: fseek to symtab section failed");

    assert(symtab_entry->sh_size % symtab_entry->sh_entsize == 0);
    int symtab_num = symtab_entry->sh_size / symtab_entry->sh_entsize;
    nread = fread(symtab, symtab_entry->sh_entsize, symtab_num, fp);
    Assert(nread == symtab_num, "ftrace: short read of ELF symtab section");

    // Search for FUNC symbols in symtab and push into func_array
    for(int i = 0; i < symtab_num; i++) {
        int st_type = ELF32_ST_TYPE(symtab[i].st_info);
        if(st_type == STT_FUNC) {
            char *symbol_name = strtab + symtab[i].st_name;
            uint32_t start_addr = symtab[i].st_value;
            uint32_t end_addr = start_addr + symtab[i].st_size;
            func_array_push(symbol_name, start_addr, end_addr);
        }
    }

    func_array_sort();

    free(sh_table);
    free(shstrtab);
    free(strtab);
    free(symtab);
}

void init_ftrace(const char *elf_file) {
  if (elf_file == NULL) {
    Log("No ELF file is given for ftrace. Function tracing will be disabled.");
    return;
  }
  Log("Loading ELF file '%s' for ftrace...", elf_file);
  ftrace_load_elf(elf_file);
}
