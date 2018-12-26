#define eGLRB 7       //
#define eDLRB 8       //
#define eGSM 9        //
#define eDSM 10       //  Sound output
#define eGLREa 11     //      pins
#define eDLREa 12     //
#define eGLREb 13     //
#define eDLREb 14     //

#define eLRBS 15      //
#define eSMS 16       //  Reading pins 
#define eLREaS 17     //  speakers groups
#define eLREbS 18     //

#define ledOne 19     //
#define ledTwo 20     //  Pins LEDs 
#define ledThree 21   //  speaakers groupes
#define ledFor 22     //

#define signalOne 23      //
#define signalTwo 24      //  Pins reading
#define signalThree 25    //  signal choice 
#define signalFor 26      //

#define cSignalOne 27     //
#define cSignalTwo 28     //  Pins command
#define cSignalThree 29   //  signal choice
#define cSignalFor 30     //


int bOne = 0;
int bTwo = 0;
int bThree = 0;
int bFor = 0;

int sOne = 0;
int sTwo = 0;
int sThree = 0;
int sFor = 0;

int sData;

void setup() {
  
  pinMode(eGLRB, OUTPUT);
  pinMode(eDLRB, OUTPUT);
  pinMode(eGSM, OUTPUT);
  pinMode(eDSM, OUTPUT);
  pinMode(eGLREa, OUTPUT);
  pinMode(eDLREa, OUTPUT);
  pinMode(eGLREb, OUTPUT);
  pinMode(eDLREb, OUTPUT);

  pinMode(eLRBS, INPUT_PULLUP);
  pinMode(eSMS, INPUT_PULLUP);
  pinMode(eLREaS, INPUT_PULLUP);
  pinMode(eLREbS, INPUT_PULLUP);

  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(ledFor, OUTPUT);

  pinMode(signalOne, INPUT);
  pinMode(signalTwo, INPUT);
  pinMode(signalThree, INPUT);
  pinMode(signalFor, INPUT);

  pinMode(cSignalOne, OUTPUT);
  pinMode(cSignalTwo, OUTPUT);
  pinMode(cSignalThree, OUTPUT);
  pinMode(cSignalFor, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

  speakersCom();
  speakersGroup();

}


void speakersCom() {

  sData = Serial.read();
  
  if (((digitalRead(eLRBS)) == 0) or (sData == 1)) {
    bOne = bOne + 1;
    if (bOne == 2) {
      bOne = 0;
    }
  }
  if (((digitalRead(eSMS)) == 0) or (sData == 2)) {
    bTwo = bTwo + 1;
    if (bTwo == 2) {
      bTwo = 0;
    }
  }
  if (((digitalRead(eLREaS)) == 0) or (sData == 3)) {
    bThree = bThree + 1;
    if (bThree == 2) {
      bThree = 0;
    }
  }
  if (((digitalRead(eLREbS)) == 0) or (sData == 4)) {
    bFor = bFor + 1;
    if (bFor == 2) {
      bFor = 0;
    }
  }

  if (bOne == 1) {
    digitalWrite(eGLRB, HIGH);
    digitalWrite(eDLRB, HIGH);
    digitalWrite(ledOne, HIGH);
  }
  if (bTwo == 1) {
    digitalWrite(eGSM, HIGH);
    digitalWrite(eDSM, HIGH);
    digitalWrite(ledTwo, HIGH);
  }
  if (bThree == 1) {
    digitalWrite(eGLREa, HIGH);
    digitalWrite(eDLREa, HIGH);
    digitalWrite(ledThree, HIGH);
  }
  if (bFor == 1) {
    digitalWrite(eGLREb, HIGH);
    digitalWrite(eDLREb, HIGH);
    digitalWrite(ledFor, HIGH);
  }

  if (bOne == 0) {
    digitalWrite(eGLRB, LOW);
    digitalWrite(eDLRB, LOW);
    digitalWrite(ledOne, LOW);
  }
  if (bTwo == 0) {
    digitalWrite(eGSM, LOW);
    digitalWrite(eDSM, LOW);
    digitalWrite(ledTwo, LOW);
  }
  if (bThree == 0) {
    digitalWrite(eGLREa, LOW);
    digitalWrite(eDLREa, LOW);
    digitalWrite(ledThree, LOW);
  }
  if (bFor == 0) {
    digitalWrite(eGLREb, LOW);
    digitalWrite(eDLREb, LOW);
    digitalWrite(ledFor, LOW);
  }
  
}


void speakersGroup() {

  sData = Serial.read();
  
}
