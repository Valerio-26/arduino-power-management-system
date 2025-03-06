#include "battery_monitor.h"
#include "board_config.h"
#include <Arduino.h>
#include <PKAE_Timer.h>

void powerOff ();

// BatteryMonitor batteryMonitor (BATTERY_VOLTAGE_PIN);

void setup () {
    Serial.begin (115200);
    pinMode (BUTTON_PIN, INPUT_PULLUP);
    pinMode (BUTTON_LED_PIN, OUTPUT);
    pinMode (POWER_MOSFET_PIN, OUTPUT);
    pinMode (BUZZER_PIN, OUTPUT);
    digitalWrite (POWER_MOSFET_PIN, HIGH);
}

void loop () {
    boolean lLEDstate = LOW;
    boolean lReleased = true;

    PKAE_Timer StableLED (300);
    PKAE_Timer ButtonHeld (3000);

    digitalWrite (BUZZER_PIN, HIGH);
    delay (500);
    digitalWrite (BUZZER_PIN, LOW);

    while (true) {
        /*if (batteryMonitor.getBatteryPercentage () <= 0) {
            powerOff ();

        }*/

        if (digitalRead (BUTTON_PIN) == LOW) {
            if (lReleased and StableLED.IsTimeUp ()) {
                lLEDstate = !lLEDstate;
                digitalWrite (BUTTON_LED_PIN, lLEDstate);
            }
            lReleased = false;
        } else {
            lReleased = true;
            ButtonHeld.Reset ();
        }
        if (ButtonHeld.IsTimeUp ())
            powerOff ();
    }
}

void powerOff () {
    boolean lLEDstate = LOW;
    PKAE_Timer BlinkLED (100);
    digitalWrite (POWER_MOSFET_PIN, LOW);

    // Rapid flash Onboard LED indicate power about to be lost
    while (true) {
        if (BlinkLED.IsTimeUp ()) {
            lLEDstate = !lLEDstate;
            digitalWrite (BUTTON_LED_PIN, lLEDstate);
        }
    }
}
