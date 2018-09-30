/*
 * Utra-sonic gate opener
 * This program reads a Paralax Utra-sonic "ping" sensor
 * When the sensor is triggered, an analog servo is opened
 * 2018 Nathan Young
 * 
 */

#include <NewPing.h> 
#include <Servo.h>

int pos = 0; // variable to store the servo position

//sonar0
const int TriggerPin0 = 11;
const int EchoPin0 = 12;

//sonar1
const int TriggerPin1 = 5;
const int EchoPin1 = 6;

Servo myservo; // create servo object to control a servo
NewPing sonar0(TriggerPin0, EchoPin0, 100);
NewPing sonar1(TriggerPin1, EchoPin1, 100);

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {

  int cm0 = sonar0.ping_cm();
  int cm1 = sonar1.ping_cm();

  Serial.println(cm0); // Use "serial plotter" to debug

  if (cm0 >= 1)

  {
    //open gate for sonar0
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15); // waits 15ms for the servo to reach the position
    }

    delay(5000); //hold the gate open

    //close gate for sonar0
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15); // waits 15ms for the servo to reach the position
    }
  }

  if (cm1 >= 1)

  {
    //open gate for sonar0
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15); // waits 15ms for the servo to reach the position
    }

    delay(5000); //hold the gate open

    //close gate for sonar0
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15); // waits 15ms for the servo to reach the position
    }
  }

  delay(250); //wait 250 uSecondds

  //reset our values
  cm0 = 0;
  cm1 = 0;
}
