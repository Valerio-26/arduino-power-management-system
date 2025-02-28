#include<Arduino.h>
#include "board_config.h"

float readBatteryVoltage();
float readBatteryPercentage();


void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(BUTTON_LED_PIN, OUTPUT);
    pinMode(BATTERY_VOLTAGE_PIN, INPUT);
    pinMode(POWER_MOSFET_PIN, OUTPUT);
}

void loop() {
    if(readBatteryPercentage() < 20) {
        digitalWrite(POWER_MOSFET_PIN, LOW);
    } else {
        digitalWrite(POWER_MOSFET_PIN, HIGH);
        digitalWrite(BUTTON_LED_PIN, HIGH);
    }
}

float readBatteryVoltage() {
    return analogRead(BATTERY_VOLTAGE_PIN) * 0.0048828125;
}

float readBatteryPercentage() {
    float voltage = readBatteryVoltage();
    if(voltage < 3.5) {
        return 0;
    } else {
        return (voltage - 3.5) / 1.2 * 100;
    }
}