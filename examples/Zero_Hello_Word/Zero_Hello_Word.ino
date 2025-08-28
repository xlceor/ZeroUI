#include <TFT_eSPI.h>
#include <ZeroUI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1);
  ZeroUI.begin(tft);
}

void hello() {
    Label lbl();
    lbl.setColor(0xFF0000);
    lbl.setTextSize(2);
    lbl.setText("Hello World");

}

void loop() {

}