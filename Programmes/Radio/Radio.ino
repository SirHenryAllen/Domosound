// TEA5767 Example

#include <Wire.h>
#include <TEA5767Radio.h>

TEA5767Radio radio = TEA5767Radio();

float sData;
float freq;

void setup() { 
  
  Wire.begin();
  Serial.begin(9600);
  
}

void loop() {

  sData = Serial.read();
  freq = sData;
  radio.setFrequency(freq);
  
}
