#include <SoftwareSerial.h>

const int buttonPin = 2;         // Pin connected to the push button
const int buzzerPin = 13;         // Pin connected to the buzzer

SoftwareSerial mySerial(11, 10); // RX, TX for GSM module

bool messageSent = false;        // To prevent repeated SMS on a single press

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(buzzerPin, OUTPUT);       // Set buzzer pin as output

  mySerial.begin(9600);             // GSM module communication
  delay(1000);

  // Set GSM module to SMS text mode
  mySerial.println("AT+CMGF=1"); 
  delay(1000);
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read the state of the push button

  if (buttonState == LOW && !messageSent) { // If button is pressed and SMS not yet sent
    activateBuzzer();           // Activate buzzer when button is pressed
    delay(1000);
    sendSMS();                  // Send SMS
    messageSent = true;         // Set flag to prevent multiple SMS for a single press
  } else if (buttonState == HIGH) { // Reset flag when button is released
    messageSent = false;
  }
}

void activateBuzzer() {
  digitalWrite(buzzerPin, HIGH); // Turn buzzer on
  delay(500);                    // Buzz for 500 ms
  digitalWrite(buzzerPin, LOW);  // Turn buzzer off
  delay(500);                    // Delay before SMS sends
}

void sendSMS() {
  // Send SMS command
  mySerial.println("AT+CMGS=\"+94xxxxxxx\""); // Replace with recipient's phone number
  delay(1000);

  // Send the SMS text
  mySerial.print("I'm in an Emergency Situation");
  delay(1000);

  mySerial.write(26); 
  delay(2000);        
}
