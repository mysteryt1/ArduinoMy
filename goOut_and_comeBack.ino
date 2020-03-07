#include "Wire.h"
#define addr 0x38
#define Si1 7
#define Si2 6
#define SW1 8
#define SW2 5
#define SW3 4
const int data[] = {0x00, 0x01, 0x07, 0x0f, 0x09, 0x39};
int num1 = 0;
int num2 = 0;
int t = 1;
bool A;
bool nana = true;
bool nana2 = true;
void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(Si1, OUTPUT);
  pinMode(Si2, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
}
void builder1() {
  if (nana) {
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 1;
        send();
        delay(1);
        send();
        num2 = 1;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 1;
        send();
        delay(1);
        send();
        num2 = 2;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 4;
        send();
        delay(1);
        send();
        num2 = 3;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 5;
        send();
        delay(1);
        send();
        num2 = 3;
      }
    }

    nana = false;
    nana2 = true;
  }
  num1 = 5;
  send();
  delay(1);
  send();
  num2 = 3;


}
void SW() {
  if (t == 1) {
    builder1();
  }
  if (digitalRead(SW1) == 0) {
    t = 0;
  }
  if (t == 0) {
    builder2();
  }
}
void builder2() {
  if (nana2) {

    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 4;
        send();
        delay(1);
        send();
        num2 = 3;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 1;
        send();
        delay(1);
        send();
        num2 = 2;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 1;
        send();
        delay(1);
        send();
        num2 = 1;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int i = 0; i < 30; i++) {
        num1 = 0;
        send();
        delay(1);
        send();
        num2 = 0;
      }
    }
    nana2 = false;
  }
  num1 = 0;
  send();
  delay(1);
  send();
  num2 = 0;
  if (digitalRead(SW1) == 0) {
    t = 1;
    nana = true;
  }

}
void send() {
  Wire.beginTransmission(addr);
  Wire.write(data[num1]);
  Wire.endTransmission();
  digitalWrite(Si1, HIGH);
  digitalWrite(Si2, LOW);
  delay(1);
  ////////////////////
  Wire.beginTransmission(addr);
  Wire.write(data[num2]);
  Wire.endTransmission();
  digitalWrite(Si1, LOW);
  digitalWrite(Si2, HIGH);
}
void loop() {

  SW();
}
