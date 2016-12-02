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

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  motorOne->setSpeed(200);
  motorOne->run(FORWARD);
  // turn on motor
  motorOne->run(RELEASE);


  // Set the speed to start, from 0 (off) to 255 (max speed)
  motorTwo->setSpeed(255);
  //motorTwo->run(FORWARD);
  motorTwo->run(BACKWARD);
  // turn on motor
  motorTwo->run(RELEASE);
  
}

void loop() {


  //Drive Motor #1 forward
  Serial.println("motorOne-------------------------");

      motorOne->run(FORWARD);
      motorOne->setSpeed(200);

    //  motorTwo->run(BACKWARD);
    //  motorTwo->setSpeed(70);
      
      delay(2000);
    //  motorOne->run(RELEASE);
      motorOne->setSpeed(0);

      
    //  motorTwo->run(RELEASE);
    //  delay(500);

  Serial.println("motorTwo-------------------------");   
      motorTwo->run(FORWARD); //black
      motorTwo->setSpeed(200);

   //   motorOne->run(BACKWARD);
   //   motorOne->setSpeed(70);
      
      delay(2000);
    //  motorTwo->run(RELEASE);
      motorOne->setSpeed(0);

      
    //  motorOne->run(RELEASE);
    //  delay(500);


}


