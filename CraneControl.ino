#include "AccelStepper.h"
#define HALFSTEP 8

#define motorPin1  12
#define motorPin2  11
#define motorPin3  10
#define motorPin4  9

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup()
{
  stepper1.setMaxSpeed(1000.0);
  stepper1.setSpeed(1000);
  stepper1.moveTo(0);
}

void loop()
{
  
}

String serialEvent()
{
  /* Returns a optimized string of the HC-06 
   * Bluetooth device
   * 
   * YOU HAVE TO CHECK FIRST, IF THE SERIAL 
   * BLUETOOTH DEVICE HC-06 IS AVAILABLE,  
   * BEFOR CALLING THIS FUNCTION
   *  
   * Don't forget "Serial.begin(9600);"
   * in the "void setup()" :D
   */
  
  String data;
  
  data = Serial.readString();
  data.remove(0,10);
  data.remove(data.length()-1,1);

  return data;
}

