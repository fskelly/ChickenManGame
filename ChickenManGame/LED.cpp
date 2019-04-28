#include "LED.h"

void LED::begin() {
    pinMode(LED_PIN_R, OUTPUT);
    pinMode(LED_PIN_G, OUTPUT);
    pinMode(LED_PIN_B, OUTPUT);

    setColor(1, 1, 1);
}

void LED::setColor(int r, int g, int b) {
    ledR = r ? 1 : 0;
    ledG = g ? 1 : 0;
    ledB = b ? 1 : 0;

    digitalWrite(LED_PIN_R, ledR);
    digitalWrite(LED_PIN_G, ledG);
    digitalWrite(LED_PIN_B, ledB);

    // Serial.printf("color(%d,%d,%d)\n", ledR, ledG, ledB);
}

void LED::setColor(TEAM flag) {
    setColor(flag == RED, flag == GREEN, flag == BLUE);
}

unsigned int LED::blink(unsigned long interval, TEAM flag, unsigned int times) {
    if ((times) && (millis() - lastBlink >= 1000 / interval)) {
        if (blinked) {
            setColor(0, 0, 0);
        }  else {
            if (flag == NO_TEAM) setColor(1, 1, 1);
            else setColor(flag);
        }

        lastBlink = millis();
        blinked   = !blinked;
        return --times;
    }
    return times;
}