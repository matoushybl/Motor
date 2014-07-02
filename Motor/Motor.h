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


#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

#define STOP 0
#define NONSTOP 10

class Motor
{
  public:
    Motor(int aen, int ben, int afor, int arev, int bfor, int brev);

    void setMode(int mode);
	void left();
	void leftStop();
	void leftReverse();
	void right();
	void rightStop();
	void rightReverse();
	void forward();
	void backward();
	void stop();
	void setLeftSpeed(int speed);
	void setRightSpeed(int speed);
	void setGlobalSpeed(int speed);
	void rotateLeft();
	void rotateRight();

    private:
    int AEN;
    int BEN;
	int AFOR;
	int AREV;
	int BFOR;
	int BREV;
    int Mode;
    
};

#endif
