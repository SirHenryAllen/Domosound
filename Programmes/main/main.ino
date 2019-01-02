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
#define ledThree 21   //  speakers groupes
#define ledFor 22     //

#define signalOne 23      //
#define signalTwo 24      //  Pins reading
#define signalThree 25    //  signal choice 
#define signalFor 26      //

#define cSignalOne 27     //
#define cSignalTwo 28     //  Pins command
#define cSignalThree 29   //  signal choice
#define cSignalFor 30     //

#define sLedOne 31        //
#define sLedTwo 32        //  Pins LEDs
#define sLedThree 33      //  signal
#define sLedFor 34        //


int bOne = 0;
int bTwo = 0;
int bThree = 0;
int bFor = 0;

int sOne = 0;
int sTwo = 0;
int sThree = 0;
int sFor = 0;

unsigned char sData;

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

  pinMode(sLedOne, OUTPUT);
  pinMode(sLedTwo, OUTPUT);
  pinMode(sLedThree, OUTPUT);
  pinMode(sLedFor, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

  speakersCom();
  signall();

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
    Serial.println("Ground floor living room speakers : ON");
  }
  if (bTwo == 1) {
    digitalWrite(eGSM, HIGH);
    digitalWrite(eDSM, HIGH);
    digitalWrite(ledTwo, HIGH);
    Serial.println("Dining room speakers : ON");
  }
  if (bThree == 1) {
    digitalWrite(eGLREa, HIGH);
    digitalWrite(eDLREa, HIGH);
    digitalWrite(ledThree, HIGH);
    Serial.println("First floor living room speakers a : ON");
  }
  if (bFor == 1) {
    digitalWrite(eGLREb, HIGH);
    digitalWrite(eDLREb, HIGH);
    digitalWrite(ledFor, HIGH);
    Serial.println("First floor living room speakers b : ON");
  }

  if (bOne == 0) {
    digitalWrite(eGLRB, LOW);
    digitalWrite(eDLRB, LOW);
    digitalWrite(ledOne, LOW);
    Serial.println("Ground floor living room speakers : OFF");
  }
  if (bTwo == 0) {
    digitalWrite(eGSM, LOW);
    digitalWrite(eDSM, LOW);
    digitalWrite(ledTwo, LOW);
    Serial.println("Dining room speakers : OFF");
  }
  if (bThree == 0) {
    digitalWrite(eGLREa, LOW);
    digitalWrite(eDLREa, LOW);
    digitalWrite(ledThree, LOW);
    Serial.println("First floor living room speakers a : OFF");
  }
  if (bFor == 0) {
    digitalWrite(eGLREb, LOW);
    digitalWrite(eDLREb, LOW);
    digitalWrite(ledFor, LOW);
    Serial.println("First floor living room speakers b : OFF");
  }
  
}


void signall() {

  sData = Serial.read();

  if (((digitalRead(signalOne)) == 0) or (sData == 5)) {
    sOne = sOne + 1;
    if (sOne == 2) {
      sOne = 0;
    }
  }
   if (((digitalRead(signalTwo)) == 0) or (sData == 6)) {
    sTwo = sTwo + 1;
    if (sTwo == 2) {
      sTwo = 0;
    }
  }
  if (((digitalRead(signalThree)) == 0) or (sData == 7)) {
    sThree = sThree + 1;
    if (sThree == 2) {
      sThree = 0;
    }
  }  
  if (((digitalRead(signalFor)) == 0) or (sData == 8)) {
    sFor = sFor + 1;
    if (sFor == 2) {
      sFor = 0;
    }
  }

  if (sOne == 1) {
    sTwo = 0;
    sThree = 0;
    sFor = 0;
  }
  if (sTwo == 1) {
    sOne = 0;
    sThree = 0;
    sFor = 0;
  }
  if (sThree == 1) {
    sOne = 0;
    sTwo = 0;
    sFor = 0;
  }
  if (sFor == 1) {
    sOne = 0;
    sTwo = 0;
    sThree = 0;
  }

  if (sOne == 1) {
    digitalWrite(cSignalOne, HIGH);
    digitalWrite(cSignalTwo, LOW);
    digitalWrite(cSignalThree, LOW);
    digitalWrite(cSignalFor, LOW);
    
    digitalWrite(sLedOne, HIGH);
    digitalWrite(sLedTwo, LOW);
    digitalWrite(sLedThree, LOW);
    digitalWrite(sLedFor, LOW);

    Serial.println("Signal One : Reading");
  }
  if (sTwo == 1) {
    digitalWrite(cSignalOne, LOW);
    digitalWrite(cSignalTwo, HIGH);
    digitalWrite(cSignalThree, LOW);
    digitalWrite(cSignalFor, LOW);
    
    digitalWrite(sLedOne, LOW);
    digitalWrite(sLedTwo, HIGH);
    digitalWrite(sLedThree, LOW);
    digitalWrite(sLedFor, LOW);

    Serial.println("Signal Two : Reading");
  }
  if (sThree == 1) {
    digitalWrite(cSignalOne, LOW);
    digitalWrite(cSignalTwo, LOW);
    digitalWrite(cSignalThree, HIGH);
    digitalWrite(cSignalFor, LOW);

    digitalWrite(sLedOne, LOW);
    digitalWrite(sLedTwo, LOW);
    digitalWrite(sLedThree, HIGH);
    digitalWrite(sLedFor, LOW);

    Serial.println("Signal Three : Reading");
  }
  if (sFor == 1) {
    digitalWrite(cSignalOne, LOW);
    digitalWrite(cSignalTwo, LOW);
    digitalWrite(cSignalThree, LOW);
    digitalWrite(cSignalFor, HIGH);

    digitalWrite(sLedOne, LOW);
    digitalWrite(sLedTwo, LOW);
    digitalWrite(sLedThree, LOW);
    digitalWrite(sLedFor, HIGH);

    Serial.println("Signal For : Reading");
  }

  if (sOne == 0) {
    digitalWrite(cSignalOne, LOW);
    digitalWrite(sLedOne, LOW);
  }
  if (sTwo == 0) {
    digitalWrite(cSignalTwo, LOW);
    digitalWrite(sLedTwo, LOW);
  }
  if (sThree == 0) {
    digitalWrite(cSignalThree, LOW);
    digitalWrite(sLedThree, LOW);
  }
  if (sFor == 0) {
    digitalWrite(cSignalFor, LOW);
    digitalWrite(sLedFor, LOW);
  }
}
