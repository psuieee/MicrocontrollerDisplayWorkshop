#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "bitmap.h"

#define ENABLE_GxEPD2_GFX 0

// Pinout definitions
// VCC = 3.3V
// GND = GND
// SDA(MOSI) = GPIO23
// SCL(SCK) = GPIO18
// CS(SS) = 5
// DC = 0
// RES = 2
// BUSY = 15

#define CS 5
#define DC 0
#define RES 2
#define BUSY 15

GxEPD2_3C<GxEPD2_213_Z98c, GxEPD2_213_Z98c::HEIGHT> display(GxEPD2_213_Z98c(CS, DC, RES, BUSY));


void setup()
{
  display.init(115200, true, 50, false);

  nameTag();
  // displayImage();
  display.hibernate();
}

void displayImage() {
  int imgWidth = 250;
  int imgHeight = 122;
  int x = 0;
  int y = 0;

  display.setRotation(1);
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawBitmap(x, y, psuLogo, imgWidth, imgHeight, GxEPD_BLACK);
  } while (display.nextPage());
}

void nameTag()
{
  const char name[] PROGMEM = "John Doe";
  const char major[] PROGMEM = "Electrical Engineering";
  display.setRotation(1);
  display.setFont(&FreeMonoBold12pt7b);
  display.setTextColor(GxEPD_BLACK);
  
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(name, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y-tbh);
    display.print(name);
    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
    display.getTextBounds(major, 0, 0, &tbx, &tby, &tbw, &tbh);
    x = ((display.width() - tbw) / 2) - tbx;
    display.setCursor(x, y+tbh);
    display.print(major);
  }
  while (display.nextPage());
}
void loop() {
  // N/A
}