#include <SoftwareSerial.h>

SoftwareSerial btSerial(11, 9); // HC06's TXD RXD 순서

// enA in1 in2 in3 in4 enB
int enA = 3;
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 6;
int enB = 5;



int spd = 255;

void setup() {
  Serial.begin(9600); // 보드 레이트 맞추기
  btSerial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  if(btSerial.available()){
    char c = btSerial.read();
    Serial.println(c);
    if(c=='F'){
      forward();
    }
    else if(c=='B'){
      backward();
    }
    else if(c=='G'){
      goleft();
    }
    else if(c=='I'){
      goright();
    }
    else if(c=='L'){
      turnleft();
    }
    else if(c=='R'){
      turnright();
    }
    else if(c=='H'){
      backleft();
    }
    else if(c=='J'){
      backright();
    }
    else if(c=='S') {
      sstop();
    }
  }
  delay(10);
}


void forward(){
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  analogWrite(enA, spd);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enB, spd);
}
void backward(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  analogWrite(enA, spd);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enB, spd);
}
void goleft(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  analogWrite(enA, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enB, spd);
}
void goright(){
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  analogWrite(enA, spd);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  analogWrite(enB, 0);
}

void turnleft(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  analogWrite(enA, spd);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enB, spd);
}
void turnright(){
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  analogWrite(enA, spd);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enB, spd);
}

void backleft(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  analogWrite(enA, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enB, spd);
}

void backright(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  analogWrite(enA, spd);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  analogWrite(enB, 0);
}

void sstop(){
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  analogWrite(enA, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  analogWrite(enB, 0);
}
