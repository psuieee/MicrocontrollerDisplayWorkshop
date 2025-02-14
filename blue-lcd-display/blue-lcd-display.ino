#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "bitmap.h"

// Pin definitions:
// GND = GND
// VCC = 3.3-5V
// SCL(SCK) = GPIO18
// SDA(MOSI) = GPIO23
// RES(RST) = 3.3V
// DC = GPIO4
// CS(SS) = GPIO5
// BL = 3.3V

#define CS 5
#define DC 4
#define RES -1

Adafruit_ST7735 tft = Adafruit_ST7735(CS, DC, RES); // 128x160

void setup() {
  Serial.begin(115200);
  Serial.println("Blue LCD");

  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);

  // Try out these functions!
  displayText();
  // displayImage();
  // weAre();
}

void loop() {
  // N/A
}

void displayText() {
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(1);
  tft.setCursor(10, 10);
  tft.println("Hello World!");
}

void displayImage() {
  tft.drawRGBBitmap(0, 0, psuLogo, 128, 160);
}

void weAre() {
  const String text = "We Are!";
  int16_t x1, y1;
  uint16_t w, h;
  
  tft.setTextSize(2);
  tft.getTextBounds(text, 0, 0, &x1, &y1, &w, &h); // get width and height for centering text
  int x = (tft.width() - w) / 2;
  int y = 10;
  
  tft.setCursor(x, y);
  tft.setTextColor(ST7735_BLUE);
  tft.print(text);
}
