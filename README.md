# Springer
Springer is an open source, side scattering optical sensor, utilizing commercially available electronics to measure water turbidity. We aim to create a low cost replicable sensor to be used for oceanographic research.
## Design
### Sensor Head
The sensor is designed for 3 LEDs and a Photodiode receiver. We have been testing with LEDS with wavelengths of 650, 670, 720nm with plans to use a 490nm LED in conjunction with a red filter to measure phytoplankton fluorescence. Each LED is 90 degrees to the Photodiode receiver in the middle of the sensor. The head is built with scintillation vials in mind for quick testing and calibration purposes. The cap is designed to be screwed into the head for flow through measurements.

### Electronics
A transimpedance amplifier converts and amplifies current output from the photodiode into a voltage output readable by an analog to digital converter. The ADS1115 ADC module is used with an Arduino Nano to control and send data from the sensor to a computer. The signal readings for the three LEDs as well as a dark reading are processed and output by the Arduino through a converter to an RS232 serial bus. The LEDs are switched on and off using the Arduino's digital pins as well as three transistors in common-emitter configuration, allowing for multiple wavelengths to be sampled quickly. Power to the system is controlled by a voltage regulator which accepts input voltage from 7-24 volts.

### Printed Circuit Board
All electronic components are soldered directly to a custom built printed circuit board that can be ordered using the attached files from a variety of PCB manufacturers. A custom circuit board simplifies the design while ensuring all components are properly connected and grounded allowing for quicker assembly as well as a single removable plate that can easily be inserted into and removed from the housing. All components are soldered to the board using through hole pins.
=======
Springer is an open source, side scattering optical sensor, utilising commercially available electronics to measure water turbidity. We aim to create a low cost cost replicable sensor to be used for oceanographic research.
## Design
### Sensor Head
The sensor is designed for 3 LEDs and a Photodiode reciever. We have been testing with LEDS with wavelengths of 650, 670, 720nm with plans to use a 490nm LED in conjunction with a red filter to measure phytoplankton folouresence. Each LED is 90 degrees to the Photodiode reciever in the middle of the sensor. The head is built with scintillation vials in mind for quick testing and calibration purposes. The cap is designed to be screwed into the head for flow through measurements.

### Electronics
A transimpedence amplifier converts and amplifies current output from the Photodiode into a voltage output readable by an Analog to digital converter.  The ADS1115 ADC module is used to with an Arduino Nano to control and send data from the sensor to a computer. The signal readings for the trhree LEDs as well as a dark reading are processed and output by the Arduino through a converter to an RS232 serial bus. The LEDs are switched on and off using the ARduino's digital pins as well as three transistors in commmon-emitter configuration, allowing for multiple wavelengthto be sampled quickly. Power to the system is controlled by a voltage regulator which accepts input voltage from 7-24 volts.

### Printed Circuit Board
All electronic components are soldered directly to a custom built printed circuit board, that can be ordered using the attached files from a variety of PCB manufacturers. A custom circuitboard simplifies the design while ensuring all components are properly connected and grounded allowing for quicker assembly as well as a singl;e removeable plate that can easily inserted into and removed from the housing. All components are soldered to the board using througyh hole pins.
>>>>>>> 1da7cd9b6f27ec9448ff12db2db8c97442505bcb

<img width="1033" alt="Screen Shot 2022-08-16 at 3 29 59 PM" src="https://user-images.githubusercontent.com/90986809/184965906-ee1b9666-2f35-472a-a98e-758e20b1be30.png">


<<<<<<< HEAD
### Housing & Waterproofing
A thick PVC is used as the main housing chamber for the sensor's electronic components. The Sensor head and end cap are attached to the main chamber using fitted O rings to ensure a tight waterproof seal. The sensor head optical pathways are made clear and waterproofed using an epoxy, and shaped using a silicone mold. This helps minimize optical deformities in the epoxy and keep electronics like the LEDs and photodiode sealed. Other 3D printed components are coated with epoxy to ensure no water is leaking into the system and helps improve the rigidity of the components. Wires are fed into the housing using the BLUE ROBOTICS wetlink penetrator.
=======
### Housing & Waterproofing
A thick PVC is used as the main housing chamber for the sensors electronic components. The Sensor head and encap are attached to the main chamber using fitted O rings to ensure a tight waterproof seal. The sensor head optical pathways are made clear and waterproofed using an epoxy, and shaped using a silicone mold. This helps minimize optical deformities in the epoxy and keep elecronics like the LEDs and photodiode sealed. Other 3D printed components are coated with epoxy to ensure no water is leaking into the system and helps improve the rigidity of the components. Wires are fed into the housing using a the BLUE ROBOTICS wetlink penetrator.










>>>>>>> 1da7cd9b6f27ec9448ff12db2db8c97442505bcb
