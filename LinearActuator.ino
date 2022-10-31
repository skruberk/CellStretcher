//This sketch activates a linear actuator using an arduino nano every board , requires the servo library (shouldn't need to be downloaded) 
//and the keypad library tools->manage libraries install keypad library (adafruit keypad works)

#include <Servo.h>
#include <Keypad.h>
const int buttonPin[] = {9,10,11,12};     // the number of the pushbutton pins
const byte ROWS = 1; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3','4'},
}; //recognizes these as keypad numbers

byte colPins[COLS] = {9, 10, 11, 12}; //connect arduino pins to column pinouts of keypad
byte rowPins[ROWS] = {8}; //connect arduino pins to recognize the row keypad

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );; 

Servo myservo;  // create servo object to control a servo
int servoPin=7;
int pos;    // variable to store the servo position
byte Speed = 0; // initialize variable for speed of motor (0-255)
int outPos = 115; //stretched servo position: max is 115, most likely want to change to a shorter stretch like 118
int inPos = 120; //starting servo position 
char currentKey=customKeypad.getKey();

void setup() {
  Serial.begin(9600);
  //customKeypad.begin();
myservo.attach(servoPin);  // attaches the servo on pin 7 to the servo object
myservo.write(inPos);
}

void loop() {
  // these are the keys you press to get the stretcher to move
char customKey = customKeypad.getKey();
  switch(customKey){
  case '1': //reset to starting position
  myservo.write(inPos);
    Serial.println(customKey);
    break;
  case '3': //manual stretch
    myservo.write(inPos);
    delay(500);
    myservo.write(outPos);
    delay(500);
    Serial.println(customKey);
    break;
  case '2':
    Serial.println(customKey);
    break;
  case '4': //cyclic stretch
  Serial.println(customKey);
    if (currentKey=customKey){
      for (int i=0; i<=10; i++) {
      myservo.write(inPos);
      delay(500);
      myservo.write(outPos);
      delay(500);
     Serial.println(currentKey); 
}
    }
  }
  }
 
