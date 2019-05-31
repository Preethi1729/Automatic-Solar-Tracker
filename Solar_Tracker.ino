#include<Servo.h>
Servo myservo; // create servo object to control a servo
int pos = 90; // initial position
int ldr1 = A0; // LDR 1 pin
int ldr2 = A1; //LDR 2 pin
int tolerance = 2; //Sets the tolerance for which the slope is valid for the trigger process.
void setup()
{
myservo.attach(9); // attaches the servo on pin 9 to the servo object
pinMode(ldr1, INPUT);// initialize the input pins
pinMode(ldr2, INPUT);


myservo.write(pos); // tell servo to go to position in variable &#39;pos&#39;
delay(2000); // a 2 seconds delay while we position the solar panel
}
void loop()
{
  
int val1 = analogRead(ldr1); // read the value of sensor 1
int val2 = analogRead(ldr2); // read the value of sensor 2
if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {
//do nothing if the difference between values is within the tolerance limit
} else {
if(val1 > val2)
{
pos = -- pos;
}
if(val1 < val2)
{
pos = ++pos;



}

if(pos > 180) { pos = 180; } // reset to 180 if it goes higher
if(pos < 0) { pos = 0; } // reset to 0 if it goes lower
myservo.write(pos); // tell servo to go to position in variable &#39;pos&#39;
delay(50); // waits 50ms for the servo to reach the position

}
}
