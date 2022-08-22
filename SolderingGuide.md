# Schematic
<img width="863" alt="Screen Shot 2022-08-22 at 12 05 26 PM" src="https://user-images.githubusercontent.com/90986809/185967140-c53564e6-aaa4-4b96-8251-fc4e92e16291.png">

## Power Supply
Regulates input power and ensures safe and reliable voltages for components.
- ensure correct polarity of diode and 10µf capacitor.

LM7805 Pinout              | Capacitor polarity | Diode Polarity                                                                                                                           |
----------------------|--------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| <img width="596" alt="Screen Shot 2022-08-22 at 12 06 23 PM" src="https://user-images.githubusercontent.com/90986809/185967888-a9bb82fe-3b4d-40fa-a32c-7d44f1aa36a5.png">  |  <img width="322" alt="Screen Shot 2022-08-22 at 12 07 48 PM" src="https://user-images.githubusercontent.com/90986809/185967889-dc147ff1-ac1e-4f62-9975-bb7484381400.png">                    |  <img width="319" alt="Screen Shot 2022-08-22 at 12 10 24 PM" src="https://user-images.githubusercontent.com/90986809/185968136-5d3b2108-10e4-4299-be19-d366ccdb8709.png">        |                                                                                                                                                     







## Max 3232
Converts UART to RS232. Allows serial communication between sensor and computer.
-Check RX and TX pins. T1out and R1in to the screw terminal. T1in and R1out to the Arduino.

## Arduino
Microcontroller used to switch LEDs on and off as well as record and smooth data from the ADC.
-Check RX, TX and Digital pins.
| **Arduino Nano Pinout**              |
|---
| <img width="600" alt="Screen Shot 2022-08-22 at 12 25 21 PM" src="https://user-images.githubusercontent.com/90986809/185977459-88b61806-44a3-429a-b07a-1b56bcace3e7.png">

## Photodiode amplifier
<img align="left" img width="160" alt="Screen Shot 2022-08-22 at 1 04 32 PM" src="https://user-images.githubusercontent.com/90986809/185978471-9dd8e05d-b376-4cf2-886b-9d81ebfd9e0b.png"> Transimpedance amplifier circuit to convert photodiode signal to voltage as well as amplify it before the ADC.
- 10MΩ and 22pf in parallel between 1in- and 1inOUT. PD cathode connects to 1in-. 1OUT goes to the low pass filter. *Make sure OpAmp is powered

## ADC
Analog-Digital Converter. Converts the analog voltage signal from the photodiode amplifier to a digital signal readable by the Arduino. SDA transfers data and SCL transfers clock information. A0 channel is what I have been using. You could theoretically use any channel. Ensure the input to the channel comes from the low pass filter after the capacitor.
## Transistor network
<img align="left" img width="315" alt="Screen Shot 2022-08-22 at 1 05 17 PM" src="https://user-images.githubusercontent.com/90986809/185978502-c2566217-7753-48aa-a07f-78d5726bfbaf.png"> Transistors are used in common emitter configuration as switches to allow the Arduino to control the current to power the LEDs. Pin 1 to GND, pin 2 comes from Arduino with 5.1KΩ, resistor pin 3 comes from LED negative terminal with 100Ω resistors.
