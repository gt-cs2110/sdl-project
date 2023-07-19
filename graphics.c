#include <SDL.h>
#include "graphics.h"

static uint32_t pixelbuf_width;
static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture;

static void sdl_err(const char *message) {
    fprintf(stderr, "%s: %s\n", message, SDL_GetError());
}

int graphics_setup(int width, int height) {
    pixelbuf_width = width;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        sdl_err("SDL initialization error");
        return 1;
    }
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window, &renderer) < 0) {
        sdl_err("Could not create SDL window and renderer");
        return -1;
    }
    if (!(texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, width, height))) {
        sdl_err("Could not create SDL video buffer");
        return -1;
    }

    return 0;
}

int graphics_get_keypress(void) {
    SDL_Event event;
    if (SDL_PollEvent(&event)
            && event.type == SDL_KEYUP
            // Don't send them back 0 until we've processed all events
            && event.key.keysym.sym != SDLK_UNKNOWN) {
        return event.key.keysym.sym;
    } else {
        // Sentinel value meaning no keypress
        return '\0';
    }
}

int graphics_render(uint32_t *pixels) {
    if (SDL_UpdateTexture(texture, NULL, pixels, pixelbuf_width*sizeof (uint32_t)) < 0
        || SDL_RenderClear(renderer) < 0
        || SDL_RenderCopy(renderer, texture, NULL, NULL) < 0) {
        sdl_err("Could not render frame");
        return -1;
    }
    SDL_RenderPresent(renderer);
    return 0;
}

void graphics_delay(uint32_t milliseconds) {
    SDL_Delay(milliseconds);
}

void graphics_teardown(void) {
    static int toredown_already = 0;

    if (!toredown_already) {
        if (window)
            SDL_DestroyWindow(window);
        if (renderer)
            SDL_DestroyRenderer(renderer);
        if (texture)
            SDL_DestroyTexture(texture);
        SDL_Quit();
        toredown_already = 1;
    }
}
