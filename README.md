# Introduction-to-Robotics-2021---2022
Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files.

# HOMEWORK 1:

## Technical Task
Use a separate potentiometer in controlling each of thecolor of the RGB led (Red,Green andBlue).  
The control must be donewithdigital electronics(aka you must read the value of the potentiome-ter with Arduino, and write a mapped value to each of the pins connectedto the led.

## Components
* RGB led
* 3 potentiometers
* Arduino Uno board
* breadboard
* 3 330 ohms resistors
* connection cables

## Setup
![SetupHw1](https://user-images.githubusercontent.com/40142811/139057233-b06bd210-a544-4d58-b465-0480d003a5f9.jpeg)

## Live demo
You can access the live demo using this link: https://www.youtube.com/watch?v=e9ZMd7sGPAE

# HOMEWORK2:

## Technical Task
Building the traffic lights for a crosswalk. Youwill use 2 LEDs to represent the traffic lights for people (red and green)and 3 LEDs to represent the traffic lights for cars (red, yellow and green).

The system has the following states:

1.  State 1(default, reinstated after state 4 ends): green light for cars,red light for people, no sounds. Duration: indefinite, changed bypressing the button.
2.  State 2(initiated by counting down 10 seconds after a button press):the light should be yellow for cars, red for people and no sounds.Duration: 3 seconds.
3.  State 3(iniated after state 2 ends): red for cars, green for people anda beeping sound from the buzzer at a constant interval. Duration:10 seconds.
4.  State 4(initiated after state 3 ends): red for cars,blinking greenfor people and a beeping sound from the buzzer, at a constant inter-val, faster than the beeping i


## Components
 5 LEDs, 1 button, 1 buzzer, resistors and wires (per logic)
 
## Setup
![Hw2_Setup](https://user-images.githubusercontent.com/40142811/140174408-75080f3e-2a79-4fc3-9052-1edf6722bd83.jpeg)

## Live Demo

 
