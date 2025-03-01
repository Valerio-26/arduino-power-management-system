#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H
#include <Arduino.h>

#define MIN_BATTERY_VOLTAGE 6     // real 0%
#define MAX_BATTERY_VOLTAGE 8.4   // real 100%
#define MIN_BATTERY_PERCENTAGE 15 // Secure cut-off
#define MAX_RAW_VALUE 1023
#define REFERENCE_VOLTAGE 5 // Arduino reference voltage
#define RESISTOR_1 10000.0  // 10k resistor
#define RESISTOR_2 6800.0   // 6.8k resistor


class BatteryMonitor {
    private:
    int batteryPin;
    int rawValue;
    float batteryVoltage;

    public:
    BatteryMonitor (int _batteryPin);
    float rawToVoltage ();
    float getBatteryVoltage ();
    int getBatteryPercentage ();
};


#endif
