#include "battery_monitor.h"

BatteryMonitor::BatteryMonitor (int _batteryPin) : batteryPin (_batteryPin) {
}

float BatteryMonitor::rawToVoltage () {
    rawValue = analogRead (batteryPin);
    return rawValue * (REFERENCE_VOLTAGE / MAX_RAW_VALUE);
}

float BatteryMonitor::getBatteryVoltage () {
    return rawToVoltage () * (RESISTOR_2 / (RESISTOR_1 + RESISTOR_2));
}

// TODO: Implement a more accurate battery percentage calculation
int BatteryMonitor::getBatteryPercentage () {
    batteryVoltage = getBatteryVoltage ();
    return ((getBatteryVoltage () - MIN_BATTERY_VOLTAGE) /
           (MAX_BATTERY_VOLTAGE - MIN_BATTERY_VOLTAGE)) *
    100;
}