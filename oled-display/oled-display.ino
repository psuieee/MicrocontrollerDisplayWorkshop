#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Wire.h>

// Pinout definitions
// GND = GND
// VCC = 3.3V
// SCL = GPIO22
// SDA = GPIO21

#define RES -1

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, RES); // 128x64

// Global variables
int count = 0;
unsigned long previousMillis = 0;
int x = 0;
unsigned long lastScroll = 0;
float xPos = 64.0, yPos = 32.0;
float xSpeed = 1.5, ySpeed = 1.2;
int rectWidth = 20, rectHeight = 10;
unsigned long lastUpdate = 0;

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
  // Try out these functions!
  // counter();
  // scrollText();
  // bounce();
}

void displayText() {
  display.setCursor(10, 10);
  display.println("Hello World!");
  display.display();
}

void counter() {
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
  display.print(count);
  display.display();
  count++;
}

void scrollText() {
  String message = "Hello, this is a scrolling message!";
  int speed = 2;
  
  static int x = display.width();
  static unsigned long lastScroll = 0;
  display.setTextWrap(false);
  
  if (millis() - lastScroll >= (speed * 10)) {
    display.clearDisplay();
    
    int posY = 32;
    display.setCursor(x, posY);
    display.print(message);
    display.display();
    
    int16_t bx, by;
    uint16_t textWidth, textHeight;
    display.getTextBounds(message, x, posY, &bx, &by, &textWidth, &textHeight);
    
    x--;
    if (x < -((int)textWidth)) {
      x = display.width();
    }
    
    lastScroll = millis();
  }
}


void bounce() {
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
