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

Avancer(){

  Motor.speed(MOTOR1,50);
  Motor.speed(MOTOR2,50);

}

TurnDroite(){
    Motor.speed(MOTOR1,50);
    Motor.speed(MOTOR2, 20);
    delay(150);
    

}

TurnLeft(){
  Motor.speed(MOTOR1,20);
      Motor.speed(MOTOR2, 50);
      delay(150);

}

ChoixDirection(){

  if(Direction == 1)
{
  if(xAcar > xDestination){
    // se déplacer à gauche 
    TurnLeft();
    Direction = 4;
     x-= 1;
     
    
  }else if (xAcar < xDestination){
    //se déplacer à droite
      TurnRight();

    Direction = 3;
    x+= 1;
  }else{
    if(yAcar == yDestination){
      //arrivé
    }else if (yAcar > yDestination){

      if(xAcar > 0){
        //Aller à gauche
        
        TurnLeft();
        Direction = 4;
     x-= 1;
        
      }else{
        //aller à droite

          TurnRight();
        Direction = 3;
     x+= 1;
      }
      
    }else if(yAcar < yDestination){
      //Aller tout droit
            
     Avancer();
     y+= 1;
      
    }

    
    }   
  
  }
}else if ( Direction == 2){

  if(xAcar > xDestination){
    // se déplacer à droite
       TurnRight();

    Direction = 4;
    x-= 1;
    
  }else if (xAcar < xDestination){
    //se déplacer à gauche
        TurnLeft();
    Direction = 3;
     x+= 1; 
     }else{
    if(yAcar == yDestination){
      //arrivé
    }else if (yAcar < yDestination){

      if(xAcar > 0){
        //Aller à droite

             TurnRight();

    Direction = 4;
    x-= 1;
        
      }else{
        //aller à gauche
      
           TurnLeft();
        Direction = 3;
     x+= 1;
      }
      }else if(yAcar > yDestination){
      //Aller tout droit
            
      Avancer();  
      y-=1;
    } 
    }
  
  
}else if (Direction == 3){
  if(xAcar > xDestination){
// aller tout droit
  Avancer();
  x+=1;
    
  }else if (xAcar < xDestination){

    if(xAcar > 0){

      //Tourner à gauche
          TurnLeft();

  Direction = 1;
  y-=1;
    }else{
// tourner à droite

     TurnRight();
  Direction = 2;
  y+=1;
    }

  } else{
    if(yAcar > yDestination){

       //tourner à gauche
        TurnLeft();

  Direction = 1;
  y-=1;
  
  }else if(yAcar < yDestination){
      //tourner à droite
          TurnRight();

      Direction = 2;
       y+=1;
    }else{
      //arrivé
    }
  }
}else if (Direction == 4){
  if(xAcar > xDestination){
    
  if(xAcar > 0){
    
      //tourner à droite
         TurnRIght();
      Direction = 1;
          y-=1;
      
    }else{
// tourner à gauche
      TurnLeft();
      Direction = 2;
      y+=1; 
      
    }

  }else if (xAcar < xDestination){
    //aller tout droit
      Avancer();
  x-=1;
  }else{
    if(yAcar > yDestination){
       
      //tourner à droite
         TurnRight();
      Direction = 1;
          y-=1;
      
      
    }else if(yAcar < yDestination){
      //tourner à gauche
          TurnLeft();
      Direction = 2;
      y+=1; 
      
    }else{
      //arrivé
    }
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
  if (AD == 0 && AG == 0){
  
    
  // si le capteur droit est actif aller à gauche jusqu'à ce que le capteur central ne soit plus actif puis actif
  }else if(AD == 1 && AG == 0){
  
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
  
  }
// si le capteur central n'est pas actif
}else{
  // si aucun capteur n'est actif, continuer le mouvement
  if (AD == 0 && AG == 0){

  // si seul le capteur droit est actif, aller à gauche
  }else if(AD == 1 && AG == 0){
   
  // si seul le capteur gauche est actif, aller à droite
  }else if (AD == 0 && AG == 1){
   
  // si le capteur droite et gauche est actif, aller a droite et a gauche aléatoirement
  }else{
    //remplir
  
  }
}
delay(100);
}

