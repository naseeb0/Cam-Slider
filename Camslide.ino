

#include <SoftwareSerial.h>

SoftwareSerial Genotronex(10, 11); 



int dirPin = 8;
int stepperPin = 9;
String inData="";
String dinData="";
int sliderspeed=1;
int sliderdist=1;


void setup() {

  Genotronex.begin(9600);


   pinMode(dirPin, OUTPUT);
 pinMode(stepperPin, OUTPUT);
  
}
 void step(boolean dir,int steps,int sldrspeed){
 digitalWrite(dirPin,dir);
 delay(5);
 for(int i=0;i<(steps);i++){
    for(int j=0;j<32;j++){
   digitalWrite(stepperPin, HIGH);
   delayMicroseconds(200+(sldrspeed-1)*2000); 
   digitalWrite(stepperPin, LOW);
   delayMicroseconds(200+(sldrspeed-1)*2000);
    }
 }
}
void loop() {
 Genotronex.println("Left ! ");
 step(true,200*sliderdist,sliderspeed);
 delay(500);
  step(false,200*sliderdist,sliderspeed);
 delay(500);
  Genotronex.println("Reverse ! ");
  }
      
