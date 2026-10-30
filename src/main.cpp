// =====================================================================
// Lab 11 – Arrays, Loops and JSON  (STARTER FILE)
// IoT I – Dawson College – Electrical Engineering Technology
//
// Build this program one part at a time, following the lab procedure.
// Each comment below marks where the code from the procedure goes.
// =====================================================================
#include <Arduino.h>
#include <ArduinoJson.h>   // added with lib_deps in platformio.ini

// ----- Pins ----------------------------------------------------------
// Replace each ___ with the GPIO number from the tables in Part II.
#define BUTTON_PIN  32   // push button (to GND)
#define POT_PIN     34   // potentiometer wiper (analog input)
// The four LED pins are stored in an array (Global variables, Part III).

// ----- Global variables ----------------------------------------------
// Part III – LED pins array
// An array holds many values of the same type under ONE name
// (Common Commands: "Declare an Array").
// 1st blank: how many elements?
// Next four blanks: the LED pins from Part II, LED 0 first.
const int LED_PINS[4] = {16, 17, 18, 19};
const int NUM_LEDS = 4;      // the number of elements in LED_PINS
const int STEP_TIME = 200;   // how long each LED stays on (ms)


// Part IV – samples array
// An array of 10 readings. It is empty for now: takeSamples() fills it.
const int NUM_SAMPLES = 10;
int samples[NUM_SAMPLES];


// ----- Helper functions ----------------------------------------------
// Part III – showLevel()
// showLevel() – a bar graph: turn on LEDs 0 to level-1, and turn the others off.
// Example: level = 2  ->  LED 0 and LED 1 on, LED 2 and LED 3 off.
void showLevel(int level)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (i < level)                  // should LED i be part of the bar?
    {
      digitalWrite(LED_PINS[i], HIGH);
    }
    else
    {
      digitalWrite(LED_PINS[i], LOW);
    }
  }
}


// Part IV – takeSamples(), printSamples(), getAverage(),
//           getMinimum(), getMaximum()
// takeSamples() – fill the array: element 0, then element 1, … up to element 9.



// Part V – sendReport()


// Part IV – runMeasurement()


// Part V – handleCommand() and checkSerial()


void setup()
{
  Serial.begin(115200);

  // Inputs and outputs
  // Button: input with the internal pull-up resistor
  // (Common Commands: "Input with Pull-up").
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // ONE for loop sets all four LED pins as outputs (Common Commands: "For Loop").
  // i takes the values 0, 1, 2, 3 – one for each element of the array.
  for (int i = 0; i < 4; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);  // the element number (index) is i
  }

  Serial.println("Lab 11 – Arrays, Loops and JSON");
}

void loop()
{
  // Part III – LED patterns (for loops)
  for (int i = 0; i < NUM_LEDS; i++)
  {
    digitalWrite(LED_PINS[i], HIGH);   // turn LED number i on
    Serial.print("LED ");
    Serial.print(i);
    Serial.print(" is on GPIO ");
    Serial.println(LED_PINS[i]);      // print the pin number stored at index i
    delay(STEP_TIME);
    digitalWrite(LED_PINS[i], LOW);    // turn it off again
  }
  // Visit each LED from the last to the first: start at the LAST index and count DOWN
  // (Common Commands: "Count Down"). What is the index of the last element?
  for (int i = 3; i >= 0; i--)
  {
    digitalWrite(LED_PINS[i], HIGH);
    delay(STEP_TIME);
    digitalWrite(LED_PINS[i], LOW);
  }
  // Show the levels 0, 1, 2, 3 and 4, half a second each.
  for (int level = 4; level <= NUM_LEDS; level++)
  {
    showLevel(level);
    delay(500);
  }

  // Part IV – Wait for the button, then measure (while loops)
  Serial.println("Press the button to measure...");

  // A while loop repeats AS LONG AS its condition is true
  // (Common Commands: "While Loop").
  // A released button reads HIGH, so this loop waits here until the button is pressed.
  while (digitalRead(BUTTON_PIN) == HIGH)
  {
    delay(10);
  }
  delay(50);     // ignore switch bounce (like the debounce in Lab 10)

  Serial.println("Button pressed!");

  // Now wait here until the button is released, so one press = one measurement.
  while (digitalRead(BUTTON_PIN) == LOW)
  {
    delay(10);
  }
  delay(50);     // ignore switch bounce when the button is released


}