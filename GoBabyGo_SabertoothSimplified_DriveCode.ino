/**
 * Sabertooth Simplified motor driver code for the Project90 Go Baby Go project.
 * Code includes optiosns for steering using joystick or button operated controls. 
 */

#include <SabertoothSimplified.h>
SabertoothSimplified ST; // Using default connections -- 
                         // Connections to make:
                         //   Arduino TX->1  ->  Sabertooth S1
                         //   Arduino GND    ->  Sabertooth 0V
                         //   Arduino VIN    ->  Sabertooth 5V
                         //
                         
//Control Method/Option Setup
boolean JOYSTICK_CONTROL = true;
boolean BUTTON_CONTROL = false;
boolean DEBUG = true;

//Invert Motor Directions
boolean INVERT_M1 = false;
boolean INVERT_M2 = false;

//Analogue Joystick Input Designation
int xIN = 3;  //X axis input
int yIN = 4;  //Y axis input

//Button Control Input Designation
//TODO specify inputs

//Constants
int MAX_SPEED = 30; //Adjust as needed (Recommend less than 80);
int POT_NEUTRAL = 40; //Adjust as needed

int prevLeft, prevRight;

                                       
void setup()
{
  pinMode(xIN, INPUT);
  pinMode(yIN, INPUT);
  SabertoothTXPinSerial.begin(9600); // This is the baud rate you chose with the DIP switches.
}
void loop()
{
  int vx, vy;

  if(JOYSTICK_CONTROL){
    vx = analogRead(xIN);
    vy = analogRead(yIN);

    //Need to include a small range of acceptable neutral values for POT
    if(abs(512-vx)<POT_NEUTRAL){
      vx = 512;
    }
    if(abs(512-vy)<POT_NEUTRAL){
      vy = 512;
    }
  
    //Map input POT values to motor range (-127, 127)
      vx = map(vx, 0, 1023, -MAX_SPEED, MAX_SPEED);
      vy = map(vy, 0, 1023, -MAX_SPEED, MAX_SPEED);
  }

  if(BUTTON_CONTROL){
    //TODO Setup Button Control
  }
//    int drivePower = 0;
//    if(vy>512) {
//      drivePower = vy-512;
//    }
//    else {
//      drivePower = -(512-vy);
//    }
//    
//    int turnValue = 0;
//    if(vx>512) {
//      turnValue = vx-512;
//    }
//    else {
//      turnValue = -(512-vx);
//    }

  
    singleJoystickDrive(vy, vx);
    delay(10);
}

/**
 * Control motor speed and direction using a single joystick steering method
 */
void singleJoystickDrive(int drivePower, int turnValue){
  int motorLeft = 0;
  int motorRight = 0;

  //If moving forwards
  if(drivePower > 0){
    if(turnValue > 0){
      //Turning to the left
      motorLeft = drivePower - turnValue;
      motorRight = max(drivePower, turnValue);
    }
    else{
      //Turning to the right
      motorLeft = max(drivePower, -turnValue);
      motorRight = drivePower + turnValue;
    }
  }
  //Moving backwards
  else{
    if(turnValue > 0){
      //Turning to the left
      motorLeft = -max(-drivePower, turnValue);
      motorRight = drivePower + turnValue;
    }
    else{
      //Turning to the right
      motorLeft = drivePower - turnValue;
      motorRight = -max(-drivePower, -turnValue);
    }
  }
  driveCar(motorLeft, motorRight);
}

/**
 * Output values to car motors.
 */
void driveCar(int left, int right){
  prevLeft = left;
  prevRight = right;
  ST.motor(1, left);
  ST.motor(2, right);
}

/**
 * Print values of inputs/outputs to the serial monitor for testing
 */
void debug(String message, int value){
  if(DEBUG){
    Serial.print(message);
    Serial.print(" ");
    Serial.println(value);
  }
}

