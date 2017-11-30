#include "AccelStepper.h"

AccelStepper stepper[2];
String commandStepper[2];

void setup()
{
  //setup steppers
  stepper[0]= AccelStepper (8, 12, 10, 11, 9);
  stepper[1]= AccelStepper (8, 8, 6, 7, 5);
  for(int i=0; i<2; i++)
  {
    stepper[i].setMaxSpeed(1000.0);
  }

  //setup Bluetooth
  Serial.begin(9600);
}

void loop()
{
  //if available, refresh command buffers
  if (Serial.available() > 0)
  {
    String received = getBluetooth();
    
    if (received[0] == '1') 
    { 
      received.remove(0, 2);
      commandStepper[0] = received;
    }
    else if (received[0] == '2')
    {
      received.remove(0,2);
      commandStepper[1] = received;
    }
  }

  //Apply command buffer to steppers 
  for(int i=0; i<2; i++)
  {
    if (commandStepper[i] == "up")
    {
      stepper[i].setSpeed(1000.0);
      stepper[i].runSpeed();
    }
    else if (commandStepper[i] == "down")
    {
      stepper[i].setSpeed(-1000.0);
      stepper[i].runSpeed();
    }
    else
    {
      stepper[i].stop();
    }
  }
}

// Returns a optimized string of the HC-06 Bluetooth device
String getBluetooth()
{
  String data;

  data = Serial.readString();
  data.remove(0, 10);
  data.remove(data.length() - 1, 1);

  return data;
}

