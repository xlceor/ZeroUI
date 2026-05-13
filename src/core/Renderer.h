#ifndef RENDERER_H
#define RENDERER_H

#include <TFT_eSPI.h>

class Renderer {
public:
  TFT_eSPI& tft; 

  Renderer(TFT_eSPI& display) : tft(display) {}

  void fillRect(int x, int y, int w, int h, uint16_t color) {
    tft.fillRect(x, y, w, h, color);
  }

  void drawRect(int x, int y, int w, int h, uint16_t color) {
    tft.drawRect(x, y, w, h, color);
  }

  void drawText(const char* text, int x, int y, uint16_t color, int size, uint8_t datum = TL_DATUM) {
    tft.setTextColor(color);
    tft.setTextSize(size);
    tft.setTextDatum(datum);
    tft.drawString(text, x, y);
  }

  // - dirty rectangles
  // - sprites (double buffer)
  // - batching SPI
};

#endif