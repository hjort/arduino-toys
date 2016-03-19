/*
 Sound detection sensor to turn a LED on
 (Based on Analog input, analog output, serial output)
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * Sound detection sensor module to analog pin 0.
   OUT pin of the module goes to the analog pin.
   Other pins of the module go to +5V (VCC) and ground (GND).
 * LED connected from digital pin 9 to ground.
 */

const int analogInPin = A0; // Analog input pin that the module is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // read the analog in value
  int sensorValue = analogRead(analogInPin);

  // map it to the range of the analog out, decrease a bit and constrain the value
  int outputValue = constrain(255 - map(sensorValue, 0, 1023, 0, 255) - 5, 0, 255);

  // change the analog out value
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading
  delay(10);
}
