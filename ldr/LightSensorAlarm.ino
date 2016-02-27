// Alarm triggered by Light Sensor (LDR)

const byte LDR_PIN = 0;    // LDR on Analog Pin 0
const byte BUZZER_PIN = 2; // Buzzer on Pin 8
const byte LED_PINS[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Array for LED pins

const byte QTY_LEDS = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

const int THRESHOLD = 700; // threshold for the alarm (# of photons)
const int CYCLES = 20;     // number of cycles
const int RESTART_DELAY = 5000;

int ldrValue = 0; // Value read from the LDR

unsigned long changeTime;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  for (int i = 0; i < QTY_LEDS; i++)
    pinMode(LED_PINS[i], OUTPUT);

  changeTime = millis();

//  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(LDR_PIN); // read the value from the LDR
  
//  Serial.print("ldrValue = ");
//  Serial.println(ldrValue);
  
  if (ldrValue <= THRESHOLD) {
    if ((millis() - changeTime) > RESTART_DELAY) {
      alarm(CYCLES);
      changeTime = millis();
    }
  }
}

void alarm(int times) {
  
  float sinVal;
  int toneVal;
  byte currentLED = 0;
  byte direction = 1;

  digitalWrite(LED_PINS[currentLED], HIGH); // turn on the first LED
  
  for (int t = 0; t < times; t++) {
    for (int x = 0; x < 180; x++) {

      // generate a frequency from the sin value
      sinVal = sin(x * (3.1412 / 180));
      toneVal = 2000 + (int(sinVal * 1000));
      tone(BUZZER_PIN, toneVal);
      delay(2);
      
      if (x % 10 == 0) {
        digitalWrite(LED_PINS[currentLED], LOW); // turn off the current LED
        currentLED += direction; // increment by the direction value
        digitalWrite(LED_PINS[currentLED], HIGH); // turn on the current LED
        if (currentLED > QTY_LEDS)
          direction *= -1;
      }
    }
  }
  
  // silence everything in the end 
  digitalWrite(LED_PINS[currentLED], LOW); // turn off the current LED
  noTone(BUZZER_PIN); // stop the tone
}

