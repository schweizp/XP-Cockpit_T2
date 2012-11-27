#ifndef FLIPSWITCH_H
#define FLIPSWITCH_H

// for syntax highlighting purposes
#include "usb_api.h"
#include <Bounce.h>

// hardware objects
Bounce  switchBattery(25, 10);    // Battery switch
Bounce  switchAlternator(26, 10);
Bounce  switchBeacon(19, 10);
Bounce  switchStrobe(18, 10);
Bounce  switchNavLight(38, 10);
Bounce  switchLanding(39, 10);
Bounce  switchTaxi(40, 10);
Bounce  switchFuelPump(41, 10);
Bounce  switchPitotHeat(42, 10);
Bounce  switchAvionics(43, 10);


// X-Plane objects
FlightSimCommand Battery1On;
FlightSimCommand Battery1Off;
FlightSimCommand Battery2On;
FlightSimCommand Battery2Off;
FlightSimCommand Generator1On;
FlightSimCommand Generator12Off;
FlightSimCommand Generator2On;
FlightSimCommand Generator2Off;
FlightSimCommand Generator3On;
FlightSimCommand Generator3Off;
FlightSimCommand Generator4On;
FlightSimCommand Generator4Off;
FlightSimCommand Generator5On;
FlightSimCommand Generator5Off;
FlightSimCommand Generator6On;
FlightSimCommand Generator6Off;
FlightSimCommand Generator7On;
FlightSimCommand Generator7Off;
FlightSimCommand Generator8On;
FlightSimCommand Generator8Off;
FlightSimCommand BeaconOn;
FlightSimCommand BeaconOff;
FlightSimCommand StrobeOn;
FlightSimCommand StrobeOff;
FlightSimCommand NavLightOn;
FlightSimCommand NavLightOff;
FlightSimCommand LandingLightOn;
FlightSimCommand LandingLightOff;
FlightSimCommand TaxiLightOn;
FlightSimCommand TaxiLightOff;
FlightSimCommand FuelPump1On;
FlightSimCommand FuelPump1Off;
FlightSimCommand FuelPump2On;
FlightSimCommand FuelPump2Off;
FlightSimCommand FuelPump3On;
FlightSimCommand FuelPump3Off;
FlightSimCommand FuelPump4On;
FlightSimCommand FuelPump4Off;
FlightSimCommand FuelPump5On;
FlightSimCommand FuelPump5Off;
FlightSimCommand FuelPump6On;
FlightSimCommand FuelPump6Off;
FlightSimCommand FuelPump7On;
FlightSimCommand FuelPump7Off;
FlightSimCommand FuelPump8On;
FlightSimCommand FuelPump8Off;
FlightSimCommand PitotHeatOn;
FlightSimCommand PitotHeatOff;
FlightSimCommand AvionicsOn;
FlightSimCommand AvionicsOff;


// setup function is called once when Teensy boots up
void setup_flipswitch()
{
    // initialize hardware pins
    pinMode(25, INPUT_PULLUP);
    pinMode(26, INPUT_PULLUP);
    pinMode(19, INPUT_PULLUP);
    pinMode(18, INPUT_PULLUP);
    pinMode(38, INPUT_PULLUP);
    pinMode(39, INPUT_PULLUP);
    pinMode(40, INPUT_PULLUP);
    pinMode(41, INPUT_PULLUP);
    pinMode(42, INPUT_PULLUP);
    pinMode(43, INPUT_PULLUP);



    // configure the X-Plane variables
    Battery1On       = XPlaneRef("sim/electrical/battery_1_on");
    Battery1Off      = XPlaneRef("sim/electrical/battery_1_off");
    Battery2On       = XPlaneRef("sim/electrical/battery_2_on");
    Battery2Off      = XPlaneRef("sim/electrical/battery_2_off");
    Generator1On    = XPlaneRef("sim/electrical/generator_1_on");
    Generator1Off   = XPlaneRef("sim/electrical/generator_1_off");
    Generator2On    = XPlaneRef("sim/electrical/generator_2_on");
    Generator2Off   = XPlaneRef("sim/electrical/generator_2_off");
    Generator3On    = XPlaneRef("sim/electrical/generator_3_on");
    Generator3Off   = XPlaneRef("sim/electrical/generator_3_off");
    Generator4On    = XPlaneRef("sim/electrical/generator_4_on");
    Generator4Off   = XPlaneRef("sim/electrical/generator_4_off");
    Generator5On    = XPlaneRef("sim/electrical/generator_5_on");
    Generator5Off   = XPlaneRef("sim/electrical/generator_5_off");
    Generator6On    = XPlaneRef("sim/electrical/generator_6_on");
    Generator6Off   = XPlaneRef("sim/electrical/generator_6_off");
    Generator7On    = XPlaneRef("sim/electrical/generator_7_on");
    Generator7Off   = XPlaneRef("sim/electrical/generator_7_off");
    Generator8On    = XPlaneRef("sim/electrical/generator_8_on");
    Generator8Off   = XPlaneRef("sim/electrical/generator_8_off");
    BeaconOn        = XPlaneRef("sim/lights/beacon_lights_on");
    BeaconOff       = XPlaneRef("sim/lights/beacon_lights_off");
    StrobeOn        = XPlaneRef("sim/lights/strobe_lights_on");
    StrobeOff       = XPlaneRef("sim/lights/strobe_lights_off");
    NavLightOn      = XPlaneRef("sim/lights/nav_lights_on");
    NavLightOff     = XPlaneRef("sim/lights/nav_lights_off");
    LandingLightOn  = XPlaneRef("sim/lights/landing_lights_on");
    LandingLightOff = XPlaneRef("sim/lights/landing_lights_off");
    TaxiLightOn     = XPlaneRef("sim/lights/taxi_lights_on");
    TaxiLightOff     = XPlaneRef("sim/lights/taxi_lights_off");
    FuelPump1On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump1Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump2On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump2Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump3On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump3Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump4On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump4Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump5On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump5Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump6On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump6Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump7On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump7Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    FuelPump8On     = XPlaneRef("sim/fuel/fuel_pump_1_on");
    FuelPump8Off    = XPlaneRef("sim/fuel/fuel_pump_1_off");
    PitotHeatOn     = XPlaneRef("sim/ice/pitot_heat_on");
    PitotHeatOff    = XPlaneRef("sim/ice/pitot_heat_off");
    AvionicsOn      = XPlaneRef("sim/systems/avionics_on");
    AvionicsOff     = XPlaneRef("sim/systems/avionics_on");
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
