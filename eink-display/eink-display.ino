
// base class GxEPD2_GFX can be used to pass references or pointers to the display instance as parameter, uses ~1.2k more code
// enable or disable GxEPD2_GFX base class
#define ENABLE_GxEPD2_GFX 0

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
#include "bitmap.h"

// ESP32 CS(SS)=5, SCL(SCK)=18, SDA(MOSI)=23, BUSY=15, RES(RST)=2, DC=0
// Uno R3 CS(SS)=10, SCL(SCK)=13, SDA(COPI)=11, BUSY=9, RES(RST)=7, DC=5
#define CS 10
#define BUSY 9
#define RES 7
#define DC 5

#define MAX_HEIGHT_3C 128
#define MAX_HEIGHT_BW 61
#define MAX_DISPLAY_BUFFER_SIZE 2048


// GxEPD2_3C<GxEPD2_213_Z98c, GxEPD2_213_Z98c::HEIGHT> display(GxEPD2_213_Z98c(CS, DC, RES, BUSY));
GxEPD2_BW<GxEPD2_213_BN, MAX_HEIGHT_BW> display(GxEPD2_213_BN(CS, DC, RES, BUSY));


void setup()
{
  SPI.begin();
  display.init(115200,true,50,false);

  Serial.begin(9600);
  Serial.print("Width: ");
  Serial.println(display.width());
  Serial.print("Length: ");
  Serial.println(display.height());

  displayText();
  // displayImage();
  display.hibernate();
}

const char HelloWorld[] PROGMEM = "Thomas Montemayor";
const char text[] PROGMEM = "IEEE Projects";

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

void displayText()
{
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  // center the text
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y-tbh);
    display.print(HelloWorld);
    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(display.epd2.hasColor ? GxEPD_RED : GxEPD_BLACK);
    display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
    x = ((display.width() - tbw) / 2) - tbx;
    display.setCursor(x, y+tbh);
    display.print(text);
  }
  while (display.nextPage());
}
void loop() {
  // N/A
}