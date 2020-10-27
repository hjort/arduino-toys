#include <Keypad.h> //INCLUSÃO DE BIBLIOTECA https://blogmasterwalkershop.com.br/arquivos/libs/keypad.zip

const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
const byte qtdColunas = 3; //QUANTIDADE DE COLUNAS DO TECLADO

//CONSTRUÇÃO DA MATRIZ DE CARACTERES
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte PinosqtdLinhas[qtdLinhas] = {3, 4, 5, 6}; //PINOS UTILIZADOS PELAS LINHAS
byte PinosqtdColunas[qtdColunas] = {8, 9, 10}; //PINOS UTILIZADOS PELAS COLUNAS

//INICIALIZAÇÃO DO TECLADO
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas); 

byte PINO_LED_VERDE = 2;
byte PINO_LED_VERMELHO = 7;

const int DIGITOS_SENHA = 3;
const char* SENHA_CORRETA = "123";

byte ordemDigito = 0;
char senhaDigitada[DIGITOS_SENHA+1];

void setup() {
  pinMode(PINO_LED_VERDE, OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  digitalWrite(PINO_LED_VERDE, LOW);
  digitalWrite(PINO_LED_VERMELHO, LOW);
  
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL
}

void reinicializarSenha() {
  ordemDigito = 0;
  //strcpy(senhaDigitada, "");
  memset(senhaDigitada, 0, DIGITOS_SENHA + 1);
}

void loop() {
  char tecla = meuteclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA

  if (!tecla) {
    return;
  }
  
  if (tecla) { //SE ALGUMA TECLA FOR PRESSIONADA, FAZ
    Serial.print("Tecla pressionada: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
  }
  
  /*
  if (tecla == '*') {
    digitalWrite(PINO_LED_VERDE, HIGH);
    delay(2000);
    digitalWrite(PINO_LED_VERDE, LOW);
  } else if (tecla == '#') {
    digitalWrite(PINO_LED_VERMELHO, HIGH);
    delay(2000);
    digitalWrite(PINO_LED_VERMELHO, LOW);
  }
  */
  
  if (tecla == '*') {
    reinicializarSenha();
    
  } else if (tecla == '#') {

    Serial.print("senhaDigitada: ");
    Serial.println(senhaDigitada);
    
    if (!strcmp(senhaDigitada, SENHA_CORRETA)) {
      digitalWrite(PINO_LED_VERDE, HIGH);
      delay(2000);
      digitalWrite(PINO_LED_VERDE, LOW);
    } else {
      digitalWrite(PINO_LED_VERMELHO, HIGH);
      delay(2000);
      digitalWrite(PINO_LED_VERMELHO, LOW);
    }

    reinicializarSenha();
    
  } else {
    if (ordemDigito < DIGITOS_SENHA) {
      senhaDigitada[ordemDigito] = tecla;
    }
    ordemDigito++;
  }

  //Serial.print("senhaDigitada: ");
  //Serial.println(senhaDigitada);
  
  //Serial.print("ordemDigito: ");
  //Serial.println(ordemDigito);
}
