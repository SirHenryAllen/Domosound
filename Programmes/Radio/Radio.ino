#include <Wire.h>
#include <TEA5767Radio.h>

TEA5767Radio radio = TEA5767Radio();

#define pFreq A0
#define fav 7

float sData;
float freq;
float oldPFreq;
float oldSData;
float favo [10];

int t = 0;

void setup() { 

  pinMode(pFreq, INPUT);
  pinMode(fav, INPUT_PULLUP);
  
  Wire.begin();
  Serial.begin(9600);
  
}


void loop() {

  potar();
  serial(); 
  radio.setFrequency(freq);
  favorite();
  
}


void potar() {

  if ((((oldPFreq + 1) or (oldPFreq - 1) or (oldPFreq))) != analogRead(pFreq)) {
     freq = ((analogRead(pFreq))/1023)*110;
  }
  
  oldPFreq = analogRead(pFreq);

}


void serial() {

  sData = Serial.read();
  
  if (oldSData != sData) {
    freq = sData;
  }
  
  oldSData = analogRead(sData);
  
}


void favorite() {

  if ((digitalRead(fav)) == 0) {
      favo[t] = freq;
      t = t+1;
  }
}
