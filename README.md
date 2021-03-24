# CyberGarden-Controller-Firmware
Firmware for Particle Argon microcontroller to process sensor data

Currently, the firmware reads values from 3 capacitive moisture sensors through 3 analog input pins every 30 minutes. These values are then placed into a String buffer and then sent to an IOT Hub in Microsoft Azure using the "publish" function.

Over the next few weeks, the firmware will be updated to read an I2C temperature sensor and control solenoid valves to administer water, fertilizer, and soil pH altering chemicals.
