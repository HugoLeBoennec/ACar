// Les bibliothèques

#include <SoftwareSerial.h> 
#include <Wire.h>
#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f
//les sorties
int signalPinAG = 8; // Les différents capteurs
int signalPinAD = 3;
int signalPinAA = 4;
int AG;
int AD;
int AA;
int randomV;
int attente;

void setup() {
  // put your setup code here, to run once:
pinMode(signalPinAG, INPUT);
pinMode(signalPinAD, INPUT);
pinMode(signalPinAA, INPUT);
Serial.begin(9600);
Motor.begin(I2C_ADDRESS);

}

void loop() {
  //initialisation des variables
  if(HIGH == digitalRead(signalPinAA))AA = 1;
  else AA = 0;
  if(HIGH == digitalRead(signalPinAD))AD = 1;
  else AD = 0;
  if(HIGH == digitalRead(signalPinAG))AG = 1;
  else AG = 0;

//si le capteur central est actif
if(AA == 1){
  //si uniqumement le capteur avant est actif avancer
  if (AD == 0 && AG == 0){
    Motor.speed(MOTOR1, 50);
    Motor.speed(MOTOR2, 50);
     Serial.println("avant1");
  // si le capteur droit est actif aller à gauche jusqu'à ce que le capteur central ne soit plus actif puis actif
  }else if(AD == 1 && AG == 0){
    Motor.speed(MOTOR1, 0);
    Motor.speed(MOTOR2, 100);
     Serial.println("gauche1");
    attente = 1;
    while (attente = 1){
      if (AA == 0)attente = 0;
      delay(100);
    }attente = 0;
    while (attente = 1){
      if (AA == 1)attente = 0;
      delay(100);
    }
  // si le capteur gauche est actif, aller à droite jusqu'à ce que le capteur centrale ne soit plus actif puis actif
  }else if (AD == 0 && AG == 1){
    Motor.speed(MOTOR1, 100); // MOTOR1 correspond aux roues gauches du robot
    Motor.speed(MOTOR2, 0);
     Serial.println("droite1");
    while (attente = 1){
      if (AA == 0)attente = 0;
      delay(100);
    }attente = 0;
    while (attente = 1){
      if (AA == 1)attente = 0;
      delay(100);
    }
  // si tous capteurs sont actif, aller à droite / à gauche / tout droit aléotoirement
  }else{
    //remplir
    Motor.speed(MOTOR1, 0);
    Motor.speed(MOTOR2, 100);
     Serial.println("gauche2");
  }
// si le capteur central n'est pas actif
}else{
  // si aucun capteur n'est actif, continuer le mouvement
  if (AD == 0 && AG == 0){

  // si seul le capteur droit est actif, aller à gauche
  }else if(AD == 1 && AG == 0){
    Motor.speed(MOTOR1, 0);
    Motor.speed(MOTOR2, 100);
     Serial.println("gauche3");
  // si seul le capteur gauche est actif, aller à droite
  }else if (AD == 0 && AG == 1){
    Motor.speed(MOTOR1, 100);
    Motor.speed(MOTOR2, 0);
     Serial.println("droite3");
  // si le capteur droite et gauche est actif, aller a droite et a gauche aléatoirement
  }else{
    //remplir
    Motor.speed(MOTOR1, 0);
    Motor.speed(MOTOR2, 100); 
     Serial.println("gauche4");
  }
}
delay(100);
}
