#include <SoftwareSerial.h>
#include <Wire.h>
#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f

int signalPinAG = 8;
int signalPinAD = 3;
int signalPinAA = 4;
int signalPinR = 5;
int A_AG;
int A_AD;
int A_AA;
int A_R;
int randomV;
int randomW;
int dir;

int AlignerD (int temps){
  Motor.speed(MOTOR1, 50);
  delay(temps);
    if(HIGH == digitalRead(signalPinR)){
      A_AA = 1;
      Motor.speed(MOTOR1, 30);
      Motor.speed(MOTOR2, 30);
    }else {
      temps += 200;
      AlignerD(temps);  
    }
}
int AlignerG (int temps){
  Motor.speed(MOTOR2, 50);
  delay(temps);
    if(HIGH == digitalRead(signalPinR)){
      A_AA = 1;
      Motor.speed(MOTOR1, 30);
      Motor.speed(MOTOR2, 30);
    }else {
      temps += 200;
      AlignerG(temps);  
    }
}

void setup() {
  // put your setup code here, to run once:
pinMode(signalPinAG, INPUT);
pinMode(signalPinAD, INPUT);
pinMode(signalPinAA, INPUT);
pinMode(signalPinR, INPUT);
Serial.begin(9600);
Motor.begin(I2C_ADDRESS);

}

void loop() {
  Motor.speed(MOTOR2, 100);
  delay(2600);
  Motor.speed(MOTOR2, 0);
  delay(5000);
}
