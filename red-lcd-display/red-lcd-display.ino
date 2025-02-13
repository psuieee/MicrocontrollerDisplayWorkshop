#include "Adafruit_GFX.h"
#include "Adafruit_ST7789.h"
#include "bitmap.h"

// Pin definitions:
// VCC = 3.3-5V
// GND = GND
// CS(SS) = GPIO5
// RES = 3.3V
// DC = GPIO0
// SDI(MOSI) = GPIO23
// SCK(SCL) = GPIO18
// LED = 3.3V
// other pins can be ignored

#define CS 5
#define DC 0
#define RES -1

Adafruit_ST7789 tft = Adafruit_ST7789(CS, DC, RES); // 240x320

void setup(void) {
  Serial.begin(115200);
  Serial.println("Red LCD");

  tft.init(240, 320);
  tft.invertDisplay(false);
  tft.fillScreen(ST77XX_BLACK);

  // Try out these functions!
  displayText();
  // displayImage();
  // weAre();
}

void loop() {
  // N/A
}

void displayText() {
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Hello World!");
}

void displayImage() {
  tft.drawRGBBitmap(0, 0, psuLogo, 240, 320);
}

void weAre() {
  const String text = "We Are!";
  int16_t x1, y1;
  uint16_t w, h;
  
  tft.setTextSize(3);
  tft.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  int x = (tft.width() - w) / 2;
  int y = 260;
  
  tft.setCursor(x, y);
  tft.setTextColor(ST77XX_BLUE);
  tft.print(text);
}
