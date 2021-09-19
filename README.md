# airconditionV2
 
## Resources

1. 2 * Breadboard 
2. 14 * wires
3. 3 * 5mm LED
   - 1 red 
   - 1 green
   - 1 blue
5. 3 * 220Ω resistor
6. 1 * DS1621 Temperature Sensor Thermometer
7. 1 * DOIT ESP32 DEVKIT V1

## Breadboard
<!--![airconditionV2](https://user-images.githubusercontent.com/40162593/133789003-07c5d6a3-4d97-4ab8-a157-d5a57662b16a.png)-->
<!--![Breadboardv2](https://user-images.githubusercontent.com/40162593/133884399-d902ef32-fdb9-48b6-b0b6-ae164d286895.png)-->
<!--![Breadboardv3](https://user-images.githubusercontent.com/40162593/133884882-ebc3fb25-db2f-4b40-9e93-8d55dbf0a8c2.png)-->
![Breadboardv4](https://user-images.githubusercontent.com/40162593/133886941-7c4b6f03-19c2-4000-af02-df526ff3942f.png)

## Setting up the board

Use the images below to understand the wiring of the setup



![ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs-Copy](https://user-images.githubusercontent.com/40162593/133789754-861cc8f0-d1d8-422c-8ef9-1a139d93898a.png)
![DS1621_8-pin](https://user-images.githubusercontent.com/40162593/133790604-0b006b64-3559-432f-9224-510e0dffe16e.png)
![led-labelled](https://user-images.githubusercontent.com/40162593/133800583-c5de258b-33f9-498c-84ea-cdc249346c64.png)
![Breadboard](https://user-images.githubusercontent.com/40162593/133803772-38a72373-75a0-46a4-942b-07bff7b0160a.png)

### Place the ESP32 DEVKIT in between to two breadboard

1. Place the ESP32 DEVKIT on the 1. BreadBoard, where your connect the 3v3 GPIO to A56 and GPIO23 (VSPI MOSI) to A42 (Make sure all the other pin's is pressed down in the numbers in between).
2. Take the 2. BreadBoard, and connect the VIN GPIO to J56 and EN GPIO to J42 (Make sure all the other pin's is pressed down in the numbers in between).

### Place the DS1621_8-pin on BreadBoard

1. Place the DS1621 on the 1. BreadBoard, where your connect pin 1 (SDA) to E33 and pin 5 to F36 (A<sub>2</sub>)

### Place the LED's on BreadBoard

1. place the red led on the 1. Breadboard, where you connect the c- pin to G1 and a+ to G3
2. place the green led on the 1. Breadboard, where you connect the c- pin to G6 and a+ to G8
3. place the blue led on the 1. Breadboard, where you connect the c- pin to G11 and a+ to G13

### Place the resistors on the BreadBoard
1. Place the resistor on the 2. Breadboard, where you connect the 1. pin to E49 and the 2. pin to H49 (make sour that it is connectet to GPIO25 one the ESP32 DEVKIT.
2. 1. Place the resistor on the 2. Breadboard, where you connect the 1. pin to E50 and the 2. pin to H50 (make sour that it is connectet to GPIO26 one the ESP32 DEVKIT.
3. 1. Place the resistor on the 2. Breadboard, where you connect the 1. pin to E51 and the 2. pin to H51 (make sour that it is connectet to GPIO27 one the ESP32 DEVKIT.

### Setting up the DS1621 to the ESP32 DEVKIT (All on 1. BreadBoard).

1. Connect pin 1 (SDA) on the DS1621 to GPIO21 (I2C SDA) on the ESP32 DEVKIT.
   - Connect a wire from D33 to D46
3. Connect pin 2 (SCL) on the DS1621 to GPIO22 (I2C SCL) on the ESP32 DEVKIT.
   - Connect a wire from C34 to C43
5. Connect pin 7, 6 and 5 (A<sub>0</sub>, A<sub>1</sub> and A<sub>2</sub>) on the DS1621 to pin 4 (GND).
   - Connect a wire from I34 to B36
   - Connect a wire from H35 to C36
   - Connect a wire from G36 to D36
7. Connect pin 4 (GND) to a GND GPIO on the ESP32 DEVKIT.
   - Connect a wire from A36 to E55 
8. Connect pin 8 (V<sub>DD</sub>) on the DS1621 to the 3v3 GPIO on the ESP32 DEVKIT.
   - Connect a wire from J33 to B56

### Setting up the LED's to the ESP32 DEVKIT.

1. Connect all the led´s to negative (All on 1. BreadBoard).
   - connect a wire from J3 to Z3
   - connect a wire from J6 to Z9
   - connect a wire from J13 to Z13 
   - connect a wire from E55 to Z55
2. Connect all the led´s to resistors
   - connect a wire from G1 (1. BreadBoard) to D49 (2. BreadBoard)
   - connect a wire from G6 (1. BreadBoard) to D50 (2. BreadBoard)
   - connect a wire from G11 (1. BreadBoard) to D51 (2. BreadBoard)

## Setting up Arduino IDE
1. Folw this tutorial for setting op the EPS32 DEVKIT https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
2. Install libraries
   - NTPClient

## Connect to the ESP32 DEVKIT.
1. Open the program.
   - change the "ssid" whit the name of your wifi.
   -  the "password" whit the password to your wifi. 
   ![wifiConf](https://user-images.githubusercontent.com/40162593/133924649-a9d3c049-754d-466d-9421-7e13a9e42b8f.PNG)

3. Open the "Serial monitor".
4. Run the program.
5. Look at the "Serial monitor" and go to the ip addrase in a browser.
![ip](https://user-images.githubusercontent.com/40162593/133924877-ca66348f-892f-46a3-bde3-3810b59405fe.PNG)
6. now you'er done, and you will be looking at a sceren the look like this.
![Webside](https://user-images.githubusercontent.com/40162593/133924949-2ae2d302-e735-4287-8878-1708a402530d.PNG)
  

