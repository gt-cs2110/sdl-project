#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

#define WIDTH 640
#define HEIGHT 480

int main(void) {
    if (graphics_setup(WIDTH, HEIGHT) < 0) {
        return 1;
    }

    uint32_t pixels[WIDTH*HEIGHT];
    uint32_t off = 0;
    for (int i = 0; i < HEIGHT*2; i++) {
        for (int row = 0; row < HEIGHT; row++) {
            uint32_t actual_row = (row + off) % HEIGHT;
            uint32_t color = (uint32_t)((double)row/HEIGHT*0xff) << 16 | 0x00ffffUL;
            for (int col = 0; col < WIDTH; col++) {
                pixels[actual_row*WIDTH + col] = color;
            }
        }
        graphics_render(pixels);
        off = (off + 1) % HEIGHT;
        graphics_delay(1);
    }

    graphics_teardown();
    return 0;
}
