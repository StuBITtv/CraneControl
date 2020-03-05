# CraneControl
Arduino Bluetooth model crane control

# What you need
- an Arduino compatible board
- a HC-06 Bluetooth modul
- 2x 28BYJ-48 stepper motors
- 2x ULN2003 motor drivers
- and of cours, an Android smartphone and a computer

# A note on the motors
I would highly recommend you to not use stepper motors due to their weak nature. Just use some cheap more powerful DC motors instead. You can still use the code for the Arduino as skeleton.  

# Setup the Arduino
- Connect the stepper motors to the motor drivers
- Connect the moto drivers to the pins 5-8  and 9-12 at your Arduino
- Connect the Bluetooth modul to the RX and TX on your Arduino
- Upload the "CraneControl.ino" to your Arduino

# Install the app
- Copy the "CraneControl.apk" to your smartphone
- Go to the security settings of your smartphone and allow unknown sources
- Open the APK and the installation starts

In case you can't hit the install button - make sure that your screen dimmer is turned of :D
