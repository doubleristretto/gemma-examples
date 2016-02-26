#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1
#define NUM_OF_PIXELS 4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_OF_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  chase(pixels.Color(255, 0, 0)); // Red
  chase(pixels.Color(0, 255, 0)); // Green
  chase(pixels.Color(0, 0, 255)); // Blue
}
 
static void chase(uint32_t color) {
  
  for (uint16_t i=0; i < pixels.numPixels()+4; i++) {
      pixels.setPixelColor(i, color); // Draw new pixel
      pixels.setPixelColor(i-4, 0); // Erase pixel a few steps back
      pixels.show();
      delay(100);
  }
}
