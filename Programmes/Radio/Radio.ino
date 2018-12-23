// TEA5767 Example

#include <Wire.h>
#include <TEA5767Radio.h>

TEA5767Radio radio = TEA5767Radio();

#define pFreq A0

float sData;
float freq;
float oldPFreq;
float oldSData;

void setup() { 

  pinMode(pFreq, INPUT);
  
  Wire.begin();
  Serial.begin(9600);
  
}


void loop() {

  potar();
  serial(); 
  radio.setFrequency(freq);
  
}


void potar() {

  if (((oldPFreq + 1) or (oldPFreq - 1) or (oldPFreq)) != analogRead(pFreq)) {
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
