#define rdcUn 44           //
#define rdcDeux 45         //  lecture pins
#define etageUn 42         //  groupe d'enceintes
#define etageDeux 43       //

#define signalOne 48       //
#define signalTwo 49       //  Pins lecture
#define signalThree 46     //  choix signal   
#define signalFor 47       //

char sData;

void setup() {
  pinMode(rdcUn, INPUT_PULLUP);
  pinMode(rdcDeux, INPUT_PULLUP);
  pinMode(etageUn, INPUT_PULLUP);
  pinMode(etageDeux, INPUT_PULLUP);

  pinMode(signalOne, INPUT_PULLUP);
  pinMode(signalTwo, INPUT_PULLUP);
  pinMode(signalThree, INPUT_PULLUP);
  pinMode(signalFor, INPUT_PULLUP);

  Serial.begin(9600);
  sData = Serial.read();

  Serial.println("Check serial");
}

void loop() {
  sData = Serial.read();
  if (sData == '1') {
    Serial.println(digitalRead(rdcUn));
  }
  if (sData == '2') {
    Serial.println(digitalRead(rdcDeux));
  }
  if (sData == '3') {
    Serial.println(digitalRead(etageUn));
  }
  if (sData == '4') {
    Serial.println(digitalRead(etageDeux));
  }
  if (sData == '5') {
    Serial.println(digitalRead(signalOne));
  }
  if (sData == '6') {
    Serial.println(digitalRead(signalTwo));
  }
  if (sData == '7') {
    Serial.println(digitalRead(signalThree));
  }
  if (sData == '8') {
    Serial.println(digitalRead(signalFor));
  }
}
