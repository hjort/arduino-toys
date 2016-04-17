/*
 Geiger Proximity: HC-SR04 Sensor + Buzzer
- VCC connection of the sensor attached to +5V
- GND connection of the sensor attached to ground
- TRIG connection of the sensor attached to digital pin 7
- ECHO connection of the sensor attached to digital pin 8
- Buzzer pin connected to digital pin 6
 */

#define BUZZER_PIN 6
#define TRIG_PIN 7
#define ECHO_PIN 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  long duration, distance, sleep;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(ECHO_PIN, HIGH);

  // convert the time into a distance
  distance = ms2cm(duration);
  
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();

  // turn the buzzer on for a duration corresponding to the distance  
  sleep = constrain(distance, 1, 500);
  tone(BUZZER_PIN, 1000);
  delay(25);
  noTone(BUZZER_PIN);
  delay(sleep);
}

long ms2cm(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

