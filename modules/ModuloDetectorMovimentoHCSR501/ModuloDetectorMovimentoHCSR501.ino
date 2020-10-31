const int pinoPIR = 3; //PINO DIGITAL UTILIZADO PELO SENSOR DE PRESENÇA
const int pinoLED = 7; //PINO DIGITAL UTILIZADO PELO LED

void setup() {
  // put your setup code here, to run once:
  pinMode(pinoLED, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoPIR, INPUT); //DEFINE O PINO COMO ENTRADA
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(pinoPIR) == HIGH) { //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
    digitalWrite(pinoLED, HIGH); //ACENDE O LED
  } else { //SENÃO, FAZ
    digitalWrite(pinoLED, LOW); //APAGA O LED
  }
}
