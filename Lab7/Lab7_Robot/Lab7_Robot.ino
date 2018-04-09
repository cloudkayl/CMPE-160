// ===========================================================
//
// Lab7_Robot.ino  
// Description: Arduino robot move
// Name: Peter Fabinski
//       Ayush Rout
// Date: 2017-10-19
// Class: CMPE-110
// Section: 3, Thurs. 11AM
//
// ===========================================================
//
//  Welcome to the CMPE-110 Robotics Lab!
//
// To program your robot, modify the code in the loop() function
// Functions you can use are:
//    fwd(duration,speed)- go forward.  
//         Duration is an integer in msec.  This is how long the robot will go forward
//         Speed is an integer from 1 (slowest) up to 10 (fastest)
//         The robot will /not/ stop if it detects and object in front of it
//    rev(duration,speed)- go backward.  
//         Duration is an integer in msec.  This is how long the robot will go backward
//         Speed is an integer from 1 (slowest) up to 10 (fastest)
//         The robot will /not/ stop if it detects an object behind it
//                           
//    turnLeft(duration,speed)- turn left.  
//         Duration is an integer in msec.  This is how long robot will turn left
//         Speed is an integer from 1 (slowest) up to 10 (fastest)
//    turnRight(duration,speed)- turn right.  
//         Duration is an integer in msec.  This is how long robot will turn right
//         Speed is an integer from 1 (slowest) up to 10 (fastest)
//    delay(duration)- let robot rest.  
//         Duration is an integer in msec.  This is how long the robot will rest
// You can start with the sample code in the loop() function and get creative!
//

#include <Servo.h>

// Attach the left and right servo control wires (white) 
// to pins 5 and 6 respectively.
#define SERVO_LEFT 5
#define SERVO_RIGHT 6
// Attach the left and right wheel encoder wires
// to pins A4 and A1
#define LEFT_WHEEL_SENSOR A4
#define RIGHT_WHEEL_SENSOR A1
// Attach the front and side IR Sensor wires
// to pins A0 and A3
#define FRONT_IR_SENSOR A0
#define SIDE_IR_SENSOR A3

#define LSERVOREST 1500
#define RSERVOREST 1500

Servo myservo_left; 
Servo myservo_right; 
int pos = 0; // variable to store the servo position 
void setup() 
{ 
 // attaches the left wheel servo on pin 5 to servo object 
 myservo_left.attach(SERVO_LEFT); 
 // attaches the right wheel servo on pin 6 to servo object 
 myservo_right.attach(SERVO_RIGHT); 
 Serial.begin(19200); //for serial IO to screen 
 Serial.println("Welcome to my servo tester!"); 
} 

// ********* Change the code below to program your robot! *********

void loop() 
{ 
  //the robot will execute commands in this function one at at time.
  //when the last command is executed, it starts again with the first command
  fwd(500,5);
  turnLeft(3000,8);
  delay(200);
  rev(250,5);
  delay(200);
  rev(250,5);
  turnRight(2000,3);
  fwd(1000,8);
} 

// ********* Don't change any code below here. (But feel free to look and ask questions!) *********

// Function fwd
// Input duration- this is the time the robot will go forward in msec
//       speed- this is the speed the robot will move, 1=slow, 10=fast
// This function is identical to forward, however, it does not look for
// objects in front and will continue going forward for duration, even 
// if it means it will crash into an object
void fwd(int duration, int speed)
{ 
  if (speed < 1) speed=1;
  if (speed > 10) speed = 10;
  
  Serial.print("In function fwd, duration:");
  Serial.println(duration,DEC); //print decimal value  
  
  // start robot moving forward
  myservo_left.writeMicroseconds(LSERVOREST+50*speed);
  myservo_right.writeMicroseconds(RSERVOREST-50*speed);

  delay(duration);

  // stops robot from moving
  myservo_left.writeMicroseconds(LSERVOREST);
  myservo_right.writeMicroseconds(RSERVOREST);
}

// Function rev
// Input duration- this is the time the robot will go backward in msec
//       speed- this is the speed the robot will move, 1=slow, 10=fast
// This function is identical to backward, however, it does not look for
// objects in back and will continue going backward for duration, even 
// if it means it will crash into an object
void rev(int duration, int speed)
{
  
  if (speed < 1) speed=1;
  if (speed > 10) speed = 10;
  
  Serial.print("In function rev, duration:");
  Serial.println(duration,DEC); //print decimal value  
  
  // start robot moving backward
  myservo_left.writeMicroseconds(LSERVOREST-50*speed);
  myservo_right.writeMicroseconds(RSERVOREST+50*speed);

  delay(duration);

  // stops robot from moving
  myservo_left.writeMicroseconds(LSERVOREST);
  myservo_right.writeMicroseconds(RSERVOREST);
}

// Function stop
// The robot will stop moving
void stop()
{
  // stops robot from moving
  myservo_left.writeMicroseconds(LSERVOREST);
  myservo_right.writeMicroseconds(RSERVOREST);
}

// Function turnLeft
// Input duration- this is the time the robot will go turn left in msec
//       speed- this is the speed the robot will turn, 1=slow, 10=fast
void turnLeft(int duration, int speed)
{
  
  if (speed < 1) speed=1;
  if (speed > 10) speed = 10;
  
  Serial.print("In function turnLeft, duration:");
  Serial.println(duration,DEC); //print decimal value  
  
  // start robot moving backward
  myservo_left.writeMicroseconds(LSERVOREST-50*speed);
  myservo_right.writeMicroseconds(RSERVOREST-50*speed);
  
  //keep turning for duration msec
  delay(duration);
  
  // stops robot from turning
  myservo_left.writeMicroseconds(LSERVOREST);
  myservo_right.writeMicroseconds(RSERVOREST);
}

// Function turnRight
// Input duration- this is the time the robot will go turn right in msec
//       speed- this is the speed the robot will turn, 1=slow, 10=fast
void turnRight(int duration, int speed)
{

  if (speed < 1) speed=1;
  if (speed > 10) speed = 10;
  
  Serial.print("In function turnLeft, duration:");
  Serial.println(duration,DEC); //print decimal value  
  
  // start robot moving backward
  myservo_left.writeMicroseconds(LSERVOREST+50*speed);
  myservo_right.writeMicroseconds(RSERVOREST+50*speed);
  
  //keep turning for duration msec
  delay(duration);
  
  // stops robot from turning
  myservo_left.writeMicroseconds(LSERVOREST);
  myservo_right.writeMicroseconds(RSERVOREST);
}
