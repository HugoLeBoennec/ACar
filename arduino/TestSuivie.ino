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


    
  if(HIGH == digitalRead(signalPinAA)){
  Dir = 3;
  }


  if(HIGH == digitalRead(signalPinAD)){
  Dir = 2;
  }
  
  if(HIGH == digitalRead(signalPinAG)){
  Dir = 1;
  }

  if(HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAA) && HIGH != digitalRead(signalPinAD)){
  //-|
  Dir = random(3);
  
  }
  if(HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAD) && HIGH != digitalRead(signalPinAA)){
  //--
  Dir = random(3);
  }
  if(HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAD) && HIGH != digitalRead(signalPinAG)){
  //|-
  Dir = random(3);
  }
  if(HIGH == digitalRead(signalPinAG) && HIGH == digitalRead(signalPinAA) && HIGH == digitalRead(signalPinAG)){
  //-|-
  Dir = random(3);
  }
    
switch (Dir) {
  case 1 :
      Motor.speed(MOTOR1, -50);
      Motor.speed(MOTOR2, 70);
      Serial.println("Gauche");

  break;

  case 2 :
      Motor.speed(MOTOR1, 70);
      Motor.speed(MOTOR2, -50);
      Serial.println("Droite");
  break;

  case 3 :
      Motor.speed(MOTOR1, 20);
      Motor.speed(MOTOR2, 20);
      Serial.println("Avant");

  break;
}
}
