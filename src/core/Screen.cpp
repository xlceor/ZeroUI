// Screen.cpp
#include "Screen.h"
#include <TFT_eSPI.h>

Screen::Screen(TFT_eSPI& main_tft, uint16_t backgroundColor)
: tft(main_tft), bgColor(backgroundColor){} 

void Screen::addComponent(Component* comp) {
  components.push_back(comp);
}

void Screen::draw() {
  tft.fillScreen(bgColor);

  for (Component* comp : components) {
    comp->Draw();
  }
}

void Screen::handleTouch(int x, int y) {
    for (Component* comp : components) {
        comp->CheckTouch(x, y);
    }
}