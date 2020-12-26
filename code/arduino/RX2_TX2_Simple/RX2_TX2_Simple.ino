/**
 * Demo sketch to control the Realtek RX2 (and clones) RC 
 * Controller IC with an Arduino (forward function only)
 *
 * @author Andrew @ Junkbotix, December 24, 2020
 * @source https://github.com/junkbotix
 * @license GPL v3 License
 *   
 * Based on original code by Mircea Diaconescu
 * October 28, 2013 (https://github.com/dimircea/)
 * 
 * Many cheap RC toys are based on TX2/RX2 transmitter/receiver 
 * ICs. This sketch demonstrates how to control the RX2 controller 
 * IC with an Arduino. Only one pin is needed from the Arduino!
 *   
 * Connect pin 10 from the Arduino to the SI pin 3 of the RX2 IC.
 * 
 * If needed, you can redefine the SIGNAL pin to point to any other 
 * free digital pin available on the Arduino.
 *
 * A copy of the Realtek TX2/RX2 datasheet (v1.2) may be found
 * at: https://github.com/junkbotix/toy-rc-car-robot-platform
 */

// Function (W1) and Start (W2) Code Periods (as defined in Realtek 
// datasheet v1.2), values are in microseconds (1000000 uS per Hz)

#define W1_CODE_PERIOD      1000 // f = 1000 Hz, 1 / f * 1000000 = 1000 uS
#define W2_CODE_PERIOD      2000 // f =  500 Hz, 1 / f * 1000000 = 2000 uS

// Alternate period definitions (try these if your chip is unstable)
/*
#define W1_CODE_PERIOD       800 // f = 1250 Hz, 1 / f * 1000000 =  800 uS
#define W2_CODE_PERIOD      1600 // f =  625 Hz, 1 / f * 1000000 = 1600 uS
*/

// W1 Functions (counts defined by the Realtek datasheet v1.2)
#define W1FX_ENDCODE           4
#define W1FX_FORWARD          10
#define W1FX_FORWARD_TURBO    16
#define W1FX_TURBO            22
#define W1FX_FORWARD_LEFT     28
#define W1FX_FORWARD_RIGHT    34
#define W1FX_BACKWARD         40
#define W1FX_BACKWARD_RIGHT   46
#define W1FX_BACKWARD_LEFT    52
#define W1FX_LEFT             58
#define W1FX_RIGHT            64

// Arduino pin to output signal on (input to RX2 SI pin 3)
#define SIGNAL_PIN            10

// Arduino pin to output status indication
#define STATUS_PIN            13

void showStatus() {
  // Toggle the status output pin five (5) times...
  for (int i = 0; i < 5; i++) {
    digitalWrite(STATUS_PIN, HIGH);
    delay(500);
    digitalWrite(STATUS_PIN, LOW);
    delay(1000);
  }

  // ...then leave it HIGH
  digitalWrite(STATUS_PIN, HIGH);
}

void doStartCode() {
  // Define microsecond delay values for HIGH to 
  // LOW signal transition, for a 75% duty cycle
  int delayLow = W2_CODE_PERIOD / 4;
  int delayHigh = delayLow * 3;

  // Send W2 start code sequence (4 x W2)
  for (int i = 0; i < 4; i++) {
    digitalWrite(SIGNAL_PIN, HIGH);
    delayMicroseconds(delayHigh);
    
    digitalWrite(SIGNAL_PIN, LOW);
    delayMicroseconds(delayLow);
  }
}

void doFunctionCode(int num) {
  // Define microsecond delay values for HIGH to 
  // LOW signal transition, for a 50% duty cycle
  int delayMicros = W1_CODE_PERIOD / 2;

  // Send W1 function code sequence (num x W1)
  for (int i = 0; i < num; i++) {
    digitalWrite(SIGNAL_PIN, HIGH);
    delayMicroseconds(delayMicros);
    
    digitalWrite(SIGNAL_PIN, LOW);
    delayMicroseconds(delayMicros);
  }
}

void doFunction(int code) {
  doStartCode();
  doFunctionCode(code);
}

void setup() {
  // Initialize the Arduino signal output pin
  pinMode(SIGNAL_PIN, OUTPUT);

  // Initialize the status output pin
  pinMode(STATUS_PIN, OUTPUT);
  
  // Show that code is initialized
  showStatus();
}

void loop() {
  // Continuously output the "forward" function code signal for testing
  doFunction(W1FX_FORWARD);
}
