/*
 Copyright (c) 2010 bildr community
 Ported to mbed by mimilowns

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

#ifndef Thermal_h
#define Thermal_h

#include "mbed.h"



class Thermal : public Serial

{

  public:
    Thermal(PinName tx, PinName rx, int baud = 9600);
    
    void setDefault();
    void test();



    void inverseOn();
    void inverseOff();
    void doubleHeightOn();
    void doubleHeightOff();
    void boldOn();
    void boldOff();
    void underlineOn();
    void underlineOff();



    void justify(char value);
    void feed(uint8_t x = 1);
    void sleep();
    void wake();



    void setCharSpacing(int spacing);
    void setSize(char value);
    void setLineHeight(int val = 32);



    void printBarcode(char * text);
    void printFancyBarcode(char * text);
    void setBarcodeHeight(int val);



    void printBitmap(uint8_t w, uint8_t h,  const uint8_t *bitmap);

    // ??
    void tab();



    void setHeatTime(int vHeatTime);

    void setHeatInterval(int vHeatInterval);

    void setPrintDensity(char vPrintDensity);

    void setPrintBreakTime(char vPrintBreakTime);

    
  private:
    bool linefeedneeded;


    // little helpers to make code easier to read&use
    void writeBytes(uint8_t a, uint8_t b);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
    
    // port from arduino serial to mbed serial
    void write(uint8_t a);
    void delay(uint8_t a);

    int zero;


    int heatTime;
    int heatInterval;
    char printDensity;
    char printBreakTime;
};

#endif
