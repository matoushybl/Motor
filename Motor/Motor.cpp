/*
 Motor library for l298 module

 The MIT License (MIT)

Copyright (c) 2014 Matouš Hýbl

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include "Arduino.h"
#include "Motor.h"

/*
 * Basic constructor
 * A - left motor
 * B - right motor
 * EN - Enabling pins - must be connected to PWM
 */
Motor::Motor(int aen, int ben, int afor, int arev, int bfor, int brev) {
	AEN = aen;
	BEN = ben;
	AFOR = afor;
	BFOR = bfor;
	BREV = brev;
	AREV = arev;
	pinMode(aen, OUTPUT);
	pinMode(ben, OUTPUT);
	pinMode(afor, OUTPUT);
	pinMode(arev, OUTPUT);
	pinMode(bfor, OUTPUT);
	pinMode(brev, OUTPUT);
	Mode = 1;
}

/*
 * If mode is STOP motors stop when a different movement method is called
 * i.e. if left motor is on and method right is called, left method stops
 * other possible param - NONSTOP
 */
void Motor::setMode(int mode) {
	if (mode == 0) {
		Mode = 0;
	} else
		Mode = 1;
}

/*
 * Stop both motors
 */
void Motor::stop() {
	digitalWrite(AFOR, LOW);
	digitalWrite(BFOR, LOW);
	digitalWrite(AREV, LOW);
	digitalWrite(BREV, LOW);

}

/*
 * Move both motors forward
 */
void Motor::forward() {
	digitalWrite(BFOR, HIGH);
	digitalWrite(AFOR, HIGH);
	if (Mode == 0) {
		digitalWrite(AREV, LOW);
		digitalWrite(BREV, LOW);
	}
}

/*
 * Move only left motor forward
 */
void Motor::left() {
	digitalWrite(AFOR, HIGH);
	if (Mode == 0) {
		digitalWrite(BFOR, LOW);
		digitalWrite(AREV, LOW);
		digitalWrite(BREV, LOW);
	}
}

/*
 * Stop left motor only
 */
void Motor::leftStop() {
	digitalWrite(AFOR, LOW);
	digitalWrite(AREV, LOW);
}

/*
 * Move left motor backward
 */
void Motor::leftReverse() {
	digitalWrite(AREV, HIGH);
	if (Mode == 0) {
		digitalWrite(BFOR, LOW);
		digitalWrite(AFOR, LOW);
		digitalWrite(BREV, LOW);
	}
}

/*
 * Move only right motor forward
 */
void Motor::right() {
	digitalWrite(BFOR, HIGH);
	if (Mode == 0) {
		digitalWrite(AFOR, LOW);
		digitalWrite(AREV, LOW);
		digitalWrite(BREV, LOW);
	}
}

/*
 * Stop right motor only
 */
void Motor::rightStop() {
	digitalWrite(BFOR, LOW);
	digitalWrite(BREV, LOW);
}

/*
 * Move left motor backward
 */
void Motor::rightReverse() {
	digitalWrite(BREV, HIGH);
	if (Mode == 0) {
		digitalWrite(BFOR, LOW);
		digitalWrite(AFOR, LOW);
		digitalWrite(AREV, LOW);
	}
}

/*
 * Move both motors backward
 */
void Motor::backward() {
	digitalWrite(BREV, HIGH);
	digitalWrite(AREV, HIGH);
	if (Mode == 0) {
		digitalWrite(AFOR, LOW);
		digitalWrite(BFOR, LOW);
	}
}

/*
 * Set speed of left motor
 * Range 0-255 - PWM
 */
void Motor::setLeftSpeed(int speed) {
	analogWrite(AEN, speed);
}

/*
 * Set speed of right motor
 * Range 0-255 - PWM
 */
void Motor::setRightSpeed(int speed) {
	analogWrite(BEN, speed);
}

/*
 * Set speed of both motors
 * Range 0-255 - PWM
 */
void Motor::setGlobalSpeed(int speed) {
	analogWrite(AEN, speed);
	analogWrite(BEN, speed);
}

/*
 * Rotate left using both motors - left is going forward, right backward
 */
void Motor::rotateLeft() {
	digitalWrite(BREV, HIGH);
	digitalWrite(AFOR, HIGH);
	if (Mode == 0) {
		digitalWrite(AREV, LOW);
		digitalWrite(BFOR, LOW);
	}
}

/*
 * Rotate left using both motors - right is going forward, left backward
 */
void Motor::rotateRight() {
	digitalWrite(AREV, HIGH);
	digitalWrite(BFOR, HIGH);
	if (Mode == 0) {
		digitalWrite(BREV, LOW);
		digitalWrite(AFOR, LOW);
	}
}
