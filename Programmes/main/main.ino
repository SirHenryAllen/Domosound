#define eGSalonB 7
#define eDSalonB 8
#define eGSM 9
#define eDSM 10
#define eGSalonEa 11
#define eDSalonEa 12
#define eGSalonEb 13
#define eDSalonEb 14

#define eSalonBS 15
#define eSMS 16
#define eSalonEaS 17
#define eSalonEbS 28

int bUn = 0;
int bDeux = 0;
int bTrois = 0;
int bQuatre = 0;

int sData;

void setup() {
  
  pinMode(eGSalonB, HIGH);
  pinMode(eDSalonB, HIGH);
  pinMode(eGSM, HIGH);
  pinMode(eDSM, HIGH);
  pinMode(eGSalonEa, HIGH);
  pinMode(eDSalonEa, HIGH);
  pinMode(eGSalonEb, HIGH);
  pinMode(eDSalonEb, HIGH);

  pinMode(eSalonBS, INPUT_PULLUP);
  pinMode(eSMS, INPUT_PULLUP);
  pinMode(eSalonEaS, INPUT_PULLUP);
  pinMode(eSalonEbS, INPUT_PULLUP);

  Serial.begin(9600);
  
}

void loop() {

  sData = Serial.read();
  
  if (((digitalRead(eSalonBS)) == 0) or (sData == 1)) {
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
  if (((digitalRead(eSalonEaS)) == 0) or (sData == 3)) {
    bTrois = bTrois + 1;
    if (bTrois == 2) {
      bTrois = 0;
    }
  }
  if (((digitalRead(eSalonEbS)) == 0) or (sData == 4)) {
    bQuatre = bQuatre + 1;
    if (bQuatre == 2) {
      bQuatre = 0;
    }
  }

}
