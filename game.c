#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

#define WIDTH 640
#define HEIGHT 480

struct game_state {
    int quit;
    int color_idx;
    uint32_t row_off;
};

int main(void) {
    if (graphics_setup(WIDTH, HEIGHT) < 0) {
        return 1;
    }

    struct game_state state = {
        .quit = 0,
        .color_idx = 2,
        .row_off = 0,
    };

    while (!state.quit) {
        int key;
        while ((key = graphics_get_keypress())) {
            switch (key) {
            case ' ':
                state.color_idx = (state.color_idx + 1) % 3;
                break;
            case 'q':
            case ASCII_ESC:
                state.quit = 1;
                break;
            }
        }

        uint32_t pixels[WIDTH*HEIGHT];
        for (int row = 0; row < HEIGHT; row++) {
            uint32_t actual_row = (row + state.row_off) % HEIGHT;
            uint32_t color = (uint32_t)((double)row/HEIGHT*0xff) << (8*state.color_idx) | (0xffffffUL & ~(0xffUL << (8*state.color_idx)));
            for (int col = 0; col < WIDTH; col++) {
                pixels[actual_row*WIDTH + col] = color;
            }
        }
        if (graphics_render(pixels) < 0) {
            return 1;
        }

        state.row_off = (state.row_off + 1) % HEIGHT;
        graphics_delay(1);
    }

    graphics_teardown();
    return 0;
}
