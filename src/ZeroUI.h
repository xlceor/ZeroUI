#ifndef ZERO_UI_H
#define ZERO_UI_H

#include <TFT_eSPI.h>
#include <vector>
#include "components/Button.h"
#include "components/Slider.h"
#include "components/Switch.h"
#include "components/Label.h"
#include "style.h"


typedef void (*ScreenChangeCallback)(int screenID);

class ZeroUI_Class {
public:
  void begin(TFT_eSPI &tft);
  void touch(int x, int y);
  void update(); 
  void onScreenChange(ScreenChangeCallback cb);
  void goTo(int screenID);

  std::vector<Button> buttons;
  std::vector<Slider> sliders;
  std::vector<ToggleSwitch> switches;
  std::vector<Label> labels;

  TFT_eSPI* tft;
  
};

extern ZeroUI_Class ZeroUI;

#endif