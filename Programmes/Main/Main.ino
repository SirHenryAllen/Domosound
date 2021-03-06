#define rdcUnG 22          //
#define rdcUnD 23          //
#define rdcDeuxG 24        //
#define rdcDeuxD 25        //  Pins sortie
#define etageUnG 26        //      son
#define etageUnD 27        //
#define etageDeuxG 28      //
#define etageDeuxD 29      //

#define rdcUn 44           //
#define rdcDeux 45         //  lecture pins
#define etageUn 42         //  groupe d'enceintes
#define etageDeux 43       //

#define signalOne 48       //
#define signalTwo 49       //  Pins lecture
#define signalThree 46     //  choix signal   
#define signalFor 47       //

#define cSignalOneR 50     //
#define cSignalTwoR 51     //  
#define cSignalThreeR 52   //  
#define cSignalForR 53     //  Pins commande
#define cSignalOneL 7      //  choix signal
#define cSignalTwoL 6      //
#define cSignalThreeL 5    //
#define cSignalForL 4      //

#define cLedOne 31         //
#define cLedTwo 32         //  Pins LEDs
#define cLedThree 33       //  choix signal
#define cLedFor 34         //

#define oLedOne 35         //
#define oLedTwo 36         //  Pins LEDs
#define oLedThree 37       //  enceintes témoin
#define oLedFor 38         //

#define relaisJack 39
#define switchJack 40
#define cBluetooth 41

boolean debug = 0;

boolean signalOutput[4]; 
boolean ledOutput[4];
boolean ledInput[4];
boolean jackState;

char sData;

String b = "";

void setup() {
  pinMode(rdcUnG, OUTPUT);
  pinMode(rdcUnD, OUTPUT);
  pinMode(rdcDeuxG, OUTPUT);
  pinMode(rdcDeuxD, OUTPUT);
  pinMode(etageUnG, OUTPUT);
  pinMode(etageUnD, OUTPUT);
  pinMode(etageDeuxG, OUTPUT);
  pinMode(etageDeuxD, OUTPUT);

  pinMode(rdcUn, INPUT_PULLUP);
  pinMode(rdcDeux, INPUT_PULLUP);
  pinMode(etageUn, INPUT_PULLUP);
  pinMode(etageDeux, INPUT_PULLUP);

  pinMode(signalOne, INPUT_PULLUP);
  pinMode(signalTwo, INPUT_PULLUP);
  pinMode(signalThree, INPUT_PULLUP);
  pinMode(signalFor, INPUT_PULLUP);

  pinMode(cSignalOneR, OUTPUT);
  pinMode(cSignalTwoR, OUTPUT);
  pinMode(cSignalThreeR, OUTPUT);
  pinMode(cSignalForR, OUTPUT);
  pinMode(cSignalOneL, OUTPUT);
  pinMode(cSignalTwoL, OUTPUT);
  pinMode(cSignalThreeL, OUTPUT);
  pinMode(cSignalForL, OUTPUT);  

  pinMode(cLedOne, OUTPUT);
  pinMode(cLedTwo, OUTPUT);
  pinMode(cLedThree, OUTPUT);
  pinMode(cLedFor, OUTPUT);

  pinMode(oLedOne, OUTPUT);
  pinMode(oLedTwo, OUTPUT);
  pinMode(oLedThree, OUTPUT);
  pinMode(oLedFor, OUTPUT);
  
  pinMode(relaisJack, OUTPUT);
  pinMode(switchJack, INPUT);
  pinMode(cBluetooth, OUTPUT);

  
  Serial.begin(9600);
  sData = Serial.read();

  Serial.println("Check serial");

}

void checkBluetooth() {
  
  if (sData == 'o') {
    Serial.println("Activation bluetooth");
    digitalWrite(cBluetooth, HIGH);
    delay(5000);
    b = "bluetooth activé"; 
    Serial.println("Cooldown");
    digitalWrite(cBluetooth, LOW);
    delay(3000);
  }
  if (sData == 'e') {
    Serial.println("Extinction bluetooth");
    digitalWrite(cBluetooth, HIGH);
    delay(3000);
    b = "bluetooth désactivé";
    Serial.println("Cooldown");
    digitalWrite(cBluetooth, LOW);
    delay(3000);
  }
  if (sData == 'a') {
    Serial.println("Appairage bluetooth");
    digitalWrite(cBluetooth, HIGH);
    delay(7000);
    Serial.println("Cooldown");
    digitalWrite(cBluetooth, LOW);
    delay(3000);
    }
  }

void checkJackState() {
  if (sData == '/' /* or digitalRead(switchJack) */) {
    if (jackState) {
      jackState = false;
    } else {
        jackState = true;
    }
    appliJackState();
  }
}

void appliJackState() {
  if (jackState) {
    digitalWrite(relaisJack, HIGH); 
    Serial.println("Port jack rdc : entree");
  } else {
      digitalWrite(relaisJack, LOW);
      Serial.println("Port jack rdc : sortie");
  }
}

void checkLedOutput() {
  
  if (ledOutput[0]) {
    digitalWrite(oLedOne, HIGH); 
  } else {
      digitalWrite(oLedOne, LOW);
  }
  if (ledOutput[1]) {
    digitalWrite(oLedTwo, HIGH); 
  } else {
      digitalWrite(oLedTwo, LOW);
  } 
  if (ledOutput[2]) {
    digitalWrite(oLedThree, HIGH); 
  } else {
      digitalWrite(oLedThree, LOW);
  }
  if (ledOutput[3]) {
    digitalWrite(oLedFor, HIGH); 
  } else {
      digitalWrite(oLedFor, LOW);
  }
}

void checkLedInput() {
  if (ledInput[0]) {
    digitalWrite(cLedOne, HIGH); 
  } else {
      digitalWrite(cLedOne, LOW);
  }
  if (ledInput[1]) {
    digitalWrite(cLedTwo, HIGH); 
  } else {
      digitalWrite(cLedTwo, LOW);
  }
  if (ledInput[2]) {
    digitalWrite(cLedThree, HIGH); 
  } else {
      digitalWrite(cLedThree, LOW);
  }
  if (ledInput[3]) {
    digitalWrite(cLedFor, HIGH); 
  } else {
      digitalWrite(cLedFor, LOW);
  } 
}

void checkInput() {
  
  if (/* (digitalRead(signalOne)) == 1 or */ sData == '5') {
    digitalWrite(cSignalOneR, HIGH);
    digitalWrite(cSignalTwoR, LOW);  
    digitalWrite(cSignalThreeR, LOW);
    digitalWrite(cSignalForR, LOW);
    //
    digitalWrite(cSignalOneL, HIGH);
    digitalWrite(cSignalTwoL, LOW);  
    digitalWrite(cSignalThreeL, LOW);
    digitalWrite(cSignalForL, LOW);    
    ledInput[0] = 1;
    ledInput[1] = 0;
    ledInput[2] = 0;
    ledInput[3] = 0;
    Serial.println("Signal d'entree un : 1");
    Serial.println("Signal d'entree deux : 0");
    Serial.println("Signal d'entree trois : 0");
    Serial.println("Signal d'entree quatre : 0");
    Serial.println("----------------------------------");
  }
  if (/* (digitalRead(signalTwo)) == 1 or */ sData == '6') {
    digitalWrite(cSignalOneR, LOW);
    digitalWrite(cSignalTwoR, HIGH);  
    digitalWrite(cSignalThreeR, LOW);
    digitalWrite(cSignalForR, LOW);
    //
    digitalWrite(cSignalOneL, LOW);
    digitalWrite(cSignalTwoL, HIGH);  
    digitalWrite(cSignalThreeL, LOW);
    digitalWrite(cSignalForL, LOW);
    ledInput[0] = 0;
    ledInput[1] = 1;
    ledInput[2] = 0;
    ledInput[3] = 0;
    Serial.println("Signal d'entree un : 0");
    Serial.println("Signal d'entree deux : 1");
    Serial.println("Signal d'entree trois : 0");
    Serial.println("Signal d'entree quatre : 0");
    Serial.println("----------------------------------");
  }
  if (/* (digitalRead(signalThree)= == 1 or */ sData == '7') {
    digitalWrite(cSignalOneR, LOW);
    digitalWrite(cSignalTwoR, LOW);  
    digitalWrite(cSignalThreeR, HIGH);
    digitalWrite(cSignalForR, LOW);
    //
    digitalWrite(cSignalOneL, LOW);
    digitalWrite(cSignalTwoL, LOW);  
    digitalWrite(cSignalThreeL, HIGH);
    digitalWrite(cSignalForL, LOW);
    ledInput[0] = 0;
    ledInput[1] = 0;
    ledInput[2] = 1;
    ledInput[3] = 0;
    Serial.println("Signal d'entree un : 0");
    Serial.println("Signal d'entree deux : 0");
    Serial.println("Signal d'entree trois : 1");
    Serial.println("Signal d'entree quatre : 0");
    Serial.println("----------------------------------");
  }
  if (/* (digitalRead(signalFor)) == 1  or */ sData == '8') {
    digitalWrite(cSignalOneR, LOW);
    digitalWrite(cSignalTwoR, LOW);  
    digitalWrite(cSignalThreeR, LOW);
    digitalWrite(cSignalForR, HIGH);
    //
    digitalWrite(cSignalOneL, LOW);
    digitalWrite(cSignalTwoL, LOW);  
    digitalWrite(cSignalThreeL, LOW);
    digitalWrite(cSignalForL, HIGH);
    ledInput[0] = 0;
    ledInput[1] = 0;
    ledInput[2] = 0;
    ledInput[3] = 1;
    Serial.println("Signal d'entree un : 0");
    Serial.println("Signal d'entree deux : 0");
    Serial.println("Signal d'entree trois : 0");
    Serial.println("signal d'entree quatre : 1");
    Serial.println("----------------------------------");
  }
}

void checkOutput() {
  if (/* digitalRead(rdcUn) or */ sData == '1') {
    stateOutput(0);
  }
  if (/* digitalRead(rdcDeux) or */ sData == '2') {
    stateOutput(1);
  }
  if (/* digitalRead(etageUn) or */ sData == '3') {
    stateOutput(2);
  }
  if (/* digitalRead(etageDeux) or */ sData == '4') {
    stateOutput(3);
  }
}

void stateOutput (int x) {
  if (signalOutput[x]) {
    signalOutput[x] = false;
  } else {
    signalOutput[x] = true;
  }
  appliOutput();
}

void appliOutput() {
  if (signalOutput[0]) {
    digitalWrite(rdcUnG, HIGH);
    digitalWrite(rdcUnD, HIGH);
    ledOutput[0] = 1;
    Serial.print("rdcUn : ");
    Serial.println(signalOutput[0]);
  } else {
      digitalWrite(rdcUnG, LOW);
      digitalWrite(rdcUnD, LOW);
      ledOutput[0] = 0;
      Serial.print("rdcUn : ");
      Serial.println(signalOutput[0]);
  }
  
  if (signalOutput[1]) {
    digitalWrite(rdcDeuxG, HIGH);
    digitalWrite(rdcDeuxD, HIGH);
    ledOutput[1] = 1;
    Serial.print("rdcDeux : ");
    Serial.println(signalOutput[1]);
  } else {
      digitalWrite(rdcDeuxG, LOW);
      digitalWrite(rdcDeuxD, LOW);
      ledOutput[1] = 0;
      Serial.print("rdcDeux : ");
      Serial.println(signalOutput[1]);
  }
  
  if (signalOutput[2]) {
    digitalWrite(etageUnG, HIGH);
    digitalWrite(etageUnD, HIGH);
    ledOutput[2] = 1;
    Serial.print("etageUn : ");
    Serial.println(signalOutput[2]);
  } else {
      ledOutput[2] = 0;
      digitalWrite(etageUnG, LOW);
      digitalWrite(etageUnD, LOW);
      Serial.print("etageUn : ");
      Serial.println(signalOutput[2]);
  }
  
  if (signalOutput[3]) {
    ledOutput[3] = 1;
    digitalWrite(etageDeuxG, HIGH);
    digitalWrite(etageDeuxD, HIGH);
    Serial.print("etageDeux : ");
    Serial.println(signalOutput[3]);
  } else {
      ledOutput[3] = 0;
      Serial.print("etageDeux : ");
      Serial.println(signalOutput[3]);
      digitalWrite(etageDeuxG, LOW);
      digitalWrite(etageDeuxD, LOW);
  }
  Serial.println("----------------------------------");
}

void loop() {
  
  sData = Serial.read();
  
  checkOutput();
  checkInput();
  checkLedOutput();
  checkLedInput();
  checkJackState();
  checkBluetooth();
   
}
