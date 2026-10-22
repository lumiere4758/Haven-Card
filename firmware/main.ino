#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Custom PCB Pin Assignments for RP2350A
#define OLED_CLK    2  // GPIO 2 (Pin 4 on schematic)
#define OLED_MOSI   3  // GPIO 3 (Pin 5 on schematic)
#define OLED_CS     5  // GPIO 5 (Pin 8 on schematic)
#define OLED_RESET  6  // GPIO 6 (Pin 9 on schematic)
#define OLED_DC     7  // GPIO 7 (Pin 10 on schematic)

// Initialize SSD1306 using hardware SPI
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // Explicitly assign custom SPI pins for the RP2350A chip
  SPI.setSCK(OLED_CLK);
  SPI.setTX(OLED_MOSI);

  // Initialize display and check for wiring/power issues
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    while(true); // Halt if OLED fails to respond
  }

  // Clear buffer
  display.clearDisplay();

  // Draw 'WELCOME' text onto the buffer
  display.setTextSize(2);              // Font scaling (try 1 or 3 if preferred)
  display.setTextColor(SSD1306_WHITE); // Pixel color
  display.setCursor(16, 24);           // Center alignment offset
  display.println(F("WELCOME"));       // Target string

  // Push buffer contents to the screen
  display.display();
}

void loop() {
  // Nothing required here for a static display message
}