#include <SoftwareSerial.h>

SoftwareSerial Xbee(2,3);

int motorPin = 5;
int motorPWM = 4;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  //Serial1.begin(9600);
  Serial.begin(9600);
}

void loop(){
  while(Serial.available() > 1){
   int pwm = Serial.read();
     if(pwm > 0 && pwm <= 255){
       int dir = 1;
       digitalWrite(motorPin, dir);
       analogWrite(motorPWM, pwm);
     }else if(pwm > 255 && pwm <= 510){
       int dir = 0;
       digitalWrite(motorPin, dir);
       analogWrite(motorPWM, pwm);     
     }else{
       analogWrite(motorPWM, 0);
     }
  }
}
