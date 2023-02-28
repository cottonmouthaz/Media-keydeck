// Copyright 2023 SausageMods
// Thanks to Sanjay900 for being a genius
#include <Arduino.h>
#include <NSEncoder.h>
#include <HID-Project.h>
// Key mapping
const int pinRotaryEncoderA = 0;
const int pinRotaryEncoderB = 1;
const int pinPlayPause = 2;
const int pinPrevious = 3;
const int pinNext = 4;
const int pinKeyF13 = 5;
const int pinKeyF14 = 6;
const int pinKeyF15 = 7;
const int pinKeyF16 = 8;
const int pinKeyF17 = 9;
const int pinKeyF18 = 10;

// Debounce variables
unsigned long lastDebounceTime[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int debounceDelay = 50;
const int encoderDelay = 40;
int keyState[11] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, 0};

Encoder myEnc(0, 1);
long oldPosition = 0;
long distance = 5;
void setup() {
    // Set up the key pins as inputs with pull-up resistors
    pinMode(pinPlayPause, INPUT_PULLUP);
    pinMode(pinPrevious, INPUT_PULLUP);
    pinMode(pinNext, INPUT_PULLUP);
    pinMode(pinRotaryEncoderA, INPUT_PULLUP);
    pinMode(pinRotaryEncoderB, INPUT_PULLUP);
    pinMode(pinKeyF13, INPUT_PULLUP);
    pinMode(pinKeyF14, INPUT_PULLUP);
    pinMode(pinKeyF15, INPUT_PULLUP);
    pinMode(pinKeyF16, INPUT_PULLUP);
    pinMode(pinKeyF17, INPUT_PULLUP);
    pinMode(pinKeyF18, INPUT_PULLUP);

    // Begin the Consumer & Keyboard API
    Consumer.begin();
    Keyboard.begin();
}

void loop() {
    long newPosition = myEnc.read();
    if (newPosition - oldPosition > distance) {
        oldPosition = newPosition;
        Consumer.write(MEDIA_VOLUME_UP);
    }
    if (oldPosition - newPosition > distance) {
        oldPosition = newPosition;
        Consumer.write(MEDIA_VOLUME_DOWN);
    }
    // Check if the play/pause key is pressed
    if (digitalRead(pinPlayPause) != keyState[0]) {
        if ((millis() - lastDebounceTime[0]) > debounceDelay) {
            keyState[0] = digitalRead(pinPlayPause);
            lastDebounceTime[0] = millis();
            if (keyState[0] == LOW) {
                Consumer.write(MEDIA_PLAY_PAUSE);
            }
        }
    }

    // Check if the previous track key is pressed
    if (digitalRead(pinPrevious) != keyState[1]) {
        if ((millis() - lastDebounceTime[1]) > debounceDelay) {
            keyState[1] = digitalRead(pinPrevious);
            lastDebounceTime[1] = millis();
            if (keyState[1] == LOW) {
                Consumer.write(MEDIA_PREVIOUS);
            }
        }
    }

    // Check if the next track key is pressed
    if (digitalRead(pinNext) != keyState[2]) {
        if ((millis() - lastDebounceTime[2]) > debounceDelay) {
            keyState[2] = digitalRead(pinNext);
            lastDebounceTime[2] = millis();
            if (keyState[2] == LOW) {
                Consumer.write(MEDIA_NEXT);
            }
        }
    }

    // Check if the F13 key is pressed
    if (digitalRead(pinKeyF13) != keyState[3]) {
        if ((millis() - lastDebounceTime[3]) > debounceDelay) {
            keyState[3] = digitalRead(pinKeyF13);
            lastDebounceTime[3] = millis();
            if (keyState[3] == LOW) {
                Keyboard.write(KEY_F13);
            }
        }
    }

    // Check if the F14 key is pressed
    if (digitalRead(pinKeyF14) != keyState[4]) {
        if ((millis() - lastDebounceTime[4]) > debounceDelay) {
            keyState[4] = digitalRead(pinKeyF14);
            lastDebounceTime[4] = millis();
            if (keyState[4] == LOW) {
                Keyboard.write(KEY_F14);
            }
        }
    }

    // Check if the F15 key is pressed
    if (digitalRead(pinKeyF15) != keyState[5]) {
        if ((millis() - lastDebounceTime[5]) > debounceDelay) {
            keyState[5] = digitalRead(pinKeyF15);
            lastDebounceTime[5] = millis();
            if (keyState[5] == LOW) {
                Keyboard.write(KEY_F15);
            }
        }
    }

    // Check if the F16 key is pressed
    if (digitalRead(pinKeyF16) != keyState[6]) {
        if ((millis() - lastDebounceTime[6]) > debounceDelay) {
            keyState[6] = digitalRead(pinKeyF16);
            lastDebounceTime[6] = millis();
            if (keyState[6] == LOW) {
                Keyboard.write(KEY_F16);
            }
        }
    }

    // Check if the F17 key is pressed
    if (digitalRead(pinKeyF17) != keyState[7]) {
        if ((millis() - lastDebounceTime[7]) > debounceDelay) {
            keyState[7] = digitalRead(pinKeyF17);
            lastDebounceTime[7] = millis();
            if (keyState[7] == LOW) {
                Keyboard.write(KEY_F17);
            }
        }
    }

    // Check if the F18 key is pressed
    if (digitalRead(pinKeyF18) != keyState[8]) {
        if ((millis() - lastDebounceTime[8]) > debounceDelay) {
            keyState[8] = digitalRead(pinKeyF18);
            lastDebounceTime[8] = millis();
            if (keyState[8] == LOW) {
                Keyboard.write(KEY_F18);
            }
        }
    }
}