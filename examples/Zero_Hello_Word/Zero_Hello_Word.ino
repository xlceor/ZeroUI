#include <ZeroUI.h>

TFT_eSPI tft = TFT_eSPI();
XPT2046_Touchscreen ts(7); // CS pin

Screen* mainScreen;
Button* helloBtn;
Label* welcomeLbl;

void sayHello(int state) {
  Serial.println("¡Hola desde ZeroUI!");
}

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3);

  SPIClass touchSPI(FSPI);
  touchSPI.begin(36, 37, 35);
  ts.begin(touchSPI);
  ts.setRotation(3);

  ZeroUI::begin(tft, ts);

  mainScreen = new Screen(tft, TFT_BLACK);
  // Crear y añadir el Label de bienvenida antes del botón
  welcomeLbl = new Label(tft, 20, 20, 280, 30, TFT_BLACK, TFT_DARKGREY, TFT_YELLOW, "Bienvenido a ZeroUI");
  welcomeLbl->setTextSize(3);
  mainScreen->addComponent(welcomeLbl);

  // Crear el botón con estilos personalizados
  helloBtn = new Button(tft, 40, 80, 160, 50, TFT_BLUE, TFT_WHITE, TFT_WHITE, "Púlsame");
  helloBtn->setTextSize(2);
  helloBtn->setEvent(sayHello);
  mainScreen->addComponent(helloBtn);

  ZeroUI::setScreen(mainScreen);
}

void loop() {
  ZeroUI::loop();
}