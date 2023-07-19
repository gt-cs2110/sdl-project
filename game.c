#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

// TODO: remove me
#include <SDL.h>

#define WIDTH 640
#define HEIGHT 480

int main(void) {
    if (graphics_setup(WIDTH, HEIGHT) < 0) {
        return 1;
    }

    int quit = 0;
    uint32_t pixels[WIDTH*HEIGHT];
    uint32_t off = 0;
    int color_idx = 2;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    color_idx = (color_idx + 1) % 3;
                } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = 1;
                }
            }
        }

        for (int row = 0; row < HEIGHT; row++) {
            uint32_t actual_row = (row + off) % HEIGHT;
            uint32_t color = (uint32_t)((double)row/HEIGHT*0xff) << (8*color_idx) | (0xffffffUL & ~(0xffUL << (8*color_idx)));
            for (int col = 0; col < WIDTH; col++) {
                pixels[actual_row*WIDTH + col] = color;
            }
        }
        if (graphics_render(pixels) < 0) {
            return 1;
        }
        off = (off + 1) % HEIGHT;
        graphics_delay(1);
    }

    graphics_teardown();
    return 0;
}
