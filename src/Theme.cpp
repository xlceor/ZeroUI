#include "Theme.h"
#include <TFT_eSPI.h>

const Theme RetroTerminal = {
  TFT_BLACK,    // background
  TFT_GREEN,    // primary    - main interactive color
  0x0400,       // dim        - low-luminance for inactive surfaces
  TFT_YELLOW,   // accent     - highlights and warnings
  TFT_GREEN,    // text       - foreground text
  0x0320,       // border     - mid-dim green outline
  2             // textSize
};
