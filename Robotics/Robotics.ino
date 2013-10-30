#include <MeetAndroid.h>
#include <math.h>
//declare variables for the motor pins
//Left Motors
int motorPin1 = 8;	
int motorPin2 = 9;	
int motorPin3 = 10;	
int motorPin4 = 11;	

//Right Motors
int motorPin01 = 4;	
int motorPin02 = 5;	
int motorPin03 = 6;	
int motorPin04 = 7;	
                      
int motorSpeed = 1200;  
int count = 0;          // count of steps made
int countsperrev = 512; // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

//used to calculate angle turns
int wheeldiammm = 54;
int distancebetweenwheels = 100;
int wheelcircumference = ceil(3.1415926535*wheeldiammm);
int robotcircumference = ceil(3.1415926535*distancebetweenwheels);

MeetAndroid meetAndroid;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorPin01, OUTPUT);
  pinMode(motorPin02, OUTPUT);
  pinMode(motorPin03, OUTPUT);
  pinMode(motorPin04, OUTPUT);
  Serial.begin(9600);
  
  meetAndroid.registerFunction(forward,'A');
  meetAndroid.registerFunction(reverse,'B');
  meetAndroid.registerFunction(spinRight,'C');
  meetAndroid.registerFunction(spinLeft,'D');
}

void loop()
{
  meetAndroid.receive();
}

void forward(byte flag, byte numOfValues)
{
  for(int j = 0; j < countsperrev; j++){
      for(int i = 0; i < 8; i++){
        setOutput1(i);
        delayMicroseconds(motorSpeed);
      }
  }
}

void reverse(byte flag, byte numOfValues)
{
  for(int j = 0; j < countsperrev; j++){
      for(int i = 0; i < 8; i++){
        setOutput1(7 - i); 
        delayMicroseconds(motorSpeed);
      }
  }
}

void spinRight(byte flag, byte numOfValues)
{
  for(int j = 0; j < 254; j++){
      for(int i = 0; i < 8; i++){
        setOutput2(i); 
        delayMicroseconds(motorSpeed);
      }
  }
}

void spinLeft(byte flag, byte numOfValues)
{
  for(int j = 0; j < 254; j++){
      for(int i = 0; i < 8; i++){
        setOutput2(7 - i);
        delayMicroseconds(motorSpeed);
      }
  }
}

void setOutput2(int out)  // Move wheels opposite directions
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
  digitalWrite(motorPin01, bitRead(lookup[out], 0));
  digitalWrite(motorPin02, bitRead(lookup[out], 1));
  digitalWrite(motorPin03, bitRead(lookup[out], 2));
  digitalWrite(motorPin04, bitRead(lookup[out], 3));
}

void setOutput1(int out)  // Move wheels same direction
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
  digitalWrite(motorPin01, bitRead(lookup[7-out], 0));
  digitalWrite(motorPin02, bitRead(lookup[7-out], 1));
  digitalWrite(motorPin03, bitRead(lookup[7-out], 2));
  digitalWrite(motorPin04, bitRead(lookup[7-out], 3));
}


