void setup()
{

}

void loop()
{

}

String getBluetoothString()
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

