// Including necessary libraries
#include <Arduino.h>
#include <U8g2lib.h>

// Configuring Serial Communication Library
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

// Wire.h communicate with devices over the I2C and SPI busses
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, A5, A4, U8X8_PIN_NONE);

// Defining output pins
#define outA 2
#define outB 3

// Declaring variables to hold positions
int lastPosition;
int currentPosition;
int counter = 0;

void setup() {
  // Initiating hte u8g2 interface for OLED display
  u8g2.begin();

  // Define INPUT pins
  pinMode(outA, INPUT);
  pinMode(outB, INPUT);

  // Set the baud rate of the serial monitor 
  Serial.begin(9600);

  // Read the value of A pin of rotary encoder
  int lastPosition = digitalRead(outA);
}

void loop() {
  // Read the value of pin A repeatedly
  currentPosition = digitalRead(outA);
  
  // If the last postion and current position does not match
  // and the pin B also does not match the current position readning
  // Increase the measured angle in clockwise direction
  if(lastPosition != currentPosition){
    if(digitalRead(outB) != currentPosition){
      counter++;
    }
    else{
      // Decrease the counter for anti-clockwise direction
      counter--;
    }
    // Output the values for the serial monitor (as the OLED display is not functioning properly)
    Serial.print("Position: ");
    Serial.print(counter);
    Serial.println();
    delay(100);

    // Clear the buffer of OLED display
    u8g2.clearBuffer();
    // Set the font style of the display
    u8g2.setFont(u8g2_font_ncenB08_tr);
    // Output the string "Position" in first row
    u8g2.drawStr(0,10, "Position");
    // Output the counter value in the next column
    u8g2.drawStr(0,25, counter);
    // Transmit the formatted output to microcontroller
    u8g2.sendBuffer();
    // Delay 100 micro-secinds
    delay(100);
    // Clear the buffer again for the next input
    u8g2.clearBuffer();
  }

  // Assign the value of current position to last position
  lastPosition = currentPosition;
}
