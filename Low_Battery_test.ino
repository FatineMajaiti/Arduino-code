#include <SimpleTimer.h>

// Warn the user when battery voltage is low
// Using a buzzer
// with Voltage Divider (2x 10K resistor)

// the timer object
SimpleTimer timer;

const int sensorPin = A0; //voltage will be read from A0 analog pin
const int BuzzerPin = 4; 
const float voltageThreshold = 6.00; //This is the amount from which we start to warn
const int buzzInterval = 1000 * 4; // amount of time between buzz, in ms

int intervalId = -1;

float getVoltage() {
  int sensorValue = analogRead(sensorPin); // read the A0 pin value
  return sensorValue * (5.00 / 1023.00) * 2; // convert the value to a true voltage since analog input goes from 0 - 1023
}

void turnOffBuzzer() {
  digitalWrite(BuzzerPin, LOW); //Set buzzer low (turn off)
}

void turnOnBuzzer() {
  digitalWrite(BuzzerPin, HIGH); //method to turn buzzer on
}

void BuzzOnce() {
  turnOnBuzzer();
  timer.setTimeout(50, turnOnBuzzer);
}

void startBuzzing() {
  intervalId = timer.setInterval(buzzInterval, BuzzOnce);
}

void stopBuzzing() {
  timer.deleteTimer(intervalId);
  intervalId = -1;
  turnOffBuzzer();
}

void setup() {
  pinMode(BuzzerPin, OUTPUT);
  turnOffBuzzer();
}

void checkVoltage() { 
  float voltage = getVoltage();
  if (voltage < voltageThreshold) {
    // check if already buzzing
    if (intervalId < 0) {
      startBuzzing();
    }
  } else {
    // check if already buzzing
    if (intervalId >= 0) {
      stopBuzzing();
    }
  }
}
void loop() {
  checkVoltage();
  timer.run();
}


