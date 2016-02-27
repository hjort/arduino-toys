/*
Note frequencies retrieved from:
http://www.phy.mtu.edu/~suits/notefreqs.html
*/

#define BUTTON1_PIN 3
#define BUTTON2_PIN 4
#define BUTTON3_PIN 5
#define BUTTON4_PIN 6
#define BUTTON5_PIN 7
#define BUTTON6_PIN 8
#define BUZZER_PIN  9

#define FIRST_BUTTON BUTTON1_PIN
#define LAST_BUTTON  BUTTON6_PIN

#define FREQ_C5 523.25
#define FREQ_D5 587.33
#define FREQ_E5 659.25
#define FREQ_F5 698.46
#define FREQ_G5 783.99
#define FREQ_A5 880.00

const float freqs[] = {FREQ_C5, FREQ_D5, FREQ_E5, FREQ_F5, FREQ_G5, FREQ_A5};

void setup()
{
  for (int pin = FIRST_BUTTON; pin <= LAST_BUTTON; pin++)
    pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int button = 0, freq = 0;
  for (int pin = FIRST_BUTTON; pin <= LAST_BUTTON; pin++) {
    if (digitalRead(pin) == HIGH) {
      button = pin - FIRST_BUTTON;
      freq = int(freqs[button]);

      Serial.print("Button ");
      Serial.print(button + 1);
      Serial.print(": ");
      Serial.print(freq);
      Serial.println(" Hz");

      tone(BUZZER_PIN, freq, 100);
    }
  }
  delay(100);
}

