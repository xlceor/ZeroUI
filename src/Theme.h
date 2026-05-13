#ifndef THEME_H
#define THEME_H

#include <stdint.h>

struct Theme {
  uint16_t background;
  uint16_t primary;
  uint16_t dim;
  uint16_t accent;
  uint16_t text;
  uint16_t border;
  uint8_t  textSize;
};

extern const Theme RetroTerminal;

#endif
