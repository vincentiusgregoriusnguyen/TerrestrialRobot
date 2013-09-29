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
int count = 0;          
int countsperrev = 512; // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

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
}

void loop()
{
  for (int i = 0; i < countsperrev; i++)
    forward();
  for (int i = 0; i < countsperrev; i++)
    reverse();
  for (int i = 0; i < countsperrev; i++)
    spinLeft();
  for (int i = 0; i < countsperrev; i++)
    spinRight();
}

void forward()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput1(i); 
    delayMicroseconds(motorSpeed);
  }
}

void reverse()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput1(7 - i); 
    delayMicroseconds(motorSpeed);
  }
}

void spinRight()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput2(i); 
    delayMicroseconds(motorSpeed);
  }
}

void spinLeft()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput2(7 - i); 
    delayMicroseconds(motorSpeed);
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


