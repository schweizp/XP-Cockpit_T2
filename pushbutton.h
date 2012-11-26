#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

// for syntax highlighting purposes
#include "usb_api.h"
#include <Bounce.h>

//includes

Bounce      shift_1(8, 10);         // COM1 shift big to small increment

// X-Plane objects
FlightSimCommand COM1StdbyFlip;

// variables

// declarations


// setup function is called once when Teensy boots up
void setup_pushbutton()
{
    // initialize hardware
    pinMode(8, INPUT_PULLUP);

    // configure the X-plane variables
    COM1StdbyFlip = XPlaneRef("sim/radios/com1_standy_flip");
}

// loop functions is called repeatedly as long as Teensy is powered up
void loop_pushbutton()
{
    // gets state of encoder pushbuttons and sets
    // corresponding booleans acordingly
    if (shift_1.update())
        if (shift_1.fallingEdge())
        {
            com1_big = !com1_big;
            update_lcd(0);
        }

    // gets state of Act/Stdby buttons and
    // sends command to simulator
    if (act_stdby_1.update())
        if (act_stdby_1.fallingEdge())
            COM1StdbyFlip.once();
    if (act_stdby_2.update())
        if (act_stdby_2.fallingEdge())
            NAV1StdbyFlip.once();
    if (act_stdby_3.update())
        if (act_stdby_3.fallingEdge())
            COM2StdbyFlip.once();
    if (act_stdby_4.update())
        if (act_stdby_4.fallingEdge())
            NAV2StdbyFlip.once();
    if (act_stdby_5.update())
        if (act_stdby_5.fallingEdge())
            ADFStdbyFlip.once();


}



#endif // PUSHBUTTON_H
