// ========================================================================
// ESP32+TTGO Dice
// ========================================================================


#include <TFT_eSPI.h>        // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();   // Invoke library


const int buttonPin0 = 0;
const int buttonPin1 = 35;

const int centerX = 67;
const int centerY0 = 60;
const int centerY1 = 180;
const int dieEdge = 96;
const int dotRadius = 10;
const int dotEdge = 28;

int buttonState0 = 0;
bool buttonHeldDown0 = false;

void setup()
{
  pinMode (buttonPin0, INPUT);
  pinMode (buttonPin1, INPUT);
  
  // Initialize display, paint screen navy blue.
  tft.begin ();
  tft.fillScreen (TFT_NAVY);

  // Initial draw of dice.
  drawDie (random (6), centerX, centerY0, TFT_BLACK);
  drawDie (random (6), centerX, centerY1, TFT_BLACK);
}

void loop()
{
  if (digitalRead (buttonPin0) == LOW) {
    drawDie (random (6), centerX, centerY0, TFT_LIGHTGREY);
    drawDie (random (6), centerX, centerY1, TFT_LIGHTGREY);
    buttonHeldDown0 = true;
  } else {
    if (buttonHeldDown0) {
      drawDie (random (6), centerX, centerY0, TFT_BLACK);
      drawDie (random (6), centerX, centerY1, TFT_BLACK);      
    }
    buttonHeldDown0 = false;
  }
}

void drawDie (int roll, int x, int y, uint16_t color)
{
  tft.fillRoundRect (x - (dieEdge / 2), y - (dieEdge / 2), dieEdge, dieEdge, 12, TFT_WHITE);
  
  switch (roll) {
      case 0:
      drawOne (x, y, color);
      break;
      
      case 1:
      drawTwo (x, y, color);
      break;
      
      case 2:
      drawThree (x, y, color);
      break;
      
      case 3:
      drawFour (x, y, color);
      break;
      
      case 4:
      drawFive (x, y, color);
      break;
      
      default:
      drawSix (x, y, color);
      break;      
    }
}

void drawOne (int x, int y, uint16_t color)
{
  tft.fillCircle (x, y, dotRadius, color);
}

void drawTwo (int x, int y, uint16_t color)
{
  tft.fillCircle (x - dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x + dotEdge, y + dotEdge, dotRadius, color);
}

void drawThree (int x, int y, uint16_t color)
{
  tft.fillCircle (x- dotEdge, y- dotEdge, dotRadius, color);
  tft.fillCircle (x, y, dotRadius, color);
  tft.fillCircle (x + dotEdge, y + dotEdge, dotRadius, color);
}

void drawFour (int x, int y, uint16_t color)
{
  tft.fillCircle (x - dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x - dotEdge, y + dotEdge, dotRadius, color);
  tft.fillCircle (x + dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x + dotEdge, y + dotEdge, dotRadius, color);
}

void drawFive (int x, int y, uint16_t color)
{
  tft.fillCircle (x - dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x - dotEdge, y + dotEdge, dotRadius, color);
  tft.fillCircle (x, y, dotRadius, color);
  tft.fillCircle (x + dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x + dotEdge, y + dotEdge, dotRadius, color);
}

void drawSix (int x, int y, uint16_t color)
{
  tft.fillCircle (x - dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x - dotEdge, y, dotRadius, color);
  tft.fillCircle (x - dotEdge, y + dotEdge, dotRadius, color);
  tft.fillCircle (x + dotEdge, y - dotEdge, dotRadius, color);
  tft.fillCircle (x + dotEdge, y, dotRadius, color);
  tft.fillCircle (x + dotEdge, y + dotEdge, dotRadius, color);
}
