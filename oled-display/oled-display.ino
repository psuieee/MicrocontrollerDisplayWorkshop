#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

// Define OLED dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1   //   QT-PY / XIAO

// Uno R3: SCL(SCK)=D19, SDA=D18
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize the SH1106 OLED display
  display.begin(i2c_Address, true);

  // Clear the display and set up text
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);  // Set text color
  display.setTextSize(1);  // Set text size
  display.setCursor(0, 0);  // Set cursor to the top-left corner
  display.println(F("Hello, World!"));
  display.display();
}

void loop() {
  // Nothing to do here
}


