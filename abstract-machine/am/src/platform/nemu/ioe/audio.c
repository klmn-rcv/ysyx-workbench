#include <am.h>
#include <nemu.h>

#define AUDIO_FREQ_ADDR      (AUDIO_ADDR + 0x00)
#define AUDIO_CHANNELS_ADDR  (AUDIO_ADDR + 0x04)
#define AUDIO_SAMPLES_ADDR   (AUDIO_ADDR + 0x08)
#define AUDIO_SBUF_SIZE_ADDR (AUDIO_ADDR + 0x0c)
#define AUDIO_INIT_ADDR      (AUDIO_ADDR + 0x10)
#define AUDIO_COUNT_ADDR     (AUDIO_ADDR + 0x14)
#define AUDIO_BUF_START_ADDR (AUDIO_ADDR + 0x18)
#define AUDIO_BUF_END_ADDR   (AUDIO_ADDR + 0x1c)
#define AUDIO_SUBMIT_ADDR    (AUDIO_ADDR + 0x20)

void __am_audio_init() {
}

void __am_audio_config(AM_AUDIO_CONFIG_T *cfg) {
  cfg->present = true;
  cfg->bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
}

void __am_audio_ctrl(AM_AUDIO_CTRL_T *ctrl) {
  outl(AUDIO_FREQ_ADDR, ctrl->freq);
  outl(AUDIO_CHANNELS_ADDR, ctrl->channels);
  outl(AUDIO_SAMPLES_ADDR, ctrl->samples);
  outl(AUDIO_INIT_ADDR, 1);   // 写入reg_init寄存器来触发audio_init_device，初始化音频设备
}

void __am_audio_status(AM_AUDIO_STATUS_T *stat) {
  stat->count = inl(AUDIO_COUNT_ADDR);
}

void __am_audio_play(AM_AUDIO_PLAY_T *ctl) {
  int len = ctl->buf.end - ctl->buf.start;
  if (len <= 0) return;

  int bufsize = inl(AUDIO_SBUF_SIZE_ADDR);
  while (len > bufsize - (int)inl(AUDIO_COUNT_ADDR));

  outl(AUDIO_BUF_START_ADDR, (uintptr_t)ctl->buf.start);
  outl(AUDIO_BUF_END_ADDR, (uintptr_t)ctl->buf.end);
  outl(AUDIO_SUBMIT_ADDR, 1);  // 写入reg_submit寄存器来触发audio_enqueue，原子地将音频数据从用户程序buf复制到音频设备的流缓冲区中
}
