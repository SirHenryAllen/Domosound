#define eGLRB 22       //
#define eDLRB 23       //
#define eGSM 24        //
#define eDSM 25       //  Sound output
#define eGLREa 26     //      pins
#define eDLREa 27     //
#define eGLREb 28     //
#define eDLREb 29     //

#define eLRBS 30      //
#define eSMS 31       //  Reading pins 
#define eLREaS 32     //  speakers groups
#define eLREbS 33     //

#define ledOne 34     //
#define ledTwo 35     //  Pins LEDs 
#define ledThree 36   //  speaakers groupes
#define ledFor 37     //

#define signalOne 38      //
#define signalTwo 39      //  Pins reading
#define signalThree 40    //  signal choice 
#define signalFor 41      //

#define cSignalOne 42     //
#define cSignalTwo 43     //  Pins command
#define cSignalThree 44   //  signal choice
#define cSignalFor 45     //


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
