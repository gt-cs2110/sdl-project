#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

extern int graphics_setup(int width, int height);
extern int graphics_render(uint32_t *pixels);
extern void graphics_delay(uint32_t milliseconds);
extern void graphics_teardown(void);

#endif // GRAPHICS_H
