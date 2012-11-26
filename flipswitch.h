#ifndef FLIPSWITCH_H
#define FLIPSWITCH_H

// for syntax highlighting purposes
#include "usb_api.h"
#include <Bounce.h>

// hardware objects
Bounce        tModeOff(28, 10);                    // Transponder rotary switch Mode selector...

// X-Plane objects
FlightSimCommand TransponderOFF;

// setup function is called once when Teensy boots up
void setup_flipswitch()
{
    // initialize hardware pins
    pinMode(28, INPUT_PULLUP);

    // configure the X-Plane variables
    TransponderOFF = XPlaneRef("sim/transponder/transponder_off");
}

// loop function is called repeteadtly as long as Teensy is powered
void loop_flipswitch()
{
    // read state of input pins and set corresponding
    // state in X-Pane variable
    if (tModeOff.update())
        if (tModeOff.read() == LOW)
            TransponderOFF.once();
}


#endif // FLIPSWITCH_H
