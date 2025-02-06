#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "bitmap.h"

// Pin definitions
// ESP32: SCL(SCK)=18, SDA(MOSI)=23, RES(RST)=2, DC=0, CS(SS)=5, BL=Vcc
// Uno R3: SCL(SCK)=13, SDA(COPI)=11, RES(RST)=7, DC=5, CS(SS)=10, BL=Vcc

#define TFT_CS     10  // Chip select
#define TFT_RST    7  // Reset pin
#define TFT_DC     5  // Data/Command pin

// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 160

// Create an instance of the display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

int counter = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 1000;

void setup() {
  tft.initR(INITR_BLACKTAB); // Initialize with the black tab
  tft.fillScreen(ST7735_BLACK); // Fill the screen with black
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);

  // displayText();
  displayImage();

}

void loop() {
  // counterLoop();
  // dvdLoop();

}

void displayText() {
  tft.setCursor(10, 10);
  tft.println("YIPPEEE");
}

void displayImage() {
  tft.drawRGBBitmap(0, 0, psuLogo2, 128, 160);
}

void updateCounter() {
  // Clear the previous counter value by filling the area with black
  tft.fillScreen(ST7735_BLACK);

  // Display the updated counter value
  tft.setCursor(10, 10);
  tft.println("Count:");
  tft.setCursor(10, 60);
  tft.println(counter);

  counter++; // Increment the counter
}

void counterLoop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    updateCounter();
  }
}
