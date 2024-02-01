#include <LiquidCrystal.h>

// LCD Initialization
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

// Sensor and Actuator Pins
int sensorPin = A0;    // Soil moisture sensor
int ledPin = 3;        // LED
int relayPin = 2;      // Relay for water pump
int buzzerPin = 12;    // Buzzer
const int TriggerPin = 11;
const int EchoPin = 10;
const int buttonPin = 13; // Button connected to pin 13

void setup() {
    lcd.begin(16, 2); // Set up the LCD's number of columns and rows
    pinMode(ledPin, OUTPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP); // Set the button as an input with internal pull-up
    Serial.begin(9600);
}

void loop() {
    // Read soil moisture level and calculate percentage
    int sensorValue = analogRead(sensorPin);
    int smPercent = map(sensorValue, 0, 1019, 0, 100); // Convert soil moisture to percentage

    // Ultrasonic sensor measurement for water level and calculate percentage
    digitalWrite(TriggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);
    long duration = pulseIn(EchoPin, HIGH);
    int distance = duration * 0.034 / 2; // Calculate the distance
    int wlPercent = map(distance, 4, 1106, 0, 100); // Convert water level to percentage

    // Display WL and SM percentages on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WL: ");
    lcd.print(wlPercent);
    lcd.print("%  SM: ");
    lcd.print(smPercent);
    lcd.print("%");

    Serial.print("Moisture Level: ");
    Serial.println(sensorValue);
    Serial.print("Water Level (cm): ");
    Serial.println(distance);

    bool noWater = distance <= 4; // Assume no water if distance is less than or equal to 4 cm
    if (noWater) {
        digitalWrite(buzzerPin, HIGH); // Activate buzzer
        lcd.setCursor(0, 1);
        lcd.print("No Water!");
        Serial.println("No Water!");
    } else {
        digitalWrite(buzzerPin, LOW); // Deactivate buzzer
    }

    // Manual Pump Control
    if (digitalRead(buttonPin) == LOW && !noWater) { // Button is pressed and there is water
        digitalWrite(relayPin, HIGH); // Turn on the relay (pump)
        digitalWrite(ledPin, HIGH); // Turn on the LED
        lcd.setCursor(0, 1);
        lcd.print("Manual Irrigation");
        Serial.println("Manual Irrigation");
    }
    // Automatic Pump Control based on sensor readings
    else if (sensorValue < 300 && !noWater) {
        digitalWrite(relayPin, HIGH); // Turn on the relay (pump)
        digitalWrite(ledPin, HIGH); // Turn on the LED
        lcd.setCursor(0, 1);
        lcd.print("Auto Irrigating...");
        Serial.println("Auto Irrigating...");
    } else {
        // Turn off the pump and LED when button is not pressed, or there is no water
        digitalWrite(relayPin, LOW); 
        digitalWrite(ledPin, LOW);
        lcd.setCursor(0, 1);
        lcd.print("No Irrigation");
        Serial.println("No Irrigation");
    }

    delay(100); // Short delay for button debounce
}
