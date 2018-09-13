/***************************************************
 * ERICS NOTE!!!!!!!!!!!
 * I have not finished this nor does it work.  
 * Bars are off screen and plot is screwy
 * I hate it right now so I'm done
 * 
 * 
 * 
 * 
 * 
 * 
 *  
 * tutorial
 * https://learn.adafruit.com/adafruit-1-44-color-tft-with-micro-sd-socket/wiring-and-test
 * GFX Tutorial: https://learn.adafruit.com/adafruit-gfx-graphics-library
 * 
 * Pins
 * LED 3.3 or 5V depending on your display
 * SCK D13
 * SDA D11(MOSI)
 * A0 D8
 * RST D9
 * CS D10
 * GND GND
 * VCC 3.3 or 5V depending on your display
  This is a library for the Adafruit 1.8" SPI display.

This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
The 1.8" TFT shield
  ----> https://www.adafruit.com/product/802
The 1.44" TFT breakout
  ----> https://www.adafruit.com/product/2088
as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>


// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS     10
#define TFT_RST    9  // you can also connect this to the Arduino reset
                       // in which case, set this #define pin to -1!
#define TFT_DC     8

// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)

// For 1.44" and 1.8" TFT with ST7735 use
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);  //<---------------------Eric Says Use This!

// For 1.54" TFT with ST7789
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS,  TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
//#define TFT_SCLK 13   // set these to be whatever pins you like!
//#define TFT_MOSI 11   // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int channelAI = A0;      // probe
int delayAI = A1;       // delay potentiometer
float delayVariable =5; // 10 seems good for decent update- bit fast
float scale = 0;
int xCounter = 0;
int yPosition = 0;
int readings[85];
int counter = 0;


void setup(void) {
  Serial.begin(9600);
  Serial.print("Hello! ST77xx TFT Test");

  // Use this initializer if you're using a 1.8" TFT
  //tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  // Use this initializer (uncomment) if you're using a 1.44" TFT
  tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab  //<----------------------Must Change Examples to this! 

  // Use this initializer (uncomment) if you're using a 0.96" 180x60 TFT
  //tft.initR(INITR_MINI160x80);   // initialize a ST7735S chip, mini display

  // Use this initializer (uncomment) if you're using a 1.54" 240x240 TFT
  //tft.init(240, 240);   // initialize a ST7789 chip, 240x240 pixels

  tft.fillScreen(ST77XX_BLACK);


 

  // large block of text
  tft.fillScreen(ST77XX_BLACK);

  
// draw a single pixel
  tft.drawPixel(10, 10, ST77XX_GREEN);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  
  delay(2000);
 

tft.setRotation(tft.getRotation()+1);

  
}

void loop() {
  //display.setTextColor(WHITE);  
//delayVariable = analogRead(delayAI);
  //delayVariable = (delayVariable/10);
  scale = 47.0/1023.0; 
  // commented out above delay items as no pot/encoder installed yet
  
  
  //record readings
  for(xCounter = 0; xCounter < 85; xCounter += 1)
    {                                 
      yPosition = analogRead(channelAI);
      readings[xCounter] = (yPosition*scale);
      delay (delayVariable);
    }
  
 tft.fillScreen(ST77XX_BLACK);

  //Draw Voltage Ref Lines
  tft.drawLine( 10, 0, 10, 47, ST77XX_GREEN);
  tft.drawLine( 5, 47-(.166 *1023.0 * scale), 10, 47-(.166 *1023.0 * scale), ST77XX_GREEN);
  tft.drawLine( 0, 47-(.33 *1023.0 * scale), 10, 47-(.33 *1023.0 * scale), ST77XX_GREEN);
  tft.drawLine( 5, 47-(.5 *1023.0 * scale), 10, 47-(.5 *1023.0 * scale), ST77XX_GREEN);
  tft.drawLine( 0, 47-(.66 *1023.0 * scale), 10, 47-(.66 *1023.0 * scale), ST77XX_GREEN);
  tft.drawLine( 5, 47-(.84 *1023.0 * scale), 10, 47-(.84 *1023.0 * scale), ST77XX_GREEN);

  for(xCounter = 0; xCounter < 100; xCounter += 1)
    {
       tft.drawPixel(xCounter, 47-readings[xCounter], ST77XX_GREEN);
       if(xCounter>1){
         tft.drawLine(xCounter-1, 47-readings[xCounter-1], xCounter, 47-readings[xCounter], ST77XX_GREEN);
           
       }
    }
  
  //tft.fillScreen(ST77XX_BLACK);     
} 
