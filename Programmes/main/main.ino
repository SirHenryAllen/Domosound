#define eGLRB 22
#define eDLRB 23
#define eGSM 24
#define eDSM 25
#define eGLREa 26
#define eDLREa 27
#define eGLREb 28
#define eDLREb 29

#define eLRBS 30
#define eSMS 31
#define eLREaS 32
#define eLREbS 33

#define ledUn 34
#define ledDeux 35
#define ledTrois 36
#define ledQuatre 37

#define signalOne 38
#define signalTwo 39
#define signalThree 40
#define signalFor 41



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

  pinMode(ledUn, OUTPUT);
  pinMode(ledDeux, OUTPUT);
  pinMode(ledTrois, OUTPUT);
  pinMode(ledQuatre, OUTPUT);

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
    digitalWrite(ledUn, HIGH);
  }
  if (bDeux == 1) {
    digitalWrite(eGSM, HIGH);
    digitalWrite(eDSM, HIGH);
    digitalWrite(ledDeux, HIGH);
  }
  if (bTrois == 1) {
    digitalWrite(eGLREa, HIGH);
    digitalWrite(eDLREa, HIGH);
    digitalWrite(ledTrois, HIGH);
  }
  if (bQuatre == 1) {
    digitalWrite(eGLREb, HIGH);
    digitalWrite(eDLREb, HIGH);
    digitalWrite(ledQuatre, HIGH);
  }

  if (bUn == 0) {
    digitalWrite(eGLRB, LOW);
    digitalWrite(eDLRB, LOW);
    digitalWrite(ledUn, LOW);
  }
  if (bDeux == 0) {
    digitalWrite(eGSM, LOW);
    digitalWrite(eDSM, LOW);
    digitalWrite(ledDeux, LOW);
  }
  if (bTrois == 0) {
    digitalWrite(eGLREa, LOW);
    digitalWrite(eDLREa, LOW);
    digitalWrite(ledTrois, LOW);
  }
  if (bQuatre == 0) {
    digitalWrite(eGLREb, LOW);
    digitalWrite(eDLREb, LOW);
    digitalWrite(ledQuatre, LOW);
  }
  
}
