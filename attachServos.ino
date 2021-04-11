#include<Servo.h>


Servo servo1;
Servo servo2;

//servo positions
int pos1 = 0;
int pos2 = 0;

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;



void setup() {
  // put your setup code here, to run once:
  servo1.attach(7);
  servo2.attach(5);
 
  Serial.begin(9600);
  
}


void writeSigned16BitValue(int value){
  int isNegative = 0;
  if(value<0){
    isNegative = 1;
    value = -value;
  }
  /*
  Serial.write(isNegative);

  Serial.write((value>>8)&0xff);
  Serial.write(value&0xff);
  */
}



void loop() {
  // 
    recvWithEndMarker();
    showNewData();
  /*digitalWrite(10,HIGH);
  delay(600);
  

  //Serial.println("hi!"); // write a string
  delay(1000);
  
  
  char data = Serial.read();
  Serial.print('hi');
  switch(data){
    case 'ON': digitalWrite(10,HIGH);break;
    case 'OFF': digitalWrite(10,LOW);break;
  }
  

  // put your main code here, to run repeatedly:
  for(pos1=0; pos1<180; pos1++){
    servo1.write(pos1);
    servo2.write(pos1); 
    delay(5);
    
  }
  for(pos1=180;pos1>0;pos1--){
    servo1.write(pos1);
    servo2.write(pos1); 
    delay(5);
   
  }
  */
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
   
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}


void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

  