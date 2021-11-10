const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;
const int buzzerPin = 12;
const int antenaPin = A0;

const int segSize = 8;

int buzzerTone = 200;
int toneDelay = 300;

int antenaCatch = 0;


int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};
bool dpState = HIGH;
int index  = 0;

const int noOfDigits = 10;

bool digitMatrix[noOfDigits][segSize] = {
 {1, 1, 1, 1, 1, 1, 0}, //0
 {0, 1, 1, 0, 0, 0, 0}, // 1
 {1, 1, 0, 1, 1, 0, 1}, // 2
 {1, 1, 1, 1, 0, 0, 1}, // 3
 {0, 1, 1, 0, 0, 1, 1}, // 4
 {1, 0, 1, 1, 0, 1, 1}, //5
 {1, 0, 1, 1, 1, 1, 1}, // 6
 {1, 1, 1, 0, 0, 0, 0}, // 7
 {1, 1, 1, 1, 1, 1, 1}, // 8
 {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber(int digit, bool decimalPoint){
  for(int i = 0; i < segSize; i++){
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(pinDP, dpState);
}
void setup() {
  for( int i = 0; i < segSize; i++){
    pinMode(segments[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(antenaPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 antenaCatch = analogRead(antenaPin);
 if (antenaCatch >= 1){
  antenaCatch = constrain(antenaCatch, 1, 9); 
  Serial.println(antenaCatch);
  tone(buzzerPin, antenaCatch * buzzerTone, toneDelay);
  displayNumber(antenaCatch, dpState);
 }
 else{
  displayNumber(0, dpState);
 }
 delay(300);
}
