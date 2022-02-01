//programação criada por Sarah Ramos para controle de um volante caseiro para jogar jogos de corrida//
//Reels no instagram:<https://www.instagram.com/reel/CU8syO4Aved/>


#include <Keyboard.h> //biblioteca que controla o Teclado

const int buttonPin2 = 9;          // Define o pino 9  o botão
int previousButtonState2 = LOW; 
const int buttonPin = 8;          // Define o pino 4 para o botão
int previousButtonState = HIGH; 

void setup() {
   pinMode(A0, INPUT); //DEFINE O PINO COMO ENTRADA
   pinMode(buttonPin, INPUT); //DEFINE O PINO COMO ENTRADA
   pinMode(buttonPin2, INPUT); //DEFINE O PINO COMO ENTRADA

//  Keyboard.begin(); // incia controle do teclado
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int buttonState2 = digitalRead(buttonPin2);
  int estadoPot = map(analogRead(A0), 0, 1023, 0, 100);

 Serial.println(buttonState2 );
 Serial.println(buttonState );
 Serial.println(estadoPot);
  delay(500);
  if(estadoPot > 60)
  {
    Keyboard.press ('a'); 
  }else{
    Keyboard.release ('a');
  }
  if(estadoPot < 30)
  {//
    Keyboard.press ('d'); 
  }else{
    Keyboard.release ('d');
  }
    if((buttonState == 1) && (buttonState != previousButtonState)) //se o botão 1 for pressionado pressione a tecla W
  {
    Keyboard.press ('w');//
  }else{
    Keyboard.release ('w');//
  }
  if ((buttonState2 == 1 ) && (buttonState2 != previousButtonState2))//se o botão 2 for pressionado pressione a tecla S
  {//
    Keyboard.press ('s'); 
  }else{
    Keyboard.release ('s');
  }
    previousButtonState = buttonState;
    previousButtonState2 = buttonState2;
}
