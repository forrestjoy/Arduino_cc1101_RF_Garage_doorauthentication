#include <ELECHOUSE_CC1101.h>
#define size 12
byte buffer[size];
byte transmitt_byte[11] = {72,101,108,108,111,32,87,111,114,108,100};
byte code[12]={48,48,48,48,48,48,48,48,48,48,48,48};

  int currentState = 0;     // current state of the button
  int lastState = 0; // previous state of the button
  int pressed = 0;    // the moment the button was pressed
  int released = 0;      // the moment the button was released
  int blueCounter=0;
  int whiteCounter=0;
  bool checkpress;
  bool notPressed=digitalRead(8);
  bool recordseq;
  int sequence;
void setup() {
  Serial.begin(9600);
  Serial.println("starting: ");
  ELECHOUSE_cc1101.Init(); // set frequency - F_433, F_868, F_965 MHz
  pinMode(4,OUTPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
}
void loop() {
    currentState=digitalRead(8);
    recordseq=digitalRead(6);
    if(recordseq==HIGH){
      digitalWrite(4,HIGH);
      delay(1000);
      digitalWrite(4,LOW);
      int collected=record();
      if(collected==1){
        Serial.println("Sequence collected");
        delay(500);
      }
      recordseq=0;
    }
    if(digitalRead(8)){
      ELECHOUSE_cc1101.SendData(code, 12); 
      delay(250);
      Serial.println((char *) code);
    }
    if(digitalRead(7)){
      for(int i=0;i<12;i++){
        code[i]=48;
        }
    }
}
int record(){
  int i=0;
  Serial.println("Input sequence");
  while(!digitalRead(6) && i<12){
    if(digitalRead(8)){
      Serial.println("Blue pushed___ 0 added");
      blueCounter++;
      delay(250);
      code[i]=48;
      i++;
    }
    if(digitalRead(7)){
      Serial.println("White pushed___ 1 added");
      whiteCounter++;
      delay(250);
      code[i]=49;
      i++;
    }
  }
  return 1;
  //Serial.println((char *)code);
}
