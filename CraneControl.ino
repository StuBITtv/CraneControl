#include "AccelStepper.h"
#define HALFSTEP 8

#define motor1Pin1  12
#define motor1Pin2  11
#define motor1Pin3  10
#define motor1Pin4  9

#define motor2Pin1  8
#define motor2Pin2  7
#define motor2Pin3  6
#define motor2Pin4  5

AccelStepper stepper1(HALFSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper stepper2(HALFSTEP, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);
String commandStepper[2];

void setup()
{
  Serial.begin(9600);
  stepper1.setMaxSpeed(1000.0);
  stepper2.setMaxSpeed(1000.0);
}

void loop()
{
  if (Serial.available() > 0) //get data from Bluetooth if available
  {
    String received = getBluetooth();
    if (received[0] == '1') //check what motor is wanted
    {
      commandStepper[0] = received;
    }
    else if (received[0] == '2')
    {
      commandStepper[1] = received;
    }
  }

  if (commandStepper[0] == "1:up") //check command buffer for first stepper
  {
    stepper1.setSpeed(1000.0);
    stepper1.runSpeed();
  }
  else if (commandStepper[0] == "1:down")
  {
    stepper1.setSpeed(-1000.0);
    stepper1.runSpeed();
  }
  else
  {
    stepper1.stop();
  }

  if (commandStepper[1] == "2:up") //check command buffer for second stepper
  {
    stepper2.setSpeed(1000.0);
    stepper2.runSpeed();
  }
  else if (commandStepper[1] == "2:down")
  {
    stepper2.setSpeed(-1000.0);
    stepper2.runSpeed();
  }
  else
  {
    stepper2.stop();
  }
}

String getBluetooth()
{
  /* Returns a optimized string of the HC-06
     Bluetooth device

     YOU HAVE TO CHECK FIRST, IF THE SERIAL
     BLUETOOTH DEVICE HC-06 IS AVAILABLE,
     BEFOR CALLING THIS FUNCTION

     Don't forget "Serial.begin(9600);"
     in the "void setup()" :D
  */

  String data;

  data = Serial.readString();
  data.remove(0, 10);
  data.remove(data.length() - 1, 1);

  return data;
}

