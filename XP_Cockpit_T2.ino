// Cockpit for X-Plane using Teensy++ 2.0 Boards
//
// Version 0.40
// by Philemon Schweizer
//
// Teensy Board No.2
//
// Power / Light-Switches
// Flight director / Autopilot
// Ignition / Magntos
//
//


// for syntax highlighting purposes
#include "usb_api.h"

// include the different specialized coding parts
#include "pushbutton.h"
#include "encoder.h"
#include "flipswitch.h"


#include <Bounce.h>
#include <Encoder.h>
#include <LiquidCrystal.h>


// setup runs once, when Teensy boots.
void setup()
{
    // call setup functions of the
    // different modules
    setup_encoder();
    setup_flipswitch();
    setup_pushbutton();
}

// loop runs repetitively, as long as Teensy is powered up
void loop()
{

    // normally the first step in loop() should update from X-Plane
    FlightSim.update();

    // call loop functions of the
    // different modules
    loop_encoder();
    loop_flipswitch();
    loop_pushbutton();

}

