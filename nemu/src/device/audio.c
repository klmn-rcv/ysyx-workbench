/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include <device/map.h>
#include <memory/paddr.h>
#include <SDL2/SDL.h>
#include <string.h>

enum {
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  reg_gbuf_start,  // 用户程序buf起始地址，注意不是流缓冲区的起始地址！
  reg_gbuf_end,    // 用户程序buf结束地址
  reg_submit,      // __am_audio_play通过写入reg_submit寄存器来触发audio_enqueue，原子地将音频数据从用户程序buf复制到音频设备的流缓冲区中
  nr_reg
};

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static void audio_callback(void *userdata, uint8_t *stream, int len) {
  uint32_t count = audio_base[reg_count];
  uint32_t nread = count < (uint32_t)len ? count : (uint32_t)len;

  if (nread > 0) {
    memcpy(stream, sbuf, nread);
    memmove(sbuf, sbuf + nread, count - nread);
  }
  if (nread < (uint32_t)len) {
    memset(stream + nread, 0, len - nread);
  }
  audio_base[reg_count] = count - nread;
}

static void audio_init_device() {
  SDL_AudioSpec s = {};
  s.format = AUDIO_S16SYS;
  s.userdata = NULL;

  s.freq = audio_base[reg_freq];
  s.channels = audio_base[reg_channels];
  s.samples = audio_base[reg_samples];
  s.size = audio_base[reg_sbuf_size];
  s.callback = audio_callback;

  SDL_InitSubSystem(SDL_INIT_AUDIO);
  SDL_OpenAudio(&s, NULL);
  SDL_PauseAudio(0);
}

static void audio_enqueue(paddr_t start, paddr_t end) {
  Assert(end >= start, "invalid audio buffer range");
  uint32_t len = end - start;

  SDL_LockAudio();

  uint32_t count = audio_base[reg_count];
  Assert(count + len <= CONFIG_SB_SIZE, "audio stream buffer overflow");
  memcpy(sbuf + count, guest_to_host(start), len);  // 将音频数据从用户程序buf复制到音频设备的流缓冲区中，start是用户程序buf起始地址，这是客户机地址，需要通过guest_to_host转换成宿主机地址才能访问
  audio_base[reg_count] = count + len;

  SDL_UnlockAudio();
}

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  assert(offset % sizeof(uint32_t) == 0);
  assert(len == 4);
  uint32_t reg = offset / sizeof(uint32_t);

  if (reg == reg_init && is_write && audio_base[reg_init]) {  // 写入init寄存器之后才调用该回调函数，检查此时init寄存器的值（也就是刚才写入的值）是否为0，不为0才初始化音频设备
    audio_init_device();
    audio_base[reg_init] = 0;
    return;
  }

  if (reg == reg_sbuf_size && !is_write) {  // 读取sbuf_size寄存器之前就会调用该回调函数，保证每次读sbuf_size之前都先把它置为CONFIG_SB_SIZE
    audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  }

  if (reg == reg_submit && is_write && audio_base[reg_submit]) { // IOE中的__am_audio_play函数通过写入reg_submit寄存器来触发audio_enqueue，原子地将音频数据从用户程序buf复制到音频设备的流缓冲区中。原本复制音频这一步就在__am_audio_play中，但会有并发一致性问题，所以改成了现在这样
    audio_enqueue(audio_base[reg_gbuf_start], audio_base[reg_gbuf_end]);
    audio_base[reg_submit] = 0;
  }
}

void init_audio() {
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
  memset(audio_base, 0, space_size);
  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  memset(sbuf, 0, CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}
