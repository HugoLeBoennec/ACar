#include <SoftwareSerial.h>
#include <Wire.h>
#include "Grove_I2C_Motor_Driver.h"

int signalPinAG = 8; // Les différents capteurs
int signalPinAD = 3;
int signalPinAA = 4;

int AA = 0;
int AG = 0;
int AD = 0;
int Dir = 0;
int Solution = 0;
int reflex = 0;
#define I2C_ADDRESS 0x0f
void setup() {
  // put your setup code here, to run once:
  pinMode(signalPinAG, INPUT);
  pinMode(signalPinAG, INPUT);
  pinMode(signalPinAA, INPUT);
  Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
}

void loop() {

 /* if(HIGH == digitalRead(signalPinAA)){ 
  Dir = 3;
  }

  if(HIGH == digitalRead(signalPinAD)){
  Dir = 2;
  }
  
  if(HIGH == digitalRead(signalPinAG)){
  Dir = 1;
  }*/

  
 if((HIGH == digitalRead(signalPinAA) && HIGH != digitalRead(signalPinAG) && HIGH != digitalRead(signalPinAD)) || (HIGH != digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG) && HIGH != digitalRead(signalPinAD)) || (HIGH != digitalRead(signalPinAA) && HIGH != digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD))){
  
  Serial.println("Virage");
  if(HIGH == digitalRead(signalPinAA)){ 
  Dir = 3;
  }

  if(HIGH == digitalRead(signalPinAD)){
  Dir = 2;
  }
  
  if(HIGH == digitalRead(signalPinAG)){
  Dir = 1;
  }
 }

 
 if((HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG) && HIGH != digitalRead(signalPinAD)) || (HIGH != digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD)) || (HIGH == digitalRead(signalPinAA) && HIGH != digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD))){
  
  Serial.println("Croisement en T");
  if(HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG) && HIGH != digitalRead(signalPinAD)){
  Serial.println("-|");
  Solution = random(1,2);
  if(Solution == 2){ 
  Dir = 3;
  }
  
  if(Solution == 1){
  Dir = 1;
  }
 }

 if (HIGH != digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD)){
   Serial.println("--");
  Solution = random(1,2);
  if(Solution == 2){
  Dir = 2;
  }
  
  if(Solution == 1){
  Dir = 1;
  }
 }
 if (HIGH == digitalRead(signalPinAA) && HIGH != digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD)){
  Serial.println("|-");
  Solution = random(1,2);
  if(Solution == 1){ 
  Dir = 3;
  }

  if(Solution == 2){
  Dir = 2;
  }
}

}

 if(HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD)){
  // croissement en X
  Serial.println("Croissement en X");
  reflex = random(3);
  if(reflex == 3){ 
  Dir = 3;
  }

  if(reflex == 2){
  Dir = 2;
  }
  
  if(reflex == 1){
  Dir = 1;
  }
}
 
  /*if(HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAA) && HIGH != digitalRead(signalPinAD)){
  //-|

  
  }
  if(HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD) && HIGH != digitalRead(signalPinAA)){
  //--

  }
  if(HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAD) && HIGH != digitalRead(signalPinAG)){
  //|-

  }
  if(HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG)){
  //-|-
  
  }*/
    
switch (Dir) {
  case 1 :
      Motor.speed(MOTOR1, -40);
      Motor.speed(MOTOR2, 60);
      Serial.println("Gauche");

  break;

  case 2 :
      Motor.speed(MOTOR1, 60);
      Motor.speed(MOTOR2, -40);
      Serial.println("Droite");
  break;

  case 3 :
      Motor.speed(MOTOR1, 20);
      Motor.speed(MOTOR2, 20);
      Serial.println("Avant");

  break;
}
}
