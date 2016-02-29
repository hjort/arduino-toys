#define LATCH_PIN   8 // Pin connected to Pin 12 of 74HC595 (Latch)
#define CLOCK_PIN  12 // Pin connected to Pin 11 of 74HC595 (Clock)
#define DATA_PIN   11 // Pin connected to Pin 14 of 74HC595 (Data)
#define BUZZER_PIN 13 // pin connected to buzzer

// LED digit patterns, from 0 to 9
// This is for common cathode displays.
// For common anode displays, simply switch 1's and 0's.
// 1 = LED on, 0 = LED off, in this order in the IC: 15,1,2,3,4,5,6,7
const byte SEVEN_SEG_DIGITS[10] = {
  B01111110, // = 0
  B00110000, // = 1
  B01101101, // = 2
  B01111001, // = 3
  B00110011, // = 4
  B01011011, // = 5
  B01011111, // = 6
  B01110000, // = 7
  B01111111, // = 8
  B01110011  // = 9
};

void setup() {
  //set pins to output
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN,  OUTPUT);
}

void loop() {
  for (byte segs, count = 10; count > 0; count--) {
    segs = SEVEN_SEG_DIGITS[count - 1];

    if (count % 2 == 0)
      segs |= B10000000;

    // set LATCH_PIN low to allow data flow
    digitalWrite(LATCH_PIN, LOW);

    // shift out the bits
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, segs);
    
    // set LATCH_PIN to high to lock and send data
    digitalWrite(LATCH_PIN, HIGH);

    tone(BUZZER_PIN, 880, 200);
    
    delay(1000);
  }
  delay(4000);
}

