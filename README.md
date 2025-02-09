# MicrocontrollerDisplayWorkshop

Workshop 2 of Spring 2025.

## Requirements

This workshop requires the Arduino IDE. Download here: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

## Arduino IDE Setup

Install the NodeMCU ESP32 Board:
1. File -> Preferences -> Additional boards manager URLs: paste `https://dl.espressif.com/dl/package_esp32_index.json`
2. Tools -> Board -> Boards Manager...: Search `esp32` by Espressif and install

Install the following libraries:
 - Adafruit_GFX (graphics library)
 - Adafruit_ST7735 (blue lcd)
 - Adafruit_ILI9341 (red lcd)
 - Adafruit_SH110X (oled)
 - GxEPD2 (e-ink)

## Additonal Resources

Adafruit GFX Library Documentation: [https://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x.html](https://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x.html)

Arduino Uno R3 Pinout: [https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf)

NodeMCU ESP32 Pinout: [https://mischianti.org/esp32-nodemcu-32s-esp-32s-kit-high-resolution-pinout-datasheet-and-specs/](https://mischianti.org/esp32-nodemcu-32s-esp-32s-kit-high-resolution-pinout-datasheet-and-specs/)

E-ink Display Documentation: [https://github.com/WeActStudio/WeActStudio.EpaperModule/](https://github.com/WeActStudio/WeActStudio.EpaperModule/)

image2cpp: [https://javl.github.io/image2cpp/](https://javl.github.io/image2cpp/)
