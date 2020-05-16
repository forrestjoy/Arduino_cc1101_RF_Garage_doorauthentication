#include <ELECHOUSE_CC1101.h>

#define size 12
byte buffer[12];
byte codeToCheck[12]={48,49,48,48,49,48,48,48,48,48,48,48};
bool x=0;
void setup(){
  Serial.begin(9600);
  Serial.println("Receiving");
  ELECHOUSE_cc1101.Init();//F_433);  // set frequency - F_433, F_868, F_965 MHz
  ELECHOUSE_cc1101.SetReceive();
  pinMode(4,OUTPUT);
}
void loop(){
  if (ELECHOUSE_cc1101.CheckReceiveFlag()){
    //digitalWrite(4,HIGH);
    delay(50);
    //digitalWrite(4,LOW);
    int len = ELECHOUSE_cc1101.ReceiveData(buffer);
    //Serial.println("Checking code: ");
    Serial.println((char *) buffer);
    delay(50);
    Serial.println((char *) codeToCheck);
    int checked=checkCode(codeToCheck,buffer);
    if(checked==1){
      Serial.println("User Successfully Authenticated");
      digitalWrite(4,HIGH);
      delay(50);
      digitalWrite(4,LOW);
    }
    else{
    Serial.println("Failure to Authenticate");
    }
    ELECHOUSE_cc1101.SetReceive();
  }
}
int checkCode(byte checkCode[],byte receivedCode[]){
  byte a;
  byte b;
  for(int i=0;i<12;i++){
    a=checkCode[i];
    b=receivedCode[i];
    if(a!=b){
      Serial.println(a);
      Serial.println(b);
      return 0;    
    }
  }
  return 1;
}
/*digitalWrite(4,HIGH);                000101110000
    delay(150);                        000011101000
    digitalWrite(4,LOW);
    delay(150);*/
    /*Serial.println((char *) buffer);*/
    /*if(x==0){digitalWrite(4,HIGH);delay(250);}
else{digitalWrite(4,LOW);delay(250);}*/
