/******************************************************************
 This is an example for the Adafruit RA8875 Driver board for TFT displays
 ---------------> http://www.adafruit.com/products/1590
 The RA8875 is a TFT driver for up to 800x480 dotclock'd displays
 It is tested to work with displays in the Adafruit shop. Other displays
 may need timing adjustments and are not guanteed to work.

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source hardware
 by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries.
 BSD license, check license.txt for more information.
 All text above must be included in any redistribution.
 ******************************************************************/


#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
uint16_t tx, ty;

void setup()
{
  Serial.begin(9600);
  Serial.println("RA8875 start");

  /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_800x480)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }

  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  tft.fillScreen(RA8875_BLACK);

  /* Switch to text mode */
  tft.textMode();
  tft.cursorBlink(32);


  /* Set a solid for + bg color ... */

  /* ... or a fore color plus a transparent background */


  /* Set the cursor location (in pixels) */
  /*tft.textSetCursor(10, 10);*/

  /* Render some text! */
  char welcomeString[12] = "Welcome to ";
  char defconString[10] =  "DEF CON! ";
  /* Change the cursor location and color ... */
  /*tft.textSetCursor(100, 100);*/
  tft.textTransparent(RA8875_RED);
  /* If necessary, enlarge the font */
  /*tft.textEnlarge(1);*/
  /* ... and render some more text! */
  /*tft.textWrite(string);*/
  tft.textSetCursor(150, 150);
  tft.textEnlarge(3);
  tft.textWrite(welcomeString);
  tft.textSetCursor(150, 250);
  tft.textWrite(defconString);

  tft.fillCircle(600, 245, 59, RA8875_YELLOW);
  for (int i = 0; i < 18; i++){
    int x1 = 500;
    int y1 = 250 + i;
    int x2 = 695;
    int y2 = 360 + i;
    tft.drawLine(x1, y1, x2, y2, RA8875_YELLOW);
    int x3 = 695;
    int y3 = 250 + i;
    int x4 = 500;
    int y4 = 360 + i;
    tft.drawLine(x3, y3, x4, y4, RA8875_YELLOW);
  }
  tft.fillCircle(695, 270, 15, RA8875_YELLOW);
  tft.fillCircle(685, 250, 15, RA8875_YELLOW);
  tft.fillCircle(500, 355, 15, RA8875_YELLOW);
  tft.fillCircle(510, 375, 15, RA8875_YELLOW);
  tft.fillCircle(695, 355, 15, RA8875_YELLOW);
  tft.fillCircle(685, 375, 15, RA8875_YELLOW);
  tft.fillCircle(500, 270, 15, RA8875_YELLOW);
  tft.fillCircle(510, 250, 15, RA8875_YELLOW);
  tft.fillCircle(580, 225, 15, RA8875_BLACK);
  tft.fillCircle(620, 225, 15, RA8875_BLACK);
  tft.drawCurve(600, 255, 35, 30, 0, RA8875_BLACK);
  tft.drawCurve(600, 255, 35, 30, 3, RA8875_BLACK);
  tft.drawCurve(600, 256, 35, 30, 0, RA8875_BLACK);
  tft.drawCurve(600, 256, 35, 30, 3, RA8875_BLACK);
  tft.drawCurve(600, 257, 35, 30, 0, RA8875_BLACK);
  tft.drawCurve(600, 257, 35, 30, 3, RA8875_BLACK);
}

void loop()
{
}
