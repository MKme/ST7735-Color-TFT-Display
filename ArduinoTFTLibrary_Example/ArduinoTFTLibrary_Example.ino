/*
 128x128 TFT screen that uses the ST7735 chip.

 Using only Arduino TFT built in Library
  * Pins
 * LED 3.3 or 5V depending on your display
 * SCK D13
 * SDA D11(MOSI)
 * A0 D8
 * RST D9
 * CS D10
 * GND GND
 * VCC 3.3 or 5V depending on your display
 * 
 * Derived from code here: https://mithatkonar.com/wiki/doku.php/arduino/displays_for_classic_arduinos/1.8_and_1.44_tft_displays_and_classic_arduinos
 */
 
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
const unsigned int CLOCK_PIN = 13,
                   DATA_PIN = 11,
                   CS_PIN = 10,
                   DC_PIN = 8,
                   RESET_PIN = 9;
 
const unsigned int LEFT_MARGIN = 10; // number of pixels you need to shift down for 128x128 screen
 
 
TFT TFTscreen = TFT(CS_PIN, DC_PIN, RESET_PIN);
char dispStr[4];    // null terminated char array used to pass to TFT.text()
unsigned int counter = 80;
 
void setup() {
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);    // clear the screen
 
  TFTscreen.stroke(255, 255, 255);  // set font color
  TFTscreen.setTextSize(1);         // set font size
  TFTscreen.text("TFT library", LEFT_MARGIN, 4); //<----------------------Eric added vertical offset of 4 for his junk screens
 
  TFTscreen.setTextSize(7);
}
 
void loop() {
  // 
  TFTscreen.stroke(0, 0, 0);    // background color
  String(counter).toCharArray(dispStr, 4);
  TFTscreen.text(dispStr, LEFT_MARGIN, 40);  
 
  counter++;
 
  TFTscreen.stroke(255, 255, 255);  // font color
  String(counter).toCharArray(dispStr, 4);
  TFTscreen.text(dispStr, LEFT_MARGIN, 40);
  delay(50);
}
