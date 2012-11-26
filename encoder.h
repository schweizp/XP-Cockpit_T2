#ifndef ENCODER_H
#define ENCODER_H

// defines
#define RESOLUTION 4

// for syntax highlighting purposes
#include "usb_api.h"
#include <Encoder.h>

// includes
//#include "pushbutton.h"

// hardware objects
Encoder     setAlt(0, 27);      // Encoder AP altitude
Encoder     setHdg_2(1, 3);     // Encoder AP heading
Encoder     setSpeed(2, 4);     // Encoder AP speed
Encoder     setVertSpeed(X, X);  // Encoder AP vertical sped

// X-Plane objects
FlightSimCommand    APAltUp;
FlightSimCommand    APAltDown;
FlightSimCommand    APHdgUp;
FlightSimCommand    APHdgDown;
FlightSimCommand    APSpeedUp;
FlightSimCommand    APSpeedDown;
FlightSimCommand    APVertSpeedUp;
FlightSimCommand    APVertSpeedDown;

// variables
long alt_enc        = 0;    // old encoder readings
long hdg_enc        = 0;
long speed_enc      = 0;
long vertspeed_enc  = 0;

long enc1 = 0;              // actual encoder readings
long enc2 = 0;
long enc3 = 0;
long enc4 = 0;

// setup function is called once when Teensy boots up
void setup_encoder()
{
    // configure the X-Plane variables
    APAltUp         =  XPlaneRef("sim/autopilot/altitude_up");
    APAltDown       =  XPlaneRef("sim/autopilot/altitude_down");
    APHdgUp         =  XPlaneRef("sim/autopilot/heading_up");
    APHdgDown       =  XPlaneRef("sim/autopilot/heading_down");
    APSpeedUp       =  XPlaneRef("sim/autopilot/airspeed_up");
    APSpeedDown     =  XPlaneRef("sim/autopilot/airspeed_down");
    APVertSpeedUp   =  XPlaneRef("sim/autopilot/vertical_speed_up");
    APVertSpeedDown =  XPlaneRef("sim/autopilot/vertical_speed_up");

}

// loop function is called repeatedly as long as Teensy is powered
void loop_encoder()
{

    // read COM1 encoder and send
    // commands to simulator
    enc1 = wheel_1.read();
    if (enc1 > com1_enc + RESOLUTION)
    {
        if (com1_big)
            COM1CoarseUp.once();
        else
            COM1FineUp.once();
        com1_enc = enc1;
    }
    else if (enc1 < com1_enc - RESOLUTION)
    {
        if (com1_big)
            COM1CoarseDown.once();
        else
            COM1FineDown.once();
        com1_enc = enc1;
    }

}


#endif // ENCODER_H
