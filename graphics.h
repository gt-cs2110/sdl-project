#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

extern int graphics_setup(int width, int height);
extern int graphics_get_keypress(void);
extern int graphics_render(uint32_t *pixels);
extern void graphics_delay(uint32_t milliseconds);
extern void graphics_teardown(void);

// Generated with the following cursed bash one-liner:
//     gunzip -c /usr/share/man/man7/ascii.7.gz | awk '$1~/0[0-3][0-7]/{printf "#define ASCII_%-3s '\''\\x%02x'\''\n", $4, $2}'
// Based on https://stackoverflow.com/a/72003072/321301
#define ASCII_NUL '\x00'
#define ASCII_SOH '\x01'
#define ASCII_STX '\x02'
#define ASCII_ETX '\x03'
#define ASCII_EOT '\x04'
#define ASCII_ENQ '\x05'
#define ASCII_ACK '\x06'
#define ASCII_BEL '\x07'
#define ASCII_BS  '\x08'
#define ASCII_HT  '\x09'
#define ASCII_LF  '\x0a'
#define ASCII_VT  '\x0b'
#define ASCII_FF  '\x0c'
#define ASCII_CR  '\x0d'
#define ASCII_SO  '\x0e'
#define ASCII_SI  '\x0f'
#define ASCII_DLE '\x10'
#define ASCII_DC1 '\x11'
#define ASCII_DC2 '\x12'
#define ASCII_DC3 '\x13'
#define ASCII_DC4 '\x14'
#define ASCII_NAK '\x15'
#define ASCII_SYN '\x16'
#define ASCII_ETB '\x17'
#define ASCII_CAN '\x18'
#define ASCII_EM  '\x19'
#define ASCII_SUB '\x1a'
#define ASCII_ESC '\x1b'
#define ASCII_FS  '\x1c'
#define ASCII_GS  '\x1d'
#define ASCII_RS  '\x1e'
#define ASCII_US  '\x1f'

#endif // GRAPHICS_H
