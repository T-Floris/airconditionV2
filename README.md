# airconditionV2
 
## Resources

1. 14 * wires
2. 3 * LED
3. 3 * 220Ω resistor
4. 1 * DS1621 Temperature Sensor Thermometer
5. 1 * DOIT ESP32 DEVKIT V1

## Breadboard
![airconditionV2](https://user-images.githubusercontent.com/40162593/133789003-07c5d6a3-4d97-4ab8-a157-d5a57662b16a.png)

## Setting op the board

Use the images below to understand the wiring of the setup

![ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs-Copy](https://user-images.githubusercontent.com/40162593/133789754-861cc8f0-d1d8-422c-8ef9-1a139d93898a.png)
![DS1621_8-pin](https://user-images.githubusercontent.com/40162593/133790604-0b006b64-3559-432f-9224-510e0dffe16e.png)

1. Connect pin 1 (SDA) on the DS1621 to GPIO21 (I2C SDA) on the ESP32 DEVKIT.
2. Connect pin 2 (SCL) on the DS1621 to GPIO22 (I2C SCL) on the ESP32 DEVKIT.
3. Connect pin 7, 6 and 5 (A<sub>0</sub>, A<sub>1</sub> and A<sub>2</sub>) on the DS1621 to pin 4 (GND).
4. Connect pin 4 (GND) to a GND (GPIO) on the ESP32 DEVKIT.
5. Connect pin 8 (V<sub>DD</sub>) on the DS1621 to the 3v3 (GPIO) on the ESP32 DEVKIT.
