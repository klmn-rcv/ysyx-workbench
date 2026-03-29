// #include <common.h>

// #ifndef CONFIG_TARGET_AM

// #include <elf.h>
// #include <stdio.h>

// typedef struct {
//   uint64_t start;
//   uint64_t size;
//   char *name;
// } ftrace_func_t;

// static ftrace_func_t *g_funcs = NULL;
// static size_t g_func_nr = 0;
// static size_t g_func_cap = 0;

// static void ftrace_clear(void) {
//   for (size_t i = 0; i < g_func_nr; i++) {
//     free(g_funcs[i].name);
//   }
//   free(g_funcs);
//   g_funcs = NULL;
//   g_func_nr = 0;
//   g_func_cap = 0;
// }

// static void ftrace_push_func(const char *name, uint64_t start, uint64_t size) {
//   if (g_func_nr == g_func_cap) {
//     size_t new_cap = (g_func_cap == 0 ? 64 : g_func_cap * 2);
//     ftrace_func_t *new_buf = realloc(g_funcs, new_cap * sizeof(*new_buf));
//     Assert(new_buf != NULL, "ftrace: out of memory when growing symbol table");
//     g_funcs = new_buf;
//     g_func_cap = new_cap;
//   }

//   size_t n = strlen(name);
//   char *name_copy = malloc(n + 1);
//   Assert(name_copy != NULL, "ftrace: out of memory when copying symbol name");
//   memcpy(name_copy, name, n + 1);

//   g_funcs[g_func_nr].start = start;
//   g_funcs[g_func_nr].size = size;
//   g_funcs[g_func_nr].name = name_copy;
//   g_func_nr++;
// }

// static uint8_t *read_elf_image(const char *path, size_t *out_size) {
//   FILE *fp = fopen(path, "rb");
//   Assert(fp != NULL, "ftrace: cannot open ELF file '%s'", path);

//   int ret = fseek(fp, 0, SEEK_END);
//   Assert(ret == 0, "ftrace: fseek(END) failed for '%s'", path);
//   long fsz = ftell(fp);
//   Assert(fsz >= 0, "ftrace: ftell failed for '%s'", path);
//   ret = fseek(fp, 0, SEEK_SET);
//   Assert(ret == 0, "ftrace: fseek(SET) failed for '%s'", path);

//   size_t size = (size_t)fsz;
//   uint8_t *buf = malloc(size);
//   Assert(buf != NULL, "ftrace: cannot allocate %zu bytes for ELF image", size);

//   size_t nread = fread(buf, 1, size, fp);
//   Assert(nread == size, "ftrace: short read for '%s' (%zu/%zu)", path, nread, size);

//   fclose(fp);
//   *out_size = size;
//   return buf;
// }

// static void parse_elf32(const uint8_t *img, size_t img_size, const Elf32_Ehdr *eh) {
//   Assert(eh->e_shoff != 0, "ftrace: ELF32 has no section header table");
//   Assert(eh->e_shentsize >= sizeof(Elf32_Shdr), "ftrace: invalid ELF32 section header size");
//   Assert((size_t)eh->e_shoff + (size_t)eh->e_shnum * eh->e_shentsize <= img_size,
//       "ftrace: ELF32 section header table is out of file range");

//   const uint8_t *sh_base = img + eh->e_shoff;
//   Elf32_Shdr symtab = {0};
//   bool found_symtab = false;

//   for (uint16_t i = 0; i < eh->e_shnum; i++) {
//     const uint8_t *ent = sh_base + (size_t)i * eh->e_shentsize;
//     Elf32_Shdr sh;
//     memcpy(&sh, ent, sizeof(sh));
//     if (sh.sh_type == SHT_SYMTAB) {
//       symtab = sh;
//       found_symtab = true;
//       break;
//     }
//   }

//   Assert(found_symtab, "ftrace: ELF32 has no SHT_SYMTAB");
//   Assert(symtab.sh_link < eh->e_shnum, "ftrace: ELF32 symtab links invalid strtab index");
//   Assert(symtab.sh_entsize >= sizeof(Elf32_Sym), "ftrace: invalid ELF32 symtab entsize");
//   Assert((size_t)symtab.sh_offset + symtab.sh_size <= img_size, "ftrace: ELF32 symtab out of range");

//   const uint8_t *str_ent = sh_base + (size_t)symtab.sh_link * eh->e_shentsize;
//   Elf32_Shdr strtab;
//   memcpy(&strtab, str_ent, sizeof(strtab));
//   Assert((size_t)strtab.sh_offset + strtab.sh_size <= img_size, "ftrace: ELF32 strtab out of range");

//   const char *str_base = (const char *)(img + strtab.sh_offset);
//   const uint8_t *sym_base = img + symtab.sh_offset;
//   size_t sym_nr = symtab.sh_size / symtab.sh_entsize;

//   for (size_t i = 0; i < sym_nr; i++) {
//     const uint8_t *ent = sym_base + i * symtab.sh_entsize;
//     Elf32_Sym sym;
//     memcpy(&sym, ent, sizeof(sym));

//     if (ELF32_ST_TYPE(sym.st_info) != STT_FUNC || sym.st_size == 0 || sym.st_name >= strtab.sh_size) {
//       continue;
//     }

//     const char *name = str_base + sym.st_name;
//     const void *end = memchr(name, '\0', strtab.sh_size - sym.st_name);
//     Assert(end != NULL, "ftrace: ELF32 symbol name is not NUL-terminated");

//     ftrace_push_func(name, sym.st_value, sym.st_size);
//   }
// }

// static void parse_elf64(const uint8_t *img, size_t img_size, const Elf64_Ehdr *eh) {
//   Assert(eh->e_shoff != 0, "ftrace: ELF64 has no section header table");
//   Assert(eh->e_shentsize >= sizeof(Elf64_Shdr), "ftrace: invalid ELF64 section header size");
//   Assert((size_t)eh->e_shoff + (size_t)eh->e_shnum * eh->e_shentsize <= img_size,
//       "ftrace: ELF64 section header table is out of file range");

//   const uint8_t *sh_base = img + eh->e_shoff;
//   Elf64_Shdr symtab = {0};
//   bool found_symtab = false;

//   for (uint16_t i = 0; i < eh->e_shnum; i++) {
//     const uint8_t *ent = sh_base + (size_t)i * eh->e_shentsize;
//     Elf64_Shdr sh;
//     memcpy(&sh, ent, sizeof(sh));
//     if (sh.sh_type == SHT_SYMTAB) {
//       symtab = sh;
//       found_symtab = true;
//       break;
//     }
//   }

//   Assert(found_symtab, "ftrace: ELF64 has no SHT_SYMTAB");
//   Assert(symtab.sh_link < eh->e_shnum, "ftrace: ELF64 symtab links invalid strtab index");
//   Assert(symtab.sh_entsize >= sizeof(Elf64_Sym), "ftrace: invalid ELF64 symtab entsize");
//   Assert((size_t)symtab.sh_offset + symtab.sh_size <= img_size, "ftrace: ELF64 symtab out of range");

//   const uint8_t *str_ent = sh_base + (size_t)symtab.sh_link * eh->e_shentsize;
//   Elf64_Shdr strtab;
//   memcpy(&strtab, str_ent, sizeof(strtab));
//   Assert((size_t)strtab.sh_offset + strtab.sh_size <= img_size, "ftrace: ELF64 strtab out of range");

//   const char *str_base = (const char *)(img + strtab.sh_offset);
//   const uint8_t *sym_base = img + symtab.sh_offset;
//   size_t sym_nr = symtab.sh_size / symtab.sh_entsize;

//   for (size_t i = 0; i < sym_nr; i++) {
//     const uint8_t *ent = sym_base + i * symtab.sh_entsize;
//     Elf64_Sym sym;
//     memcpy(&sym, ent, sizeof(sym));

//     if (ELF64_ST_TYPE(sym.st_info) != STT_FUNC || sym.st_size == 0 || sym.st_name >= strtab.sh_size) {
//       continue;
//     }

//     const char *name = str_base + sym.st_name;
//     const void *end = memchr(name, '\0', strtab.sh_size - sym.st_name);
//     Assert(end != NULL, "ftrace: ELF64 symbol name is not NUL-terminated");

//     ftrace_push_func(name, sym.st_value, sym.st_size);
//   }
// }

// void init_ftrace(const char *elf_file) {
//   Assert(elf_file != NULL, "ftrace: ELF file path is NULL");

//   ftrace_clear();

//   size_t img_size = 0;
//   uint8_t *img = read_elf_image(elf_file, &img_size);
//   Assert(img_size >= EI_NIDENT, "ftrace: ELF file is too small");

//   Assert(img[EI_MAG0] == ELFMAG0 && img[EI_MAG1] == ELFMAG1 &&
//       img[EI_MAG2] == ELFMAG2 && img[EI_MAG3] == ELFMAG3,
//       "ftrace: bad ELF magic in '%s'", elf_file);
//   Assert(img[EI_DATA] == ELFDATA2LSB, "ftrace: only little-endian ELF is supported");

//   if (img[EI_CLASS] == ELFCLASS32) {
//     Assert(img_size >= sizeof(Elf32_Ehdr), "ftrace: invalid ELF32 header size");
//     const Elf32_Ehdr *eh = (const Elf32_Ehdr *)img;
//     parse_elf32(img, img_size, eh);
//   }
//   else if (img[EI_CLASS] == ELFCLASS64) {
//     Assert(img_size >= sizeof(Elf64_Ehdr), "ftrace: invalid ELF64 header size");
//     const Elf64_Ehdr *eh = (const Elf64_Ehdr *)img;
//     parse_elf64(img, img_size, eh);
//   }
//   else {
//     panic("ftrace: unsupported ELF class %u", img[EI_CLASS]);
//   }

//   Log("ftrace: loaded %zu function symbols from '%s'", g_func_nr, elf_file);
//   free(img);
// }

// const char *ftrace_find_func(uint64_t addr, uint64_t *start_out) {
//   for (size_t i = 0; i < g_func_nr; i++) {
//     uint64_t l = g_funcs[i].start;
//     uint64_t r = g_funcs[i].start + g_funcs[i].size;
//     if (addr >= l && addr < r) {
//       if (start_out != NULL) {
//         *start_out = l;
//       }
//       return g_funcs[i].name;
//     }
//   }
//   if (start_out != NULL) {
//     *start_out = 0;
//   }
//   return "???";
// }

// #else

// void init_ftrace(const char *elf_file) {
//   (void)elf_file;
//   panic("ftrace: init_ftrace is not supported on AM target");
// }

// const char *ftrace_find_func(uint64_t addr, uint64_t *start_out) {
//   (void)addr;
//   if (start_out != NULL) {
//     *start_out = 0;
//   }
//   return "???";
// }

// #endif


#include <elf.h>
#include <stdio.h>

#include <debug.h>

// static Elf32_Ehdr eh32;
// static 

#define MAX_FUNC_NUM 1000

typedef struct {
    char name[128];
    uint32_t start_addr;
    uint32_t end_addr;  // not included
} func_t;

typedef struct {
    int count;
    func_t arr[MAX_FUNC_NUM];
} func_array_t;

func_array_t func_array = {.count = 0};

static void func_array_push(char *str, uint32_t start_addr, uint32_t end_addr) {
    assert(end_addr > start_addr);  // size must be > 0
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

char *func_array_search(uint32_t addr) {
    int count = func_array.count;
    for(int i = 0; i < count; i++) {
        if(addr >= func_array.arr[i].start_addr && addr < func_array.arr[i].end_addr) {
            return func_array.arr[i].name;
        }
    }
    return "???";   // Not found in any function range
}

static void ftrace_load_elf(const char *elf_file) {
    FILE *fp = fopen(elf_file, "rb");
    Assert(fp != NULL, "ftrace: cannot open ELF file '%s'", elf_file);

    Elf32_Ehdr eh32;

    size_t nread = fread(&eh32, 1, sizeof(eh32), fp);
    Assert(nread == sizeof(eh32), "ftrace: short read of ELF32 header from '%s'", elf_file);

    // 校验魔数
    Assert(eh32.e_ident[EI_MAG0] == ELFMAG0 &&
         eh32.e_ident[EI_MAG1] == ELFMAG1 &&
         eh32.e_ident[EI_MAG2] == ELFMAG2 &&
         eh32.e_ident[EI_MAG3] == ELFMAG3,
         "ftrace: bad ELF magic in '%s'", elf_file);

    Elf32_Shdr *sh_table = malloc(eh32.e_shentsize * eh32.e_shnum); // 节头表
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

    char *shstrtab = malloc(shstrtab_entry->sh_size);
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
    char *strtab = malloc(strtab_entry->sh_size);
    assert(strtab);
    nread = fread(strtab, strtab_entry->sh_size, 1, fp);
    Assert(nread == 1, "ftrace: short read of ELF strtab section");

    // Read symtab
    Elf32_Sym *symtab = malloc(symtab_entry->sh_size);
    assert(symtab);
    ret = fseek(fp, symtab_entry->sh_offset, SEEK_SET);
    Assert(ret == 0, "ftrace: fseek to symtab section failed");

    assert(symtab_entry->sh_size % symtab_entry->sh_entsize == 0);
    int symtab_num = symtab_entry->sh_size / symtab_entry->sh_entsize;
    nread = fread(symtab, symtab_entry->sh_entsize, symtab_num, fp);
    Assert(nread == symtab_num, "ftrace: short read of ELF symtab section");

    // Search for FUNC
    for(int i = 0; i < symtab_num; i++) {
        int st_type = ELF32_ST_TYPE(symtab[i].st_info);
        if(st_type == STT_FUNC) {
            char *symbol_name = strtab + symtab[i].st_name;
            uint32_t start_addr = symtab[i].st_value;
            uint32_t end_addr = start_addr + symtab[i].st_size;
            printf("DEBUG: Function '%s' with start_addr 0x%08x and end_addr 0x%08x\n", symbol_name, start_addr, end_addr);
            func_array_push(symbol_name, start_addr, end_addr);
        }
    }

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
