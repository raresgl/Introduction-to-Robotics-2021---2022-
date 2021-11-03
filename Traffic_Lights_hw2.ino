const int pushButton = 2;
const int buzzerPin = 3;
const int greenHumanPin = 5;
const int redHumanPin = 6;
const int redCarPin = 9;
const int yellowCarPin = 10;
const int greenCarPin = 11;

bool buttonState = HIGH;
bool lastButtonState = HIGH;

bool greenCarPinState = HIGH;
bool yellowCarPinState = LOW;
bool redCarPinState = LOW;
bool greenHumanPinState = LOW;
bool redHumanPinState = HIGH;

int reading = HIGH;
int debounceDelay = 50;
int stateChangeTimer = 0; // this is the timer for state changes

int greenTimer = 0; // this timer starts when the pedestrian light turns green

//-- the delays for each state
int state2Delay = 10000;
int state3Delay = 3000;
int state4Delay = 10000;
int backToState1Delay = 15000;

//-- buzzer vars
int buzzerTimer = 0;
int buzzerDelay = 800;
const int buzzerTone = 60;
int blinkDelay = 400; //this will correspond to both the buzzer and the led

//-- the 4 states of the lights
bool state1 = HIGH;
bool state2 = LOW;
bool state3 = LOW;
bool state4 = LOW;

//-- This function will print the leds in each state
void ledPrinting(){
  digitalWrite(redCarPin, redCarPinState); 
  digitalWrite(yellowCarPin, yellowCarPinState); 
  digitalWrite(greenCarPin, greenCarPinState); 

  digitalWrite(redHumanPin, redHumanPinState); 
  digitalWrite(greenHumanPin, greenHumanPinState);
}

//-- This function will be useful for the first state setup and after the last state
void basicState(){
  greenCarPinState = HIGH;
  yellowCarPinState = LOW;
  redCarPinState = LOW;
  greenHumanPinState = LOW;
  redHumanPinState = HIGH;
}

void setup() {
  pinMode(pushButton, INPUT_PULLUP);
    
  pinMode(greenCarPin, OUTPUT);
  pinMode(yellowCarPin, OUTPUT);
  pinMode(redCarPin, OUTPUT);

  pinMode(greenHumanPin, OUTPUT);
  pinMode(redHumanPin, OUTPUT);
    
  Serial.begin(9600);

}

void loop() {
  // first state: green for cars, red for ppl
  reading = digitalRead(pushButton);
  if(reading == LOW && state1 == HIGH && stateChangeTimer == 0){
    stateChangeTimer = millis();
    state1 = LOW;
    state2 = HIGH;
  }

 //second state(after 10 sec): yellow for cars, red for ppl
  if(state2 == HIGH && millis() - stateChangeTimer > state2Delay && stateChangeTimer != 0){
  greenCarPinState = LOW;
  yellowCarPinState = HIGH;
  state2 = LOW;
  state3 = HIGH;
  stateChangeTimer = millis();
  }

//third state(after 3sec): red for cars, green for ppl, buzzer starts
  if(state3 == HIGH && millis() - stateChangeTimer > state3Delay){
    yellowCarPinState = LOW;
    redCarPinState = HIGH;
    greenHumanPinState = HIGH;
    redHumanPinState = LOW;
    state3 = LOW;
    state4 = HIGH;
    stateChangeTimer = millis();
  }
  
  if(millis() - stateChangeTimer < state4Delay && state4 == HIGH){
    if(millis() - buzzerTimer > buzzerDelay) {   
      tone(buzzerPin, buzzerTone, 300);
      buzzerTimer = millis();  
    }
  }

//last state(after 10sec): red for cars, blinking green for ppl, buzzer beeps faster
  if(state4 == HIGH && millis() - stateChangeTimer > state4Delay && millis() - stateChangeTimer < backToState1Delay){
      if(millis() - buzzerTimer > blinkDelay){
        tone(buzzerPin, buzzerTone, 300);
        greenHumanPinState = !greenHumanPinState;
        buzzerTimer = millis();
      }
  }
  
  if(state4 == HIGH && millis() - stateChangeTimer > backToState1Delay){
    basicState();
    stateChangeTimer = 0;
    buzzerTimer = 0;
    state4 = LOW;
    state1 = HIGH;
  }
  
  ledPrinting();
}
