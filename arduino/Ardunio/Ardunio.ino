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


int xAcar = 1;
int yAcar = 0 ;
int xDestination = 3;
int yDestination = 3;
int Direction = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(signalPinAG, INPUT);
  pinMode(signalPinAD, INPUT);
  pinMode(signalPinAA, INPUT);
  Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);
}
void Avancer() {
  Motor.speed(MOTOR1, 30);
  Motor.speed(MOTOR2, 30);
}
void TurnRight() {
  if (HIGH == digitalRead(signalPinAD)) {
    Motor.speed(MOTOR1, 50);
    Motor.speed(MOTOR2, 20);
    while (HIGH != digitalRead(signalPinAA)) delay(100);
  } else if (HIGH == digitalRead(signalPinAG)) {
    Motor.speed(MOTOR1, 20);
    Motor.speed(MOTOR2, 50);
    while (HIGH != digitalRead(signalPinAA)) delay(100);
  }
}
void TurnLeft() {
  if (HIGH == digitalRead(signalPinAG)) {
    Motor.speed(MOTOR1, 20);
    Motor.speed(MOTOR2, 50);
    while (HIGH != digitalRead(signalPinAA)) delay(100);
  } else if (HIGH == digitalRead(signalPinAD)) {
    Motor.speed(MOTOR1, 50);
    Motor.speed(MOTOR2, 20);
    while (HIGH != digitalRead(signalPinAA)) delay(100);
  }
}

void ChoixDirection() {


  // Vers le Nord
  if (Direction == 1) {
    // si l'objectif est a gauche
    if (xAcar > xDestination) {
      // se déplacer à gauche
      TurnLeft();
      Direction = 4;
      if (xAcar == 3 && yAcar == 2) xAcar -= 3;
      else xAcar -= 1;
      // si l'objectif est a droite
    } else if (xAcar < xDestination) {
      //se déplacer à droite
      TurnRight();
      Direction = 3;
      if (xAcar == 2 && yAcar == 0)xAcar += 2;
      else if (xAcar == 1 && yAcar == 3)xAcar += 2;
      else xAcar += 1;
      // si l'objectif est au meme niveau
    } else {
      // si l'objectif est au meme niveau
      if (yAcar == yDestination); //arrivé
        // si l'objectif est derrierre
        else TurnLeft();   // aller a gauche sinon aller a droite
    }


    // Ver le Sud
  } else if ( Direction == 2) {
    //si l'objectif est a droite
    if (xAcar > xDestination) {
      // se déplacer à droite
      TurnRight();
      Direction = 4;
      if (xAcar == 3 && yAcar == 2)xAcar -= 3;
      else if (xAcar == 4 && yAcar == 4)xAcar -= 3;
      else if (xAcar == 3 && yAcar == 3)xAcar -= 2;
      else xAcar -= 1;
      // si l'objectif est a gauche
    } else if (xAcar < xDestination) {
      //se déplacer à gauche
      TurnLeft();
      Direction = 3;
      if (xAcar == 0 && yAcar == 2)xAcar += 3;
      else if (xAcar == 1 && yAcar == 4)xAcar += 3;
      xAcar += 1;
    } else {
      // si l'objectif est au meme niveau
      if (yAcar == yDestination); //arrivé
        // si l'objectif est derrierre
        else TurnLeft();   // aller a gauche sinon aller a droite
    }


  // Vers l'Est
  }else if (Direction == 3) {
    //si l'objectif est en face
    if (xAcar > xDestination) TurnLeft();  // aller a gauche sinon aller a droite
    // si l'objectif est derrière
    else if (xAcar < xDestination)TurnLeft();   // aller a gauche sinon aller a droite
    else {
      //si l'objectif est a gauche
      if (yAcar > yDestination) {
        //tourner à gauche
        TurnLeft();
        Direction = 1;
        if (xAcar == 3 && yAcar == 2)yAcar -= 2;
        else if (xAcar == 4 && yAcar == 2)yAcar -= 2;
        else yAcar -= 1;
        // si l'objectif est a droite
      } else if (yAcar < yDestination) {
        //tourner à droite
        TurnRight();
        Direction = 2;
        if (xAcar == 0 && yAcar == 2)yAcar += 2;
        else if (xAcar == 4 && yAcar == 0)yAcar += 2;
        else if (xAcar == 4 && yAcar == 2)yAcar += 2;
        else if (xAcar == 3 && yAcar == 0)yAcar += 2;
        else yAcar += 1;
      }else;//arrivé
    }


    // Vers l'Ouest
  } else if (Direction == 4) {
    // si l'objectif est en face
    if (xAcar > xDestination) TurnLeft();   // aller a gauche sinon aller a droite
      // si l'objectif est derier
    else if (xAcar < xDestination) TurnLeft();   // aller a gauche sinon aller a droite
      // si l'object est au meme niveau
    else {
      // si l'objectif est a droite
      if (yAcar > yDestination) {
        //tourner à droite
        TurnRight();
        Direction = 1;
        if (xAcar == 3 && yAcar == 2) yAcar -= 2;
        else if (xAcar == 0 && yAcar == 4) yAcar -= 2;
        else yAcar -= 1;
        //si l'objectif est a gauche
      }else if (yAcar < yDestination) {
        //tourner à gauche
        TurnLeft();
        Direction = 2;
        if (xAcar == 0 && yAcar == 2) yAcar += 2;
        else if (xAcar == 3 && yAcar == 0) yAcar += 2;
        else yAcar += 1;
      }else; //arrivé
    }
  }
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
    if (AD == 0 && AG == 0)Avancer();
    // si le capteur central et un autre capteur est actif choisir une direciton
    else ChoixDirection();
  // si le capteur central n'est pas actif
  }else{
    // si aucun capteur n'est actif, continuer le mouvement
    if (AD == 0 && AG == 0){
       Motor.speed(MOTOR1, 0);
       Motor.speed(MOTOR2, 0);
    }
    // si seul le capteur droit est actif, aller à gauche
    else if(AD == 1 && AG == 0) TurnLeft();
    // si seul le capteur gauche est actif, aller à droite
    else if (AD == 0 && AG == 1)TurnRight();
    // si le capteur droite et gauche est actif, choisir une direciton
    else ChoixDirection();
  }
  delay(100);
}
