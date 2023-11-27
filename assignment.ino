// arduino code to interface LM35 with Arduino and change blink rates according to the temperature

#include <TimerOne.h>

const int tempPin = A0;  // LM35 temperature sensor connected to analog pin A0

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Timer1.initialize(250000);  //temperature is checked every 250 milliseconds
  Timer1.attachInterrupt(checkTemperature);
  Timer1.start();
}

void loop() 
{
}

void checkTemperature() 
{
  int reading = analogRead(tempPin);  // Get the voltage reading from the LM35
  float temperature=reading/2.048;  // Convert the voltage reading into the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C");

  if (temperature < 30.0)    // Check if temperature is less than 30
  {
    blinkLed(250);  // Blink every 250 milliseconds
  } 
  else 
  {
    blinkLed(500);  // Blink every 500 milliseconds
  }
}

void blinkLed(int interval) 
{
  static bool ledState = LOW;
  digitalWrite(LED_BUILTIN, ledState); 
  ledState = !ledState;
  Timer1.initialize(interval * 1000);  // Convert milliseconds to microseconds
}
