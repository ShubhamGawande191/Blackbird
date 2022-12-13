/**
  Basic NTC Thermistor demo
  https://wokwi.com/arduino/projects/299330254810382858

  Assumes a 10K@25℃ NTC thermistor connected in series with a 10K resistor.

  Copyright (C) 2021, Uri Shaked
*/

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
int green = 6; // green led
int red = 7; // red led
int yellow = 5; // yellow led

void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");
  delay(1000);
  // Green light if temperature below 30℃
  if (celsius < 30) {
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(5, HIGH);
  }
  // Yellow light if temperature between 30℃ & 80℃
  else if (celsius > 30 && celsius < 80){
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(5, LOW);
  }
  // Red light if temperature above 80℃
  else{
    digitalWrite(7, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  }
}
