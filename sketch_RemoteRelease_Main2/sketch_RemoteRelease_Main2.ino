/*
  
  Remote Release Main 2
  
  4 Segment printer

  m45-astroX

*/

#include <Wire.h>
#include <SPI.h>

#define SV 10       // SS ( ATMEGA328P_D10 )
#define SREG_NUM 2  // number of SHIFT RESISTOR

// pat(DIG number)_(print number)[]
byte pat1[] = {     // 1
  B00000000, B01100000,
};
byte pat1_len = 1;  // rows

byte pat2[] = {     // 2
  B00000000, B11011010,
};
byte pat2_len = 1;

byte pat3[] = {     // 3
  B00000000, B11110010,
};
byte pat3_len = 1;

byte pat4[] = {     // 4
  B00000000, B01100110,
};
byte pat4_len = 1;

byte pat5[] = {     // 5
  B00000000, B10110110,
};
byte pat5_len = 1;

byte pat6[] = {     // 6
  B00000000, B00111110,
};
byte pat6_len = 1;

byte pat7[] = {     // 7
  B00000000, B11100100,
};
byte pat7_len = 1;

byte pat8[] = {     // 8
  B00000000, B11111110,
};
byte pat8_len = 1;

byte pat9[] = {     // 9
  B00000000, B11110110,
};
byte pat9_len = 1;

byte pat0[] = {     // 0
  B00000000, B11111100,
};
byte pat0_len = 1;

byte patBlank[] = { // blank
  B00000000, B00000000,
};
byte patBlank_len = 1;

byte patDevide1[] = {   // "1/"
  B00000000, B01100100,
};
byte patDevide1_len = 1;

byte patSecond[] = {    // sec
  B00000000, B01000100,
};
byte patSecond_len = 1;

byte pat100[] = {       // "1."
  B00000000, B01100001,
};
byte pat100_len = 1;

byte pat200[] = {       // "2."
  B00000000, B11011011,
};
byte pat200_len = 1;

byte pat300[] = {       // "3."
  B00000000, B11110011,
};
byte pat300_len = 1;

byte pat1000[] = {      // "0."
  B00000000, B11111101,
};
byte pat1000_len = 1;

// var for I2C
byte ss = 0;   // shutter speed ( reference the "ss define list" )

// setting dig (init)
int dig1 = 10;
int dig2 = 30;
int dig3 = 0;
int dig4 = 12;


void setup() {

  Wire.begin();
  Serial.begin(9600);
  pinMode(SV, OUTPUT);
  digitalWrite(SV, HIGH);

}


void loop() {

  // connect to main 1
  Wire.requestFrom(8, 1);
  while ( Wire.available() != 0 ) {
    ss = Wire.read();
    Serial.print(ss);
    Serial.println();
  }

  if (ss == 1) {
    dig1 = 6;
    dig2 = 5;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 2) {
    dig1 = 6;
    dig2 = 0;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 3) {
    dig1 = 5;
    dig2 = 5;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 4) {
    dig1 = 5;
    dig2 = 0;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 5) {
    dig1 = 4;
    dig2 = 8;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 6) {
    dig1 = 4;
    dig2 = 6;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 7) {
    dig1 = 4;
    dig2 = 4;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 8) {
    dig1 = 4;
    dig2 = 2;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 9) {
    dig1 = 4;
    dig2 = 0;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 10) {
    dig1 = 3;
    dig2 = 8;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 11) {
    dig1 = 3;
    dig2 = 6;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 12) {
    dig1 = 3;
    dig2 = 4;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 13) {
    dig1 = 3;
    dig2 = 2;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 14) {
    dig1 = 3;
    dig2 = 0;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 15) {
    dig1 = 2;
    dig2 = 8;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 16) {
    dig1 = 2;
    dig2 = 6;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 17) {
    dig1 = 2;
    dig2 = 4;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 18) {
    dig1 = 2;
    dig2 = 2;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 19) {
    dig1 = 2;
    dig2 = 0;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 20) {
    dig1 = 1;
    dig2 = 9;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 21) {
    dig1 = 1;
    dig2 = 8;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 22) {
    dig1 = 1;
    dig2 = 7;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 23) {
    dig1 = 1;
    dig2 = 6;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 24) {
    dig1 = 1;
    dig2 = 5;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 25) {
    dig1 = 1;
    dig2 = 4;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 26) {
    dig1 = 1;
    dig2 = 3;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 27) {
    dig1 = 1;
    dig2 = 2;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 28) {
    dig1 = 1;
    dig2 = 1;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 29) {
    dig1 = 1;
    dig2 = 0;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 30) {
    dig1 = 10;
    dig2 = 9;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 31) {
    dig1 = 10;
    dig2 = 8;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 32) {
    dig1 = 10;
    dig2 = 7;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 33) {
    dig1 = 10;
    dig2 = 6;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 34) {
    dig1 = 10;
    dig2 = 5;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 35) {
    dig1 = 10;
    dig2 = 4;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 36) {
    dig1 = 10;
    dig2 = 3;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 37) {
    dig1 = 10;
    dig2 = 2;
    dig3 = 5;
    dig4 = 12;
  }
  else if (ss == 38) {
    dig1 = 10;
    dig2 = 2;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 39) {
    dig1 = 10;
    dig2 = 1;
    dig3 = 5;
    dig4 = 12;
  }
  else if (ss == 40) {
    dig1 = 10;
    dig2 = 1;
    dig3 = 3;
    dig4 = 12;
  }
  else if (ss == 41) {
    dig1 = 10;
    dig2 = 1;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 42) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 8;
    dig4 = 12;
  }
  else if (ss == 43) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 6;
    dig4 = 12;
  }
  else if (ss == 44) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 5;
    dig4 = 12;
  }
  else if (ss == 45) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 4;
    dig4 = 12;
  }
  else if (ss == 46) {
    dig1 = 10;
    dig2 = 300;
    dig3 = 2;
    dig4 = 12;
  }
  else if (ss == 47) {
    dig1 = 10;
    dig2 = 200;
    dig3 = 5;
    dig4 = 12;
  }
  else if (ss == 48) {
    dig1 = 10;
    dig2 = 200;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 49) {
    dig1 = 10;
    dig2 = 100;
    dig3 = 6;
    dig4 = 12;
  }
  else if (ss == 50) {
    dig1 = 10;
    dig2 = 100;
    dig3 = 3;
    dig4 = 12;
  }
  else if (ss == 51) {
    dig1 = 10;
    dig2 = 100;
    dig3 = 0;
    dig4 = 12;
  }
  else if (ss == 52) {
    dig1 = 10;
    dig2 = 1000;
    dig3 = 8;
    dig4 = 12;
  }
  else if (ss == 53) {
    dig1 = 10;
    dig2 = 1000;
    dig3 = 6;
    dig4 = 12;
  }
  else if (ss == 54) {
    dig1 = 10;
    dig2 = 1000;
    dig3 = 5;
    dig4 = 12;
  }
  else if (ss == 55) {
    dig1 = 10;
    dig2 = 1000;
    dig3 = 4;
    dig4 = 12;
  }
  else if (ss == 56) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 10;
    dig4 = 3;
  }
  else if (ss == 57) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 10;
    dig4 = 4;
  }
  else if (ss == 58) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 10;
    dig4 = 5;
  }
  else if (ss == 59) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 10;
    dig4 = 6;
  }
  else if (ss == 60) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 10;
    dig4 = 8;
  }
  else if (ss == 61) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 1;
    dig4 = 0;
  }
  else if (ss == 62) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 1;
    dig4 = 3;
  }
  else if (ss == 63) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 1;
    dig4 = 5;
  }
  else if (ss == 64) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 2;
    dig4 = 0;
  }
  else if (ss == 65) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 2;
    dig4 = 5;
  }
  else if (ss == 66) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 3;
    dig4 = 0;
  }
  else if (ss == 67) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 4;
    dig4 = 0;
  }
  else if (ss == 68) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 5;
    dig4 = 0;
  }
  else if (ss == 69) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 6;
    dig4 = 0;
  }
  else if (ss == 70) {
    dig1 = 10;
    dig2 = 10;
    dig3 = 8;
    dig4 = 0;
  }
  else if (ss == 71) {
    dig1 = 10;
    dig2 = 1;
    dig3 = 0;
    dig4 = 0;
  }
  else if (ss == 72) {
    dig1 = 10;
    dig2 = 1;
    dig3 = 2;
    dig4 = 5;
  }

  // print
  for ( int select_DIG = 1; select_DIG <= 4; select_DIG++ ) {

    // DIG 1
    if ( select_DIG == 1 ) {

      // edit byte
      pat1[0] = {B10000000};
      pat2[0] = {B10000000};
      pat3[0] = {B10000000};
      pat4[0] = {B10000000};
      pat5[0] = {B10000000};
      pat6[0] = {B10000000};
      pat7[0] = {B10000000};
      pat8[0] = {B10000000};
      pat9[0] = {B10000000};
      pat0[0] = {B10000000};
      patBlank[0] = {B00000000};
      patDevide1[0] = {B10000000};
      patSecond[0] = {B10000000};
      pat100[0] = {B01000000};
      pat200[0] = {B01000000};
      pat300[0] = {B01000000};
      pat1000[0] = {B01000000};

      // print
      if ( dig1 == 1 ) prt1();
      else if ( dig1 == 2 ) prt2();
      else if ( dig1 == 3 ) prt3();
      else if ( dig1 == 4 ) prt4();
      else if ( dig1 == 5 ) prt5();
      else if ( dig1 == 6 ) prt6();
      else if ( dig1 == 7 ) prt7();
      else if ( dig1 == 8 ) prt8();
      else if ( dig1 == 9 ) prt9();
      else if ( dig1 == 0 ) prt0();
      else if ( dig1 == 10 ) prtBlank();
      else if ( dig1 == 11 ) prtDevide1();
      else if ( dig1 == 12 ) prtSecond();

      delay(2);

    }

    // DIG 2
    else if ( select_DIG == 2 ) {

      // edit byte
      pat1[0] = {B01000000};
      pat2[0] = {B01000000};
      pat3[0] = {B01000000};
      pat4[0] = {B01000000};
      pat5[0] = {B01000000};
      pat6[0] = {B01000000};
      pat7[0] = {B01000000};
      pat8[0] = {B01000000};
      pat9[0] = {B01000000};
      pat0[0] = {B01000000};
      patBlank[0] = {B00000000};
      patDevide1[0] = {B01000000};
      patSecond[0] = {B01000000};
      pat100[0] = {B01000000};
      pat200[0] = {B01000000};
      pat300[0] = {B01000000};
      pat1000[0] = {B01000000};

      // print
      if ( dig2 == 1 ) prt1();
      else if ( dig2 == 2 ) prt2();
      else if ( dig2 == 3 ) prt3();
      else if ( dig2 == 4 ) prt4();
      else if ( dig2 == 5 ) prt5();
      else if ( dig2 == 6 ) prt6();
      else if ( dig2 == 7 ) prt7();
      else if ( dig2 == 8 ) prt8();
      else if ( dig2 == 9 ) prt9();
      else if ( dig2 == 0 ) prt0();
      else if ( dig2 == 10 ) prtBlank();
      else if ( dig2 == 11 ) prtDevide1();
      else if ( dig2 == 12 ) prtSecond();
      else if ( dig2 == 300 ) prt300();
      else if ( dig2 == 200 ) prt200();
      else if ( dig2 == 100 ) prt100();
      else if ( dig2 == 1000 ) prt1000();

      delay(2);

    }

    // DIG 3
    else if ( select_DIG == 3 ) {

      // edit byte
      pat1[0] = {B00100000};
      pat2[0] = {B00100000};
      pat3[0] = {B00100000};
      pat4[0] = {B00100000};
      pat5[0] = {B00100000};
      pat6[0] = {B00100000};
      pat7[0] = {B00100000};
      pat8[0] = {B00100000};
      pat9[0] = {B00100000};
      pat0[0] = {B00100000};
      patBlank[0] = {B00000000};
      patDevide1[0] = {B00100000};
      patSecond[0] = {B00100000};
      pat100[0] = {B00100000};
      pat200[0] = {B00100000};
      pat300[0] = {B00100000};
      pat1000[0] = {B00100000};

      // print
      if ( dig3 == 1 ) prt1();
      else if ( dig3 == 2 ) prt2();
      else if ( dig3 == 3 ) prt3();
      else if ( dig3 == 4 ) prt4();
      else if ( dig3 == 5 ) prt5();
      else if ( dig3 == 6 ) prt6();
      else if ( dig3 == 7 ) prt7();
      else if ( dig3 == 8 ) prt8();
      else if ( dig3 == 9 ) prt9();
      else if ( dig3 == 0 ) prt0();
      else if ( dig3 == 10 ) prtBlank();
      else if ( dig3 == 11 ) prtDevide1();
      else if ( dig3 == 12 ) prtSecond();

      delay(2);

    }

    // DIG4
    else if ( select_DIG == 4 ) {

      // edit byte
      pat1[0] = {B00010000};
      pat2[0] = {B00010000};
      pat3[0] = {B00010000};
      pat4[0] = {B00010000};
      pat5[0] = {B00010000};
      pat6[0] = {B00010000};
      pat7[0] = {B00010000};
      pat8[0] = {B00010000};
      pat9[0] = {B00010000};
      pat0[0] = {B00010000};
      patBlank[0] = {B00000000};
      patDevide1[0] = {B00010000};
      patSecond[0] = {B00010000};
      pat100[0] = {B00010000};
      pat200[0] = {B00010000};
      pat300[0] = {B00010000};
      pat1000[0] = {B00010000};

      // print
      if ( dig4 == 1 ) prt1();
      else if ( dig4 == 2 ) prt2();
      else if ( dig4 == 3 ) prt3();
      else if ( dig4 == 4 ) prt4();
      else if ( dig4 == 5 ) prt5();
      else if ( dig4 == 6 ) prt6();
      else if ( dig4 == 7 ) prt7();
      else if ( dig4 == 8 ) prt8();
      else if ( dig4 == 9 ) prt9();
      else if ( dig4 == 0 ) prt0();
      else if ( dig4 == 10 ) prtBlank();
      else if ( dig4 == 11 ) prtDevide1();
      else if ( dig4 == 12 ) prtSecond();
    }

    delay(2);

  }

}


/* print function */

void prt1() {
  for (unsigned int pat = 0; pat < pat1_len * SREG_NUM; pat += SREG_NUM) {  //1
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat1[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt2() {
  for (unsigned int pat = 0; pat < pat2_len * SREG_NUM; pat += SREG_NUM) {  //2
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat2[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt3() {
  for (unsigned int pat = 0; pat < pat3_len * SREG_NUM; pat += SREG_NUM) {  //3
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat3[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt4() {
  for (unsigned int pat = 0; pat < pat4_len * SREG_NUM; pat += SREG_NUM) {  //4
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat4[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt5() {
  for (unsigned int pat = 0; pat < pat5_len * SREG_NUM; pat += SREG_NUM) {  //5
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat5[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt6() {
  for (unsigned int pat = 0; pat < pat6_len * SREG_NUM; pat += SREG_NUM) {  //6
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat6[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt7() {
  for (unsigned int pat = 0; pat < pat7_len * SREG_NUM; pat += SREG_NUM) {  //7
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat7[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt8() {
  for (unsigned int pat = 0; pat < pat8_len * SREG_NUM; pat += SREG_NUM) {  //8
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat8[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt9() {
  for (unsigned int pat = 0; pat < pat9_len * SREG_NUM; pat += SREG_NUM) {  //9
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat9[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt0() {
  for (unsigned int pat = 0; pat < pat0_len * SREG_NUM; pat += SREG_NUM) {  //0
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat0[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prtBlank() {
  for (unsigned int pat = 0; pat < patBlank_len * SREG_NUM; pat += SREG_NUM) {  //Blank
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(patBlank[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prtDevide1() {
  for (unsigned int pat = 0; pat < patDevide1_len * SREG_NUM; pat += SREG_NUM) {  //Devide1
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(patDevide1[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prtSecond() {
  for (unsigned int pat = 0; pat < patSecond_len * SREG_NUM; pat += SREG_NUM) {  //Second
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(patSecond[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt100() {
  for (unsigned int pat = 0; pat < pat100_len * SREG_NUM; pat += SREG_NUM) {  //Second
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat100[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt200() {
  for (unsigned int pat = 0; pat < pat200_len * SREG_NUM; pat += SREG_NUM) {  //Second
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat200[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt300() {
  for (unsigned int pat = 0; pat < pat300_len * SREG_NUM; pat += SREG_NUM) {  //Second
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat300[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
void prt1000() {
  for (unsigned int pat = 0; pat < pat1000_len * SREG_NUM; pat += SREG_NUM) {  //Second
    digitalWrite(SV, LOW);
    for (unsigned int sr = 0; sr < SREG_NUM; sr++) {
      SPI.transfer(pat1000[pat + sr]);
    }
    digitalWrite(SV, HIGH);
    delayMicroseconds(100);
  }
}
