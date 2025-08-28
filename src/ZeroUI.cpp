#include "ZeroUI.h"
#include "screens.h" // Aquí llama a sus drawX()

ZeroUI_Class ZeroUI;

void ZeroUI_Class::begin(TFT_eSPI &display) {
  tft = &display;
  tft->fillScreen(BACKGROUND_COLOR);
}

void ZeroUI_Class::touch(int tx, int ty) {
  for (auto &b : buttons) if (b.isTouched(tx, ty)) b.onPress();
  for (auto &s : sliders) if (s.isTouched(tx, ty)) s.update(tx);
  for (auto &sw : switches) if (sw.isTouched(tx, ty)) sw.toggle();
}

void ZeroUI_Class::update() {

}
static ScreenChangeCallback _screenCallback = nullptr;

void ZeroUI_Class::onScreenChange(ScreenChangeCallback cb) {
  _screenCallback = cb;
}

void ZeroUI_Class::goTo(int screenID) {
  if (_screenCallback)
    _screenCallback(screenID);
}