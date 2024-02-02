# Automated Irrigation System

This Arduino project implements an Automated Irrigation System using soil moisture and water level sensors. The system continuously monitors soil moisture and water level, displaying the percentage values on a 16x2 LCD. It features manual irrigation control with a button and automatic irrigation based on predefined soil moisture thresholds.

## Components Used
- Soil Moisture Sensor
- Ultrasonic Sensor (for water level measurement)
- 16x2 LCD
- LED
- Relay (water pump control)
- Buzzer
- Push Button

## Pin Configuration
- LCD: 9, 8, 7, 6, 5, 4
- Soil Moisture Sensor: A0
- LED: 3
- Relay: 2
- Buzzer: 12
- Ultrasonic Sensor (Trigger/Echo): 11, 10
- Button: 13

## Features
- Real-time display of soil moisture and water level percentages on the LCD.
- Manual irrigation control using a push button.
- Automatic irrigation based on soil moisture levels.
- Buzzer alert for low water levels.

## Usage
1. Connect the sensors and components as per the defined pin configuration.
2. Upload the provided Arduino sketch to your board.
3. Monitor soil moisture and water level percentages on the LCD.
4. Press the button for manual irrigation when needed.
5. Enjoy an automated irrigation system based on soil moisture thresholds.

## Simulation
![Simulation](/Circuit_Design.png)

## Proteus Sketch
![Proteus Sketch](/Proteus_Design.png)

Feel free to contribute, enhance, or customize the code to meet your specific needs. Ensure proper calibration of sensors for accurate readings. Happy gardening! 🌱🚿
