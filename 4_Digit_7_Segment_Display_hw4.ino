#include <EEPROM.h>

const int dataPin = 12; // DS
const int latchPin = 11; // STCP
const int clockPin = 10; // SHCP

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

//joystick pins
const int swPin = 2;
const int xPin = A0;
const int yPin = A1;

const int displayCount = 4;
int displayDigits[] {
  segD1, segD2, segD3, segD4
};

bool swState = LOW;
bool prevSwState = LOW;
const int debounceTimer = 200;
volatile int lastBounce = 0;

int xPosition = 0;
int yPosition = 0;
bool xMoved = false;
bool yMoved = false;
int minThreshold = 300;
int maxThreshold = 700;

//the EEPROM adress used for storing all the numbers
const int adress = 0;

int digitArray[16] = {
//A B C D E F G DP 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
};

//for digit select
int currentDigit = 0;
int currentDigitOnDisplay[] = {
  0,0,0,0
};

int blinkTimer = 0;

void setup() {
  
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  
  for(int i = 0; i < displayCount; i++){
    pinMode(displayDigits[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(swPin), digitSelected, CHANGE);
  readArrayFromEEPROM(adress, currentDigitOnDisplay, displayCount);
  Serial.begin(9600);
}

void loop() {
  //if the button is not pressed the joystick will browse through the digits if the button is not pressed to the right or to the left
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);

  if(swState == LOW){
    if(swState != prevSwState){
      writeArrayIntoEEPROM(adress, currentDigitOnDisplay, displayCount);
      prevSwState = swState;
    }
    
    if (xPosition <= minThreshold && !xMoved){
      xMoved = true;
      currentDigit--;
      if (currentDigit < 0){
        currentDigit = 3;
      }
    }

    if (xPosition >= maxThreshold && !xMoved){
      xMoved = true;
      currentDigit++;
      if (currentDigit > 3){
        currentDigit = 0;
      }
    }

    if (xPosition >= minThreshold && xPosition <= maxThreshold){
      xMoved = false;
    }
  }
  //if the button is pressed it will browse through the digits from 0 to 9
  else{
    prevSwState = HIGH;
    if (yPosition <= minThreshold && !yMoved){
      yMoved = true;
      currentDigitOnDisplay[currentDigit]--;
      if (currentDigitOnDisplay[currentDigit] < 0){
        currentDigitOnDisplay[currentDigit] = 9;
      }
    }

    if (yPosition >= maxThreshold && !yMoved){
      yMoved = true;
      currentDigitOnDisplay[currentDigit]++;
      if (currentDigitOnDisplay[currentDigit] > 9){
        currentDigitOnDisplay[currentDigit] = 0;
      }
    }

    if (yPosition >= minThreshold && yPosition <= maxThreshold){
      yMoved = false;
    }
  }
  writeNumber();
}

//function for writing an array from EEPROM:
void writeArrayIntoEEPROM(int address, int numbers[], int arraySize)
{
  int addressIndex = address;
  /*
   * For every number we have to store, we’ll have to increment the address by 2, because an int is stored on 2 bytes.
   * We’ll use this new variable to keep the current address correctly updated.
   * With those 2 lines we split the int number into 2 bytes. 
   * The first byte (higher) will be stored on the current address index, and the second byte (lower) will be stored on the next following address
   */
  for (int i = 0; i < arraySize; i++){
    EEPROM.write(addressIndex, numbers[i] >> 8);
    EEPROM.write(addressIndex + 1, numbers[i] & 0xFF);
    addressIndex += 2;
  }
}

//function for reading an array from EEPROM:
void readArrayFromEEPROM(int address, int numbers[], int arraySize)
{
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++){
    numbers[i] = (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
    addressIndex += 2;
    /*
     * We read the 2 bytes corresponding to the next number, and recreate the int number from those 2 bytes. 
     * The int number can then go directly into the array.
     */
  }
}

void digitSelected() {
  if(millis() - lastBounce > debounceTimer) {
    swState = !swState;
  }
  lastBounce = millis();
}

void writeNumber(){
  for(int i = 0; i < displayCount; i++){
    showDigit(i);
    if (i == currentDigit && swState == LOW){
      //make the DP blink
      if (millis() - blinkTimer < 500) {
        writeReg(digitArray[currentDigitOnDisplay[i]] + 1);
      }
      if (millis() - blinkTimer > 1000) {
        writeReg(digitArray[currentDigitOnDisplay[i]]);
        blinkTimer = millis();
      }
    }
    else {
      writeReg(digitArray[currentDigitOnDisplay[i]]);
    }
    //if a digit is selected the dp will be turned on
    if (i == currentDigit && swState == HIGH) {
      writeReg(digitArray[currentDigitOnDisplay[i]] + 1);
    }
  delay(2);  
  }  
}

void showDigit(int displayNumber){
  for(int i = 0; i < displayCount; i++){
    digitalWrite(displayDigits[i], HIGH);
  }
  digitalWrite(displayDigits[displayNumber], LOW);
}

void writeReg(int digit){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  digitalWrite(latchPin, HIGH);
}
