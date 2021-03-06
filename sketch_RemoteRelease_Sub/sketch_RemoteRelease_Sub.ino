/*

  RemoteRelease sub
  
  ~ For Public ~
  
  m45-astroX
  
  D0 : RX
  D1 : TX
  D2 : releaseSw
  D3 : resetSw
  D4 : LantanOut
  D5 : RotarySw1
  D6 : RotarySw2
  D7 : RotarySw3
  D8 : RotarySw4
  D9 : RotarySw5

*/


byte ss = 'p';
int releaseStatus = LOW;
int resetStatus = LOW;
int rotaryStatus1 = LOW;
int rotaryStatus2 = LOW;
int rotaryStatus3 = LOW;
int rotaryStatus4 = LOW;
int rotaryStatus5 = LOW;
int rotaryStatus6 = LOW;

const int lantanPin = 4;
const int rotarySw1 = 5;
const int rotarySw2 = 6;
const int rotarySw3 = 7;
const int rotarySw4 = 8;
const int rotarySw5 = 9;
const int rotarySw6 = 10;

const int soundPin = 19;
int soundStatus = 0;

// var for bright
int startT = 0;
int waitT = 0;
int nowT = 0;

// var for request for master
int freezeNowT = 0;
int freezeT = 0;
int freezeStartT = 0;

// releasePin input
const int releasePin = 2;
int LBS = LOW;
long LDT = 0;
long DD = 50;
long DDB = 100;
//volatile byte releaseStatus = 0;

// resetPin input
const int resetPin = 3;
int LBS2 = LOW;
long LDT2 = 0;
//volatile byte resetStatus = 0;

// release input
const int releaseInPin = 10;
int LBS3 = LOW;
long LDT3 = 0;
int releaseInStatus = 0;

int v = 0;
int extra = 0;

// actuator
const int LEDPin = 11;
int lastLEDT = 0;
int lastSoundT = 0;

int doubleSendl = 0;
int lastDoubleSendlT = 0;

int doubleSendD = 0;
int lastDoubleSendDT = 0;

int offPermitState = LOW;
int releaseStartT = 0;

/* setup */
void setup() {

  Serial.begin(9600);
  pinMode(releasePin, INPUT_PULLUP);
  pinMode(resetPin, INPUT_PULLUP);
  pinMode(lantanPin, OUTPUT);
  pinMode(rotarySw1, INPUT_PULLUP);
  pinMode(rotarySw2, INPUT_PULLUP);
  pinMode(rotarySw3, INPUT_PULLUP);
  pinMode(rotarySw4, INPUT_PULLUP);
  pinMode(rotarySw5, INPUT_PULLUP);
  pinMode(rotarySw6, INPUT_PULLUP);
  
  pinMode(LEDPin, OUTPUT);
  pinMode(releaseInPin, INPUT);
  pinMode(soundPin, OUTPUT);
  digitalWrite(soundPin, HIGH);
  
  lastSoundT = 0;
  
}

void loop() {
  
  int now7 = millis();
  if (now7 - lastSoundT >= 1000) {
    digitalWrite(soundPin, LOW);
  }

  // release
  int releaseSelect = !digitalRead(rotarySw6);
  if ( releaseSelect == LOW ) {
    
    int releaseInStatus = !digitalRead(releaseInPin);
    
    if ( LBS3 == LOW && releaseInStatus == HIGH ) {
      if (( millis() - LDT3 ) > DD) {
        Serial.print('l');
      }
      LDT3 = millis();
    }
    else if ( LBS3 == HIGH && releaseInStatus == LOW ) {
      Serial.print('D');
    }
    LBS3 = releaseInStatus;
  }

  else if ( releaseSelect == HIGH ) {   // auto mode
    int releaseInStatus = !digitalRead(releaseInPin);
    if ( LBS3 == LOW && releaseInStatus == HIGH ) {
      Serial.print('l');
      doubleSendl = 5;
      lastDoubleSendlT = millis();
    }
    else if ( LBS3 == HIGH && releaseInStatus == LOW ) {
      Serial.print('D');
      doubleSendD = 5;
      lastDoubleSendDT = millis();
    }
    LBS3 = releaseInStatus;
  }

  if ( Serial.available() > 0 ) {
    ss = Serial.read();
    if ( ss == 'Z' ) { 
      waitT = 0;
      ss = 'p';
      extra = 0;
      offRun();
      doubleSendD = 0;
    }
    else if ( ss == 'q' ) {
      digitalWrite(LEDPin, HIGH);
      lastLEDT = millis();
      Serial.print('q');
    }
    else if ( ss == 'r' ) {
      digitalWrite(soundPin, HIGH);
      lastSoundT = millis();
    }
    else {
      if ( ss == 'A' ) { waitT = 30000; extra = 1; }
      else if (ss == 'B') { waitT = 20000; extra = 1; }
      else if (ss == 'C') { waitT = 10000; extra = 1; }
      else if (ss == 'D') { waitT = 30000; }
      else if (ss == 'E') { waitT = 25000; }
      else if (ss == 'F') { waitT = 20000; }
      else if (ss == 'G') { waitT = 15000; }
      else if (ss == 'H') { waitT = 13000; }
      else if (ss == 'I') { waitT = 10000; }
      else if (ss == 'J') { waitT = 8000; }
      else if (ss == 'K') { waitT = 6000; }
      else if (ss == 'L') { waitT = 5000; }
      else if (ss == 'M') { waitT = 4000; }
      else if (ss == 'N') { waitT = 3200; }
      else if (ss == 'O') { waitT = 2500; }
      else if (ss == 'P') { waitT = 2000; }
      else if (ss == 'Q') { waitT = 1600; }
      else if (ss == 'R') { waitT = 1300; }
      else if (ss == 'S') { waitT = 1000; }
      else if (ss == 'T') { waitT = 800; }
      else if (ss == 'U') { waitT = 600; }
      else if (ss == 'V') { waitT = 500; }
      else if (ss == 'W') { waitT = 400; }
      else if (ss == 'X') { waitT = 333; }
      else if (ss == 'Y') { waitT = 250; }
      else if (ss == 'a') { waitT = 200; }
      else if (ss == 'b') { waitT = 167; }
      else if (ss == 'c') { waitT = 125; }
      else if (ss == 'd') { waitT = 100; }
      else if (ss == 'e') { waitT = 77; }
      else if (ss == 'f') { waitT = 67; }
      else if (ss == 'g') { waitT = 50; }
      else if (ss == 'h') { waitT = 40; }
      else if (ss == 'i') { waitT = 33; }
      else if (ss == 'j') { waitT = 25; }
      else if (ss == 'k') { waitT = 20; }
      else if (ss == 'l') { waitT = 17; }
      else if (ss == 'm') { waitT = 13; }
      else if (ss == 'n') { waitT = 10; }
      else if (ss == 'o') { waitT = 8; }
      
      startT = millis();
      onRun();
      ss = 'p';
      doubleSendl = 0;
      
    }
    
  }
  if (extra == 0) {
    if ((millis() - startT) > waitT) {
      offRun();
    }
  }
  else if (extra != 0) {
    if ((millis() - startT) > 30000) {
      extra = extra - 1;
      startT = millis();
    }
  }
  rotaryStatus1 = !digitalRead(rotarySw1);
  rotaryStatus2 = !digitalRead(rotarySw2);
  rotaryStatus3 = !digitalRead(rotarySw3);
  rotaryStatus4 = !digitalRead(rotarySw4);
  rotaryStatus5 = !digitalRead(rotarySw5);

  // request release sw
  int releaseStatus = !digitalRead(releasePin);
  if (LBS == LOW && releaseStatus == HIGH) {
    int now = millis();
    if ((now - LDT) > DD) {
      if (rotaryStatus1 == HIGH) {
        freezeT = 0;
      }
      else if (rotaryStatus2 == HIGH) {
        freezeT = 2000;
      }
      else if (rotaryStatus3 == HIGH) {
        freezeT = 5000;
      }
      else if (rotaryStatus4 == HIGH) {
        freezeT = 10000;
      }
      else if (rotaryStatus5 == HIGH) {
        freezeT = 15000;
      }
      freezeStartT = millis();
      v = 1;
    }
    LDT = now;
  }
  LBS = releaseStatus;

  // reset input
  int resetStatus = !digitalRead(resetPin);
  if (LBS2 == LOW && resetStatus == HIGH) {
    int now2 = millis();
    if ((now2 - LDT2) > DD) {
      resetRequest();
    }
    LDT2 = now2;
  }
  LBS2 = resetStatus;

  freezeNowT = millis();
  if (v == 1) {
    if ((freezeNowT - freezeStartT) > freezeT) {
      freezeNowT = 0;
      freezeStartT = 0;
      freezeT = 0;
      v = 0;
      releaseRequest();
    }
  }
  int now4 = millis();
  if ((now4 - lastLEDT) > 200) {
    digitalWrite(LEDPin, LOW);
    lastLEDT = 0;
  }

  int nowDoubleSendlT = millis();
  if (doubleSendl != 0 && (nowDoubleSendlT - lastDoubleSendlT) > 3) {
    Serial.print('l');
    doubleSendl = doubleSendl - 1;
    lastDoubleSendlT = millis();
  }

  int nowDoubleSendDT = millis();
  if (doubleSendD != 0 && (nowDoubleSendDT - lastDoubleSendDT) > 3) {
    Serial.print('D');
    doubleSendD = doubleSendD - 1;
    lastDoubleSendDT = millis();

  }
}


void onRun() {
  digitalWrite(lantanPin, HIGH);
}

void offRun() {
  digitalWrite(lantanPin, LOW);
}

void releaseRequest() {
  Serial.print('L');
}

void resetRequest() {
  Serial.print('D');
}
