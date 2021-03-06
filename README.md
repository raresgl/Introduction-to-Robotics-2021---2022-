# Introduction-to-Robotics-2021---2022
Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files.

<details>
 <summary> HOMEWORK 1: </summary>

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
</details>
 
<details>
 <summary> HOMEWORK2: </summary>

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
You can access the live demo using this link: https://youtu.be/y_VPY5b39fc
</details>

<details>
<summary> HOMEWORK 3: </summary>

## Technical Task
Should detect EMF (check body and near outlets. It should printthe value on the 7-segment display (or light the led bar)andshould makea sound based on the intensity.

## Components
a buzzer and a 7-segment display 

## Setup
![Hw3](https://user-images.githubusercontent.com/40142811/141168503-d4a2eb9f-5b6d-4b92-9657-fb75f4916bc2.jpeg)

## Live Demo
https://youtu.be/HrWQLelACp8
 </details>
<details>
 <summary> HOMEWORK 4: </summary>
 
 ## Components
 4-digit 7-segments display
 74hc595 shift register
 joystick
 4 330 ohms resistors, connection cables, breadboard, Arduino board
 

 ## Technical task
 First  state:   you  can  use  a  joystick  axis  to  cycle  through  the  4digits; using the other axis does nothing. A blinking decimal point showsthe current     digit position.  When pressing the button,  you  lock  in  on  the  selected  digit  and  enter  thesecond state. In this state, the decimal point stays always on, no longerblinking and you can no longer use the axis to cycle through the 4 digits.Instead, using the other axis, you can increment on decrement the numberon the current digit.  Pressing the button again returns you to the previousstate.  For bonus, save the last value in eeprom and load it when startingarduino. Also, keep in mind that when changing the number, you mustincrement it for each joystick movement - it should not work continuoslyincrement if you keep the joystick in one position.
 
 ## Setup
 ![Hw4](https://user-images.githubusercontent.com/40142811/142275099-718ed093-4704-42a6-aaa9-c3b645c2f4c4.jpeg)
 
 ## Live Demo
 https://youtu.be/tzeR18wYXwA
 </details>
