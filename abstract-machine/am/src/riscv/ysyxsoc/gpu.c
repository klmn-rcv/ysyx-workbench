#include <am.h>

#define VGA_BASE  0x21000000L
#define VGA_WIDTH 640
#define VGA_HEIGHT 480

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = VGA_WIDTH, .height = VGA_HEIGHT,
    .vmemsz = VGA_WIDTH * VGA_HEIGHT * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  volatile uint32_t *fb = (volatile uint32_t *)(uintptr_t)VGA_BASE;
  uint32_t *pixels = ctl->pixels;
  int start = ctl->y * VGA_WIDTH + ctl->x;
  for(int i = 0; i < ctl->h; i++) {
    for(int j = 0; j < ctl->w; j++) {
      fb[start + i * VGA_WIDTH + j] = pixels[i * ctl->w + j];
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}