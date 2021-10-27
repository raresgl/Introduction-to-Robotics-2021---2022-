const int potRedPin = A0; 
const int potGreenPin = A1;
const int potBluePin = A2;

const int redLed = 11;
const int greenLed = 10; 
const int blueLed = 9; 

int mini = 0;
int maxPotValue = 1023;
int maxAnalogValue = 255;

int potRedValue;
int potGreenValue;
int potBlueValue;

int brightnessRed;
int brightnessGreen;
int brightnessBlue;

void setup(){
  
    pinMode(potRedPin, INPUT); 
    pinMode(potGreenPin, INPUT); 
    pinMode(potBluePin, INPUT);

    pinMode(redLed, OUTPUT); 
    pinMode(greenLed, OUTPUT); 
    pinMode(blueLed, OUTPUT);
    
    /* serial communication initialisation at 9600 bits per second */
    Serial.begin(9600);
}

void loop(){
   potRedValue = analogRead(potRedPin);
   potGreenValue = analogRead(potGreenPin);
   potBlueValue = analogRead(potBluePin);

   brightnessRed = map(potRedValue, mini, maxPotValue, mini, maxAnalogValue);
   brightnessGreen = map(potGreenValue, mini, maxPotValue, mini, maxAnalogValue);
   brightnessBlue = map(potBlueValue, mini, maxPotValue, mini, maxAnalogValue);

   analogWrite(redLed, brightnessRed);
   analogWrite(greenLed, brightnessGreen);
   analogWrite(blueLed, brightnessBlue);
   
   /* printing the values in Terminal serial:
   Serial.print("Red: ");
   Serial.print(brightnessRed);
   Serial.print(" Green: ");
   Serial.print(brightnessGreen);
   Serial.print(" Blue: ");
   Serial.print(brightnessBlue);
   Serial.print("\n");\
   */
   delay(10);
}
