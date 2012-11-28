#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

// for syntax highlighting purposes
#include "usb_api.h"
#include <Bounce.h>

//includes

Bounce  pbaudioCOM1(20, 10);        // Audio COM1
Bounce  pbaudioCOM2(21, 10);        // Audio COM2
Bounce  pbaudioNAV1(22, 10);        // Audio NAV1
Bounce  pbaudioNAV2(23, 10);        // Audio NAV2
Bounce  pbaudioADF1(24, 10);        // Audio ADF1
Bounce  pbapilotNAV1(5, 10);        // AP NAV1 select
Bounce  pbapilotNAV2(7, 10);        // AP NAV2 select
Bounce  pbapilotHeading(8, 10);     // AP Heading select
Bounce  pbapilotAltitude(9, 10);    // AP Altitude select
Bounce  pbapilotVertSpeed(10, 10);      // AP Speed select
Bounce  pbapilotGlideSlope(11, 10);        // AP GPS select

// X-Plane objects
FlightSimCommand AudioCOM1;
FlightSimCommand AudioCOM2;
FlightSimCommand AudioNAV1;
FlightSimCommand AudioNAV2;
FlightSimCommand AudioADF1;
FlightSimCommand HSI_NAV1;
FlightSimCommand HSI_NAV2;
FlightSimCommand AP_NAV;
FlightSimCommand AP_Heading;
FlightSimCommand AP_Altitude;
FlightSimCommand AP_VertSpeed;
FlightSimCommand AP_GlideSlope;

// variables

// declarations


// setup function is called once when Teensy boots up
void setup_pushbutton()
{
    // initialize hardware
    pinMode(20, INPUT_PULLUP);
    pinMode(21, INPUT_PULLUP);
    pinMode(22, INPUT_PULLUP);
    pinMode(23, INPUT_PULLUP);
    pinMode(24, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);


    // configure the X-plane variables
    AudioCOM1       = XPlaneRef("sim/audio_panel/select_audio_com1");
    AudioCOM2       = XPlaneRef("sim/audio_panel/select_audio_com2");
    AudioNAV1       = XPlaneRef("sim/audio_panel/select_audio_nav1");
    AudioNAV2       = XPlaneRef("sim/audio_panel/select_audio_nav2");
    AudioADF1       = XPlaneRef("sim/audio_panel/select_audio_adf1");
    HSI_NAV1        = XPlaneRef("sim/autopilot/hsi_select_nav_1");
    HSI_NAV2        = XPlaneRef("sim/autopilot/hsi_select_nav_2");
    AP_NAV          = XPlaneRef("sim/autopilot/vnav");
    AP_Heading      = XPlaneRef("sim/autopilot/heading");
    AP_Altitude     = XPlaneRef("sim/autopilot/altitude_arm");
    AP_VertSpeed    = XPlaneRef("sim/autopilot/vertical_speed");
    AP_GlideSlope   = XPlaneRef("sim/autopilot/glide_slope");
}

// loop functions is called repeatedly as long as Teensy is powered up
void loop_pushbutton()
{
    // checks actualisation of Audio buttons and
    // sends commands to simulator
    if (pbaudioCOM1.update())
        if (pbaudioCOM1.fallingEdge())
            AudioCOM1.once();
    if (pbaudioCOM2.update())
        if (pbaudioCOM2.fallingEdge())
            AudioCOM2.once();
    if (pbaudioNAV1.update())
        if (pbaudioNAV1.fallingEdge())
            AudioNAV1.once();
    if (pbaudioNAV2.update())
        if (pbaudioNAV2.fallingEdge())
            AudioNAV2.once();
    if (pbaudioADF1.update())
        if (pbaudioADF1.fallingEdge())
            AudioADF1.once();

    // checks actualisation of autopilot buttons and
    // sends commands to simulator
    if (pbapilotNAV1.update())
        if (pbapilotNAV1.fallingEdge())
        {
            HSI_NAV1.once();
            AP_NAV.once();
        }
    if (pbapilotNAV2.update())
        if (pbapilotNAV2.fallingEdge())
        {
            HSI_NAV2.once();
            AP_NAV.once();
        }
    if (pbapilotHeading.update())
        if (pbapilotHeading.fallingEdge())
            AP_Heading.once();
    if (pbapilotAltitude.update())
        if (pbapilotAltitude.fallingEdge())
            AP_Altitude.once();
    if (pbapilotVertSpeed.update())
        if (pbapilotVertSpeed.fallingEdge())
            AP_VertSpeed.once();
    if (pbapilotGlideSlope.update())
        if (pbapilotGlideSlope.fallingEdge())
            AP_GlideSlope.once();
}



#endif // PUSHBUTTON_H
