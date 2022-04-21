/*

  Remote Release Main1

  Main

  m45-astroX
  
  D0 : RX
  D1 : TX
  D2 : EncoderA
  D3 : EncoderB
  D4 : intSelectSw
  D5 : releasePin
  D6 : resetPin
  D7 : LightingPin
  
  A4 : SDA
  A5 : SCL
  
*/

#include <Wire.h>

// Encoder
#define ENC_A 2
#define ENC_B 3

byte pos;
byte enc_count = 51;
byte pos2;
byte enc_count2 = 51;

// releasePin input
const int releasePin = 5;
int LBS = LOW;
long LDT = 0;
long DD = 50;
volatile byte releaseStatus = 0;

// resetPin input
const int resetPin = 6;
int LBS2 = LOW;
long LDT2 = 0;
byte resetStatus = 0;

// LightingPin input
const int lightingPin = 7;
int LBS3 = LOW;
long LDT3 = 0;
volatile byte lightingStatus = 0;
int d = 0;  // delight permission
int startLightingT = 0;

// request release
byte ss = ':';
int waitST = 0;

// release output
const int releaseOutPin = 10;

// var
const int intSelectPin = 4;
const int LEDPin = 11;
int intSelectStatus = LOW;
int extra = 0;
int lastLEDT = 0;
int lastMyLEDT = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(request);

  // Encoder
  // interrupt pin ( ATMEGA328P )
  // 0:D2 , 1:D3
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  attachInterrupt(0, ENC_READ, CHANGE); // pin(D2) / function / terms
  attachInterrupt(1, ENC_READ, CHANGE); // pin(D3)/ function / terms

  pinMode(releasePin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
  pinMode(lightingPin, INPUT_PULLUP);
  pinMode(releaseOutPin, OUTPUT);
  digitalWrite(releaseOutPin, LOW);
  pinMode(intSelectPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
  
}


void loop() {

  // release input
  int releaseStatus = !digitalRead(releasePin);
  if (LBS == LOW && releaseStatus == HIGH) {
    int now = millis();
    if ((now - LDT) > DD) {
      digitalWrite(releaseOutPin, HIGH);
      releaseRun();
    }
    LDT = now;
  }
  else if (LBS == HIGH && releaseStatus == LOW) {
    digitalWrite(releaseOutPin, LOW);
  }
  LBS = releaseStatus;
  
  int resetStatus = !digitalRead(resetPin);
  if (LBS2 == LOW && resetStatus == HIGH) {
    int now2 = millis();
    if ((now2 - LDT2) > DD) {
      digitalWrite(releaseOutPin, LOW);
      extra = 0;
      d = 0;
      startLightingT = 0;
      ss = ':';
      waitST = 0;
      resetRun();
      Serial.print('r');
      
    }
    LDT2 = now2;
  }
  LBS2 = resetStatus;


  // lighting sw
  int lightingStatus = !digitalRead(lightingPin);
  if (LBS3 == LOW && lightingStatus == HIGH) {
    int now3 = millis();
    if ((now3 - LDT3) > DD) {
      digitalWrite(releaseOutPin, HIGH);
      d = 1;
      startLightingT = millis();

      if (enc_count2 == 1) { waitST = 20000; extra = 21; }
      else if (enc_count2 == 2) { waitST = 30000; extra = 19; }
      else if (enc_count2 == 3) { waitST = 10000; extra = 18; }
      else if (enc_count2 == 4) { waitST = 20000; extra = 16; }
      else if (enc_count2 == 5) { waitST = 30000; extra = 15; }
      else if (enc_count2 == 6) { waitST = 10000; extra = 15; }
      else if (enc_count2 == 7) { waitST = 20000; extra = 14; }
      else if (enc_count2 == 8) { waitST = 30000; extra = 13; }
      else if (enc_count2 == 9) { waitST = 10000; extra = 13; }
      else if (enc_count2 == 10) { waitST = 20000; extra = 12; }
      else if (enc_count2 == 11) { waitST = 30000; extra = 11; }
      else if (enc_count2 == 12) { waitST = 10000; extra = 11; }
      else if (enc_count2 == 13) { waitST = 20000; extra = 10; }
      else if (enc_count2 == 14) { waitST = 30000; extra = 9; }
      else if (enc_count2 == 15) { waitST = 10000; extra = 9; }
      else if (enc_count2 == 16) { waitST = 20000; extra = 8; }
      else if (enc_count2 == 17) { waitST = 30000; extra = 7; }
      else if (enc_count2 == 18) { waitST = 10000; extra = 7; }
      else if (enc_count2 == 19) { waitST = 20000; extra = 6; }
      else if (enc_count2 == 20) { waitST = 10000; extra = 6; }
      else if (enc_count2 == 21) { waitST = 30000; extra = 5; }
      else if (enc_count2 == 22) { waitST = 20000; extra = 5; }
      else if (enc_count2 == 23) { waitST = 10000; extra = 5; }
      else if (enc_count2 == 24) { waitST = 30000; extra = 4; }
      else if (enc_count2 == 25) { waitST = 20000; extra = 4; }
      else if (enc_count2 == 26) { waitST = 10000; extra = 4; }
      else if (enc_count2 == 27) { waitST = 30000; extra = 3; }
      else if (enc_count2 == 28) { waitST = 20000; extra = 3; }
      else if (enc_count2 == 29) { waitST = 10000; extra = 3; }
      else if (enc_count2 == 30) { waitST = 30000; extra = 2; }
      else if (enc_count2 == 31) { waitST = 20000; extra = 2; }
      else if (enc_count2 == 32) { waitST = 10000; extra = 2; }
      else if (enc_count2 == 33) { waitST = 30000; extra = 1; }
      else if (enc_count2 == 34) { waitST = 20000; extra = 1; }
      else if (enc_count2 == 35) { waitST = 10000; extra = 1; }
      else if (enc_count2 == 36) { waitST = 30000; }
      else if (enc_count2 == 37) { waitST = 25000; }
      else if (enc_count2 == 38) { waitST = 20000; }
      else if (enc_count2 == 39) { waitST = 15000; }
      else if (enc_count2 == 40) { waitST = 13000; }
      else if (enc_count2 == 41) { waitST = 10000; }
      else if (enc_count2 == 42) { waitST = 8000; }
      else if (enc_count2 == 43) { waitST = 6000; }
      else if (enc_count2 == 44) { waitST = 5000; }
      else if (enc_count2 == 45) { waitST = 4000; }
      else if (enc_count2 == 46) { waitST = 3000; }
      else if (enc_count2 == 47) { waitST = 2500; }
      else if (enc_count2 == 48) { waitST = 2000; }
      else if (enc_count2 == 49) { waitST = 1600; }
      else if (enc_count2 == 50) { waitST = 1300; }
      else if (enc_count2 == 51) { waitST = 1000; }
      
      releaseRun();
      
    }
    
    LDT3 = now3;
    
  }
  
  LBS3 = lightingStatus;
  
  // request release
  if ( Serial.available() > 0 ) {
    ss = Serial.read();
    if (ss == 'q') {
      digitalWrite(LEDPin, HIGH);
      lastMyLEDT = millis();
    }
    else if(ss == 'l'){
      releaseRun();
      digitalWrite(releaseOutPin, HIGH);
    }
    else if (ss == 'L') {
      if (enc_count2 == 1) { waitST = 20000; extra = 21; }
      else if (enc_count2 == 2) { waitST = 30000; extra = 19; }
      else if (enc_count2 == 3) { waitST = 10000; extra = 18; }
      else if (enc_count2 == 4) { waitST = 20000; extra = 16; }
      else if (enc_count2 == 5) { waitST = 30000; extra = 15; }
      else if (enc_count2 == 6) { waitST = 10000; extra = 15; }
      else if (enc_count2 == 7) { waitST = 20000; extra = 14; }
      else if (enc_count2 == 8) { waitST = 30000; extra = 13; }
      else if (enc_count2 == 9) { waitST = 10000; extra = 13; }
      else if (enc_count2 == 10) { waitST = 20000; extra = 12; }
      else if (enc_count2 == 11) { waitST = 30000; extra = 11; }
      else if (enc_count2 == 12) { waitST = 10000; extra = 11; }
      else if (enc_count2 == 13) { waitST = 20000; extra = 10; }
      else if (enc_count2 == 14) { waitST = 30000; extra = 9; }
      else if (enc_count2 == 15) { waitST = 10000; extra = 9; }
      else if (enc_count2 == 16) { waitST = 20000; extra = 8; }
      else if (enc_count2 == 17) { waitST = 30000; extra = 7; }
      else if (enc_count2 == 18) { waitST = 10000; extra = 7; }
      else if (enc_count2 == 19) { waitST = 20000; extra = 6; }
      else if (enc_count2 == 20) { waitST = 10000; extra = 6; }
      else if (enc_count2 == 21) { waitST = 30000; extra = 5; }
      else if (enc_count2 == 22) { waitST = 20000; extra = 5; }
      else if (enc_count2 == 23) { waitST = 10000; extra = 5; }
      else if (enc_count2 == 24) { waitST = 30000; extra = 4; }
      else if (enc_count2 == 25) { waitST = 20000; extra = 4; }
      else if (enc_count2 == 26) { waitST = 10000; extra = 4; }
      else if (enc_count2 == 27) { waitST = 30000; extra = 3; }
      else if (enc_count2 == 28) { waitST = 20000; extra = 3; }
      else if (enc_count2 == 29) { waitST = 10000; extra = 3; }
      else if (enc_count2 == 30) { waitST = 30000; extra = 2; }
      else if (enc_count2 == 31) { waitST = 20000; extra = 2; }
      else if (enc_count2 == 32) { waitST = 10000; extra = 2; }
      else if (enc_count2 == 33) { waitST = 30000; extra = 1; }
      else if (enc_count2 == 34) { waitST = 20000; extra = 1; }
      else if (enc_count2 == 35) { waitST = 10000; extra = 1; }
      else if (enc_count2 == 36) { waitST = 30000; }
      else if (enc_count2 == 37) { waitST = 25000; }
      else if (enc_count2 == 38) { waitST = 20000; }
      else if (enc_count2 == 39) { waitST = 15000; }
      else if (enc_count2 == 40) { waitST = 13000; }
      else if (enc_count2 == 41) { waitST = 10000; }
      else if (enc_count2 == 42) { waitST = 8000; }
      else if (enc_count2 == 43) { waitST = 6000; }
      else if (enc_count2 == 44) { waitST = 5000; }
      else if (enc_count2 == 45) { waitST = 4000; }
      else if (enc_count2 == 46) { waitST = 3000; }
      else if (enc_count2 == 47) { waitST = 2500; }
      else if (enc_count2 == 48) { waitST = 2000; }
      else if (enc_count2 == 49) { waitST = 1600; }
      else if (enc_count2 == 50) { waitST = 1300; }
      else if (enc_count2 == 51) { waitST = 1000; }
      
      digitalWrite(releaseOutPin, HIGH);
      d = 1;
      startLightingT = millis();
      
      releaseRun();
      
    }
    else if (ss == 'D') {
      digitalWrite(releaseOutPin, LOW);
      d = 0;
      extra = 0;
      startLightingT = 0;
      ss = ':';
      waitST = 0;
      resetRun();
      Serial.print('r');
    }
  }
  else {
    if ((millis() - lastMyLEDT) > 200) {
      lastMyLEDT = 0;
      digitalWrite(LEDPin, LOW);
    }
  }
  if (d == 1) {
    if (extra == 0) {
      if ((millis() - startLightingT) > waitST) {
        digitalWrite(releaseOutPin, LOW);
        d = 0;
        startLightingT = 0;
        ss = ':';
        waitST = 0;
        extra = 0;
        Serial.print('r');
      }
    }
    else if (extra != 0) {
      if ((now3 - startLightingT) > 30000) {
        extra = extra - 1;
        startLightingT = millis();
      }
    }
  }
  if ( (millis() - lastLEDT) > 200 ) {
    lastLEDT = millis();
    Serial.print('q');
  }
  
}


// I2C
void request() {
  intSelectStatus = !digitalRead(intSelectPin);
  if (intSelectStatus == LOW) {
    Wire.write(enc_count);
  }
  else if (intSelectStatus == HIGH) {
    Wire.write(enc_count2);
  }
}


// Encoder Count
void ENC_READ() {
  
  intSelectStatus = !digitalRead(intSelectPin);
  
  // turn off
  if ( intSelectStatus == LOW) {
    byte cur = (!digitalRead(ENC_B) << 1) + !digitalRead(ENC_A);
    byte old = pos & B00000011;
    byte dir = (pos & B00110000) >> 4;
    if (cur == 3) cur = 2;
    else if (cur == 2) cur = 3;
    if (cur != old) {
      if (dir == 0) {
        if (cur == 1 || cur == 3) dir = cur;
      }
      else {
        if (cur == 0)
        {
          if (dir == 1 && old == 3) enc_count++;
          else if (dir == 3 && old == 1) enc_count--;
          dir = 0;
        }
      }
      pos = (dir << 4) + (old << 2) + cur;
    }
    if (enc_count <= 33) {
      enc_count = 33;
    }
    if (enc_count >= 72) {
      enc_count = 72;
    }
  }
 
  else if (intSelectStatus == HIGH) {
    byte cur = (!digitalRead(ENC_B) << 1) + !digitalRead(ENC_A);
    byte old = pos2 & B00000011;
    byte dir = (pos2 & B00110000) >> 4;
    if (cur == 3) cur = 2;
    else if (cur == 2) cur = 3;
    if (cur != old) {
      if (dir == 0) {
        if (cur == 1 || cur == 3) dir = cur;
      }
      else {
        if (cur == 0)
        {
          if (dir == 1 && old == 3) enc_count2 ++;
          else if (dir == 3 && old == 1) enc_count2 --;
          dir = 0;
        }
      }
      pos2 = (dir << 4) + (old << 2) + cur;
    }
    if (enc_count2 <= 1) {
      enc_count2 = 1;
    }
    if (enc_count2 >= 51) {
      enc_count2 = 51;
    }
  }
}


// release
void releaseRun() {
  
  if (enc_count == 33) Serial.print('A');
  else if (enc_count == 34) Serial.print('B');
  else if (enc_count == 35) Serial.print('C');
  else if (enc_count == 36) Serial.print('D');
  else if (enc_count == 37) Serial.print('E');
  else if (enc_count == 38) Serial.print('F');
  else if (enc_count == 39) Serial.print('G');
  else if (enc_count == 40) Serial.print('H');
  else if (enc_count == 41) Serial.print('I');
  else if (enc_count == 42) Serial.print('J');
  else if (enc_count == 43) Serial.print('K');
  else if (enc_count == 44) Serial.print('L');
  else if (enc_count == 45) Serial.print('M');
  else if (enc_count == 46) Serial.print('N');
  else if (enc_count == 47) Serial.print('O');
  else if (enc_count == 48) Serial.print('P');
  else if (enc_count == 49) Serial.print('Q');
  else if (enc_count == 50) Serial.print('R');
  else if (enc_count == 51) Serial.print('S');
  else if (enc_count == 52) Serial.print('T');
  else if (enc_count == 53) Serial.print('U');
  else if (enc_count == 54) Serial.print('V');
  else if (enc_count == 55) Serial.print('W');
  else if (enc_count == 56) Serial.print('X');
  else if (enc_count == 57) Serial.print('Y');
  else if (enc_count == 58) Serial.print('a');
  else if (enc_count == 59) Serial.print('b');
  else if (enc_count == 60) Serial.print('c');
  else if (enc_count == 61) Serial.print('d');
  else if (enc_count == 62) Serial.print('e');
  else if (enc_count == 63) Serial.print('f');
  else if (enc_count == 64) Serial.print('g');
  else if (enc_count == 65) Serial.print('h');
  else if (enc_count == 66) Serial.print('i');
  else if (enc_count == 67) Serial.print('j');
  else if (enc_count == 68) Serial.print('k');
  else if (enc_count == 69) Serial.print('l');
  else if (enc_count == 70) Serial.print('m');
  else if (enc_count == 71) Serial.print('n');
  else if (enc_count == 72) Serial.print('o');
  
}

void resetRun() {
  
  Serial.print('Z');
  
}
