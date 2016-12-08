/* 
This is a program to run two peristaltic pumps

For use with the Adafruit Motor Shield v2 
---->  http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *motorOne = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *motorTwo = AFMS.getMotor(2);
// You can also make another motor on port M3
Adafruit_DCMotor *motorThree = AFMS.getMotor(3);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  motorOne->setSpeed(100);
  motorOne->run(FORWARD);
  // turn on motor
  motorOne->run(RELEASE);


  // Set the speed to start, from 0 (off) to 255 (max speed)
  motorTwo->setSpeed(100);
  motorTwo->run(FORWARD);
  // turn on motor
  motorTwo->run(RELEASE);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  motorThree->setSpeed(100);
  motorThree->run(FORWARD);
  // turn on motor
  motorThree->run(RELEASE);
  
}

void loop() {

  int LENGTH_1;  //STATE 1 motor 1 length
  int LENGTH_2;  //STATE 1 motor 2 length

  //Random length between 2000 and 50000
  LENGTH_1 = rand() % 48001 + 2000;
  Serial.println(LENGTH_1);

  //Drive Motor #1 forward (Clear)
  Serial.println("motorOne-------------------------");

      motorOne->run(FORWARD); //clear
      motorOne->setSpeed(150);

      motorThree->run(FORWARD);
      motorThree->setSpeed(150);
      
      delay(LENGTH_1*1.5);
      
      motorOne->run(RELEASE);
      motorThree->run(RELEASE);


  //Drive Motor #2 forward (Black)
  Serial.println("motorTwo-------------------------");   
      motorTwo->run(FORWARD); //black
      motorTwo->setSpeed(150);
     
      motorThree->run(FORWARD);
      motorThree->setSpeed(150);
      
      delay(LENGTH_1);
    
      motorTwo->run(RELEASE);
      motorThree->run(RELEASE);


}


