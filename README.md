# Eric's ST7735-TFT-Display Code & Projects
<p align="center">
<b>Eric's ST7735-TFT-Display Code & Projects</b><br>
<br>
 <img src="https://github.com/MKme/ST7735-Color-TFT-Display/blob/master/Pics/1.PNG" width="700"/>
 <br>
Eric's ST7735 128X128 SPI Display Code &amp; Projects
1.44" 128x128 Color TFT Display code and my notes
Examples using both the Adafruit Libraries and the Arduino built-in TFT library
Install the Adafruit GFX library and the Adafruit ST7735 library in library manager within the Arduino IDE.
<br>
<br>
🐦 <a href="https://twitter.com/mkmeorg">Twitter</a>
| 📺 <a href="https://www.youtube.com/mkmeorg">YouTube</a>
| 🌍 <a href="http://www.mkme.org">mkme.org</a><br>
Support this project and become a patron on <a href="http://mkme.org/patreon">Eric's Patreon</a>.<br>
Website, Forum and store are at http://mkme.org <br>
Chat with Me: <a href="https://discord.gg/j9S4Fgv">Discord</a></b>
</p>
Support this project and become a patron on <a href="http://mkme.org/patreon">Eric's Patreon</a>.<br>
Website, Forum and store are at http://mkme.org <br>
Chat with Me: <a href="https://discord.gg/j9S4Fgv">Discord</a></b>
</p>

### Overview Video (short):
TBD

### FULL Video Tutorial:
TBD
### BUY THE SUPPLIES HERE:

Buy the display here: https://amzn.to/2NBFCGl

More videos and information at http://youtube.com/mkmeorg or http://www.mkme.org

### Wiring to Arduino Nano
| Pin On LCD | Pin on NANO |
| ---------- |----------------|
| LED  | 3.3 or 5V depending on your display  |
| SCK  | D13 |
| SDA  | D11 (MOSI) |
| A0   | D8 |
| RST  | D9  |
| CS   | D10 |
|GND   | GND |
|VCC  | 3.3 or 5V depending on your display  |


### Useful Commands When Using Adafruit Library

Rotate Display:

tft.setRotation(tft.getRotation()+1);

Fill Screen Black:

tft.fillScreen(ST77XX_BLACK);

Test wrapping on/off:

tft.setTextWrap(false);

Print Text/numbers various colors:
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(ST77XX_BLUE);
  
Draw Lines:

tft.drawLine(tft.width()-1, 0, 0, y, color);

Invert Display colors:

tft.invertDisplay(true);
