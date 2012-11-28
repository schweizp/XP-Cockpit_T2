#ifndef ENCODER_H
#define ENCODER_H

// defines
#define RESOLUTION 4

// for syntax highlighting purposes
#include "elapsedMillis.h"
#include "usb_api.h"
#include <Encoder.h>

// includes
//#include "pushbutton.h"

// hardware objects
Encoder     setAlt(0, 27);          // Encoder AP altitude
Encoder     setHdg_2(1, 3);         // Encoder AP heading
Encoder     setSpeed(2, 4);         // Encoder AP speed
Encoder     setVertSpeed(18, 19);   // Encoder AP vertical sped

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

long enc1           = 0;    // actual encoder readings
long enc2           = 0;
long enc3           = 0;
long enc4           = 0;

elapsedMillis e_millis;
unsigned long last_millis   = 0;
unsigned long act_millis    = 0;
unsigned long diff_millis   = 0;

unsigned int accel = 0;

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

    // read altitude encoder and send
    // commands to simulator
    enc1 = setAlt.read();
    if (enc1 > alt_enc + RESOLUTION)
    {
        // store elapsed milliseconds
        act_millis = e_millis;
        diff_millis = act_millis - last_millis;
        if (diff_millis > 1000)                 // more thanv1000ms since last call
        {
            APAltUp.once();                     // normal one step change
        }
        else                                    // less than 1000ms since last call
        {
            accel = (1000 / (diff_millis/3));   // acceleration alg. (prevents prolonged turning of enc.)
            while (accel >= 0)
            {
                APAltUp.once();
                accel--;
            }
        }
        alt_enc = enc1;
        last_millis = act_millis;               // store elapsed millis for next call

    }
    else if (enc1 < alt_enc - RESOLUTION)
    {
        // store elapsed milliseconds
        act_millis = e_millis;
        diff_millis = act_millis - last_millis;
        if (diff_millis > 1000)                 // more than 1000ms since last call
        {
            APAltDown.once();                   // normal one step change
        }
        else                                    // less than 1000ms since last call
        {
            accel = (1000 / (diff_millis/3));   // acceleration alg. (prevents prolonged turning of enc.)
            while (accel >= 0)
            {
                APAltDown.once();
                accel--;
            }
        }
        alt_enc = enc1;
        last_millis = act_millis;               // store elapsed millis for next call

    }

}


#endif // ENCODER_H
