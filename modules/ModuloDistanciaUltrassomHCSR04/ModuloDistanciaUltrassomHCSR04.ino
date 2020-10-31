#include "Ultrasonic.h" //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO

const int echoPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)

const int pinoBuzzer = 2; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO
const int pinoLED = 3; //PINO DIGITAL EM QUE O LED ESTÁ CONECTADO

Ultrasonic ultrasonic(trigPin, echoPin); //INICIALIZANDO OS PINOS DO ARDUINO

//int distancia; //VARIÁVEL DO TIPO INTEIRO
//String result; //VARIÁVEL DO TIPO STRING

void setup() {
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  pinMode(pinoBuzzer, OUTPUT); //DECLARA O PINO COMO SENDO SAÍDA
  pinMode(pinoLED, OUTPUT); //DECLARA O PINO COMO SENDO SAÍDA
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
}

void loop() {
  int distancia = obterDistancia(); // FAZ A CHAMADA DO MÉTODO

  Serial.print("Distancia: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(String(distancia)); ////IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  Serial.println(" cm"); //IMPRIME O TEXTO NO MONITOR SERIAL

  // SE A DISTÂNCIA ENTRE O OBJETO E O SENSOR ULTRASONICO FOR MENOR QUE 30CM...
  if (distancia <= 30) {
    tone(pinoBuzzer, 1500); //ACIONA O BUZZER
    digitalWrite(pinoLED, HIGH);

    //SENÃO...
  } else {
    noTone(pinoBuzzer); //BUZZER PERMANECE DESLIGADO
    digitalWrite(pinoLED, LOW);
  }
}

//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
int obterDistancia() {
  digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
  delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
  digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
  delayMicroseconds(10); //INTERVALO DE 10 MICROSSEGUNDOS
  digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE

  //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
  //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA NA VARIAVEL "distancia"
  int distancia = ultrasonic.Ranging(CM); //VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
  delay(500); //INTERVALO DE 500 MILISSEGUNDOS

  return distancia;
}
