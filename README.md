# Drone Fishing Release Mechanism
Drone fishing release mechanism - The arduino code for an arduino nano, connected to a Naze32 flight controller and an SG90 servo motor.

Prerequisites: Arduino, Naze32/Betaflight, and Taranis X9D+ Controller

Hardware:
- Arduino Nano
- SG90 Servo Motor
- Naze32
- Taranis X9D+ Controller

How to set things up:
1. Betaflight: Turn on the 'Servo Tilt' option in the 'Other Features' section of the Configuration tab. Click 'Save and Reboot'.
2. Taranis X9D+: Set the Auxiliary 3 channel in the 'Mixer' menu page. (Assuming you already have Aux 1 and 2 being used.
3. Betaflight: Find the 'Camstab' feature in the Modes tab, set the corresponding Aux channel, and set the range for activation (1900-2100). Click 'Save'.
4. Betaflight: Go to the CLI tab and remap the Motor 5 Pins to act as Servo 1 Pins.
  a) Enter 'resource'
  b) Enter 'resource Motor 5 none'
  c) Enter 'resource Servo 1 B08'
  d) Enter 'save'
5. Betaflight: Go to the Servo tab and link the correct channel (Aux 3 in this example). Note the offset of 1, hence Servo 0 in this tab actually refers to Servo 1.
6. Hardware: Connect the Power and Ground pins of the Motor 5 (or Servo 1) pins to the Arduino and connect the signal pin to pin 9 of the Arduino.
7. Hardware: Connect the Power and Ground pins of the Arduino to the Servo motor, and pin 7 of the Arduino, to the Servo motor signal pin.
8. Arduino: Compile and Upload the Arduino file to the Arduino Nano.
9. Naze32: Power up the naze 32
10. Hardware: Flick the switch connected to the Aux 3 channel, to activate the release mechanism.
