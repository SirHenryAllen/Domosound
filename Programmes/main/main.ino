#define eGLRB 7
#define eDLRB 8
#define eGSM 9
#define eDSM 10
#define eGLREa 11
#define eDLREa 12
#define eGLREb 13
#define eDLREb 14

#define eLRBS 15
#define eSMS 16
#define eLREaS 17
#define eLREbS 18

#define ledOne 19
#define ledTwo 20
#define ledThree 21
#define ledFor 22

#define signalOne 23
#define signalTwo 24
#define signalThree 25
#define signalFor 26



int bUn = 0;
int bDeux = 0;
int bTrois = 0;
int bQuatre = 0;

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

  pinMode(signalOne, OUTPUT);
  pinMode(signalTwo, OUTPUT);
  pinMode(signalThree, OUTPUT);
  pinMode(signalFor, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

  sData = Serial.read();
  
  if (((digitalRead(eLRBS)) == 0) or (sData == 1)) {
    bUn = bUn + 1;
    if (bUn == 2) {
      bUn = 0;
    }
  }
  if (((digitalRead(eSMS)) == 0) or (sData == 2)) {
    bDeux = bDeux + 1;
    if (bDeux == 2) {
      bDeux = 0;
    }
  }
  if (((digitalRead(eLREaS)) == 0) or (sData == 3)) {
    bTrois = bTrois + 1;
    if (bTrois == 2) {
      bTrois = 0;
    }
  }
  if (((digitalRead(eLREbS)) == 0) or (sData == 4)) {
    bQuatre = bQuatre + 1;
    if (bQuatre == 2) {
      bQuatre = 0;
    }
  }

  if (bUn == 1) {
    digitalWrite(eGLRB, HIGH);
    digitalWrite(eDLRB, HIGH);
    digitalWrite(ledOne, HIGH);
  }
  if (bDeux == 1) {
    digitalWrite(eGSM, HIGH);
    digitalWrite(eDSM, HIGH);
    digitalWrite(ledTwo, HIGH);
  }
  if (bTrois == 1) {
    digitalWrite(eGLREa, HIGH);
    digitalWrite(eDLREa, HIGH);
    digitalWrite(ledThree, HIGH);
  }
  if (bQuatre == 1) {
    digitalWrite(eGLREb, HIGH);
    digitalWrite(eDLREb, HIGH);
    digitalWrite(ledFor, HIGH);
  }

  if (bUn == 0) {
    digitalWrite(eGLRB, LOW);
    digitalWrite(eDLRB, LOW);
    digitalWrite(ledOne, LOW);
  }
  if (bDeux == 0) {
    digitalWrite(eGSM, LOW);
    digitalWrite(eDSM, LOW);
    digitalWrite(ledTwo, LOW);
  }
  if (bTrois == 0) {
    digitalWrite(eGLREa, LOW);
    digitalWrite(eDLREa, LOW);
    digitalWrite(ledThree, LOW);
  }
  if (bQuatre == 0) {
    digitalWrite(eGLREb, LOW);
    digitalWrite(eDLREb, LOW);
    digitalWrite(ledFor, LOW);
  }
  
}
