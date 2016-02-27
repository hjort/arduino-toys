// RGB LED Adjusted by Potentiometer

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int potPin = 2; // select the input pin for the potentiometer

unsigned int potValue, lastValue; // 16-bit (0..16535)
byte red, green, blue, alpha; // 8-bit (0..255)

void setup() {
  Serial.begin(9600);
}

void loop() {

  // read the value from the pot (10 bits => 0 to 1023)
  potValue = analogRead(potPin);
  
  if (lastValue == potValue)
    return;
  else
    lastValue = potValue;
  
  // 16-bit placement:
  // ------ARRRGGGBBB
  
  alpha = (potValue >> 9);                  // 0..1
  red   = ((potValue << 7) >> 9) << alpha;  // 0..255
  green = ((potValue << 10) >> 9) << alpha; // 0..255
  blue  = ((potValue << 13) >> 9) << alpha; // 0..255
  
  Serial.print("potValue = ");
  Serial.print(potValue);
  Serial.print(", R = ");
  Serial.print(red);
  Serial.print(", G = ");
  Serial.print(green);
  Serial.print(", B = ");
  Serial.print(blue);
  Serial.print(", A = ");
  Serial.println(alpha);
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  delay(100);
}

