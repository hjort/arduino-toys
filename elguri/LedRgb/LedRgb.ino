const int azul = 6;
const int verde = 5;
const int vermelho = 3;

String cor;

void setup()
{
   Serial.begin(9600);
  
   pinMode(azul, OUTPUT);
   pinMode(verde, OUTPUT);
   pinMode(vermelho, OUTPUT);
}

//Funções responsáveis por executar o brilho selecionado
void vermelhoFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}
void azulFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}
void verdeFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}
void amareloFuncao(){
  analogWrite(azul, 66);
  analogWrite(verde, 255);
  analogWrite(vermelho, 242); 
}
void roxoFuncao(){
  analogWrite(azul, 255);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}
void laranjaFuncao(){
  analogWrite(azul, 7);
  analogWrite(verde, 178);
  analogWrite(vermelho, 245);
}
void brancoFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}

/*
void loop()
{
  if(Serial.available()){
    cor = Serial.readString();
    Serial.println(cor);
  }

  if(cor == "red"){
    vermelhoFuncao();
  }
  if(cor == "blue"){
    azulFuncao();
  }
  if(cor == "green"){
    verdeFuncao();
  }
  if(cor == "yellow"){
    amareloFuncao();
  }
  if(cor == "purple"){
    roxoFuncao();
  }
  if(cor == "orange"){
    laranjaFuncao();
  }
  if(cor == "white"){
    brancoFuncao();
  }
}
*/

void loop()
{
  vermelhoFuncao();
  delay(50);
  laranjaFuncao();
  delay(50);
  amareloFuncao();
  delay(50);
  verdeFuncao();
  delay(50);
  azulFuncao();
  delay(50);
  roxoFuncao();
  delay(50);
  brancoFuncao();
  delay(50);
}

