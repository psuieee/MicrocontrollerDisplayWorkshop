# MicrocontrollerDisplayWorkshop

Workshop 2 of Spring 2025.

## Requirements

This workshop requires the Arduino IDE. Download here: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

## Arduino IDE Setup

Install and setup the ESP32 Board:
1. File -> Preferences -> Additional boards manager URLs: paste `https://dl.espressif.com/dl/package_esp32_index.json`
2. Tools -> Board -> Boards Manager...: Search `esp32` by Espressif and install
3. Click "select other board and port" from the board dropdown in the top left, then select "DOIT ESP32 DEVKIT V1" and your respective port, then press "OK"

Install the following libraries from library manager (Tools -> Manage Libraries...). Click "install all" when prompted:
 - Adafruit GFX Library by Adafruit
 - Adafruit ST7735 and ST7789 Library by Adafruit
 - Adafruit SH110X by Adafruit 
 - GxEPD2 by Jean-Marc Zingg

## Additonal Resources

Adafruit GFX Library Documentation: [https://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x.html](https://adafruit.github.io/Adafruit-GFX-Library/html/class_adafruit___g_f_x.html)

LCD Display Driver Documentation: [https://github.com/adafruit/Adafruit-ST7735-Library](https://github.com/adafruit/Adafruit-ST7735-Library)

OLED Display Driver Documentation: [https://github.com/adafruit/Adafruit_SH110x](https://github.com/adafruit/Adafruit_SH110x)

E-ink Display Driver Documentation: [https://github.com/WeActStudio/WeActStudio.EpaperModule/](https://github.com/WeActStudio/WeActStudio.EpaperModule/)

image2cpp: [https://javl.github.io/image2cpp/](https://javl.github.io/image2cpp/)

If having difficulties connecting your board, try installing these drivers: [https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers)
