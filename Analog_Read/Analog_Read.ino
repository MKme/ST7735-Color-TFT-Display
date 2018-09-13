/***************************************************
Simple Bar Graph for the 128x128 color SPI display

Code adapted from here: http://henrysbench.capnfatz.com/henrys-bench/arduino-adafruit-gfx-library-user-guide/arduino-adafruit-gfx-bar-graph/

This is a work in progress but hopefully it will help someone else by providing
a base to start and work from.

Please check out my Youtube videos here and consider a thumbs up if this helped you!
Youtube : http://www.youtube.com/mkmeorg
 
 
 * Pins
 * LED 3.3 or 5V depending on your display
 * SCK D13
 * SDA D11(MOSI)
 * A0 D8
 * RST D9
 * CS D10
 * GND GND
 * VCC 3.3 or 5V depending on your display
 
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

#define BACKCOLOR 0x18E3
#define BARCOLOR 0x0620
#define SCALECOLOR 0xFFFF
//Analog Measurement Declarations
const int analogIn = A0;
int RawValue = 0;
int LastPercent = 0;

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

  tft.fillScreen(BACKCOLOR);
  

 
// tft.setRotation(tft.getRotation()+1);

  
}

void loop() {  
  tft.fillScreen(ST77XX_BLACK);
//tft.setTextWrap(false);
  tft.setCursor(0,30);
  tft.setTextColor(ST77XX_RED);
  tft.println(" Analog Pin 0");
  //tft.println ("");
  int sensorValue = analogRead(A0);
  tft.setTextSize(2);     // set text sizebigger
  tft.setTextColor(ST77XX_GREEN);
  tft.println(sensorValue);//print the pin value driectly
  tft.setTextSize(1); //set text size back smaller
  tft.println("Raw Value"); 
  
  
  delay(0);
}

