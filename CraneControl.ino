#include "AccelStepper.h"
#define HALFSTEP 8

#define motorPin1  12
#define motorPin2  11
#define motorPin3  10
#define motorPin4  9

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
String received;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  stepper1.setMaxSpeed(1000.0);
  
  stepper1.moveTo(0);
}

void loop()
{
  if(Serial.available()>0)
  {
    received=getBluetooth();
  }
  if(received.equals("up"))
  {
    stepper1.setSpeed(1000);
    stepper1.runSpeed();
  }
  else if(received.equals("down"))
  {
    stepper1.setSpeed(-1000);
    stepper1.runSpeed();
  }
  else
  {
    stepper1.stop();
  }
  Serial.print(received);
}

String getBluetooth()
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

