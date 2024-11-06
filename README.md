# Safety_bag
An emergency alert system using Arduino that sends an SMS and activates a buzzer when a button is pressed.

1. Hardware Setup
● Connect the GSM module -SIM99A to the Arduino.
○ GND of the GSM module to GND of the Arduino.
○ VCC of the GSM module to 5V on the Arduino (confirm the voltage
requirements for your module).
○ TX of the GSM module to (pin 10, for example) on the Arduino.
○ RX of the GSM module to (pin 11) on the Arduino.

● Connect the Buzzer
○ One pin for GND
○ Second pin for - pin 13

● Connect the Push Button
○ One pin for GND
○ Second pin for - pin 2

2. Software setup
You will need the SoftwareSerial library to communicate with the GSM module.
1. Open the Arduino IDE.
2. Go to Sketch > Include Library > SoftwareSerial (if it’s not already included).
3. Enter the following code to send a message.
