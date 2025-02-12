#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Wire.h>

// Pinout definitions
// VDD = 3.3V
// GND = GND
// SCL = GPIO22
// SDA = GPIO21

#define RES -1
#define SDA 21
#define SCK 22

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, RES);

void setup() {
  Serial.begin(115200);
  Serial.println("OLED");
  Wire.begin(SDA, SCK);

  display.begin(0x3c);
  display.setTextColor(SH110X_WHITE);
  display.clearDisplay();

  displayText();
}

void loop() {
  // counterLoop();
  // scrollText();
  // bounceLoop();
}

void displayText() {
  display.setCursor(10, 10);
  display.println("Hello World!");
  display.display();
}

void counterLoop() {
  static int counter = 0;
  static unsigned long previousMillis = 0;
  const unsigned long interval = 1000;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    updateCounter();
  }
}

void updateCounter() {
  display.fillScreen(SH110X_BLACK);

  display.setCursor(10, 10);
  display.print("Count: ");
  display.print(counter);
  display.display();

  counter++;
}

void scrollText() {
  String message = "Hello, this is a scrolling message!";
  int speed = 2;
  static int x = display.width();
  static unsigned long lastScroll = 0;
  
  if (millis() - lastScroll >= (speed * 10)) {
    display.clearDisplay();
    display.setCursor(x, 32);
    display.print(message);
    display.display();
    
    x--;
    if (x < -(message.length() * 6)) {
      x = display.width();
    }
    lastScroll = millis();
  }
}

void bounceLoop() {
  static float xPos = 64, yPos = 32;
  static float xSpeed = 1.5, ySpeed = 1.2;
  static int rectWidth = 20, rectHeight = 10;
  static unsigned long lastUpdate = 0;
  const unsigned long frameDelay = 16; // ~60 FPS
  
  if(millis() - lastUpdate >= frameDelay) {
    lastUpdate = millis();
    
    updatePosition();
    checkBoundaries();
    drawBounceRect();
  }
}

void updatePosition() {
  xPos += xSpeed;
  yPos += ySpeed;
}

void checkBoundaries() {
  if(xPos <= 0 || xPos >= 128 - rectWidth) {
    xSpeed = -xSpeed;
  }
  
  if(yPos <= 0 || yPos >= 64 - rectHeight) {
    ySpeed = -ySpeed;
  }
}

void drawBounceRect() {
  display.clearDisplay();
  display.fillRect(xPos, yPos, rectWidth, rectHeight, SH110X_WHITE);
  display.display();
}


