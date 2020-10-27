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

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL
}
  
void loop(){
  char tecla_pressionada = meuteclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA
  
  if (tecla_pressionada){ //SE ALGUMA TECLA FOR PRESSIONADA, FAZ
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
  }
}
