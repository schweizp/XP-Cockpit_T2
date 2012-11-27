#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

// for syntax highlighting purposes
#include "usb_api.h"
#include <Bounce.h>

//includes

Bounce  audioCOM1(20, 10);      // Audio COM1
Bounce  audioCOM2(21, 10);      // Audio COM2
Bounce  audioNAV1();
Bounce  audioNAV2();
Bounce  audioADF1();
Bounce  audioADF2();



// X-Plane objects
FlightSimCommand AudioCOM1;
FlightSimCommand AudioCOM2;
FlightSimCommand AudioNAV1;
FlightSimCommand AudioNAV2;
FlightSimCommand AudioADF1;
FlightSimCommand AudioADF2;

// variables

// declarations


// setup function is called once when Teensy boots up
void setup_pushbutton()
{
    // initialize hardware
    pinMode(8, INPUT_PULLUP);

    // configure the X-plane variables
    AudioCOM1 = XPlaneRef("sim/audio_panel/select_audio_com1");
    AudioCOM2 = XPlaneRef("sim/audio_panel/select_audio_com2");
    AudioNAV1 = XPlaneRef("sim/audio_panel/select_audio_nav1");
    AudioNAV2 = XPlaneRef("sim/audio_panel/select_audio_nav2");
    AudioADF1 = XPlaneRef("sim/audio_panel/select_audio_adf1");
    AudioADF2 = XPlaneRef("sim/audio_panel/select_audio_adf2");
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
