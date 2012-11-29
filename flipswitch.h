#ifndef FLIPSWITCH_H
#define FLIPSWITCH_H

// for syntax highlighting purposes
#include "usb_api.h"
#include <Bounce.h>

// hardware objects
Bounce  switchBattery(25, 10);      // Battery switch
Bounce  switchGenerator(26, 10);    // Generator switch
Bounce  switchBeacon(38, 10);       // Beacon switch
Bounce  switchStrobe(39, 10);       // Strobe switch
Bounce  switchNavLight(40, 10);     // Navigation Light switch
Bounce  switchLanding(41, 10);      // Landing light switch
Bounce  switchTaxi(42, 10);         // Taxi light switch
Bounce  switchFuelPump(43, 10);     // Fuel Pump switch
Bounce  switchPitotHeat(44, 10);    // Pitot Heat switch
Bounce  switchAvionics(45, 10);     // Avionics switch

Bounce  switchAutoPilot(12, 10);    // Auto Pilot on/off switch

Bounce  rsIgnitionOff(13,10);       // Ignition rotary switch...
Bounce  rsIgnitionRight(14,10);
Bounce  rsIgnitionLeft(15,10);
Bounce  rsIgnitionBoth(16,10);
Bounce  rsIgnitionStart(17,10);


// X-Plane objects
FlightSimCommand Battery1On;
FlightSimCommand Battery1Off;
FlightSimCommand Battery2On;
FlightSimCommand Battery2Off;
FlightSimCommand Generator1On;
FlightSimCommand Generator1Off;
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

FlightSimCommand FDirOn;
FlightSimCommand FDirServosOn;

FlightSimCommand MagnetosOff;
FlightSimCommand MagnetosLeft1;
FlightSimCommand MagnetosLeft2;
FlightSimCommand MagnetosLeft3;
FlightSimCommand MagnetosLeft4;
FlightSimCommand MagnetosLeft5;
FlightSimCommand MagnetosLeft6;
FlightSimCommand MagnetosLeft7;
FlightSimCommand MagnetosLeft8;
FlightSimCommand MagnetosRight1;
FlightSimCommand MagnetosRight2;
FlightSimCommand MagnetosRight3;
FlightSimCommand MagnetosRight4;
FlightSimCommand MagnetosRight5;
FlightSimCommand MagnetosRight6;
FlightSimCommand MagnetosRight7;
FlightSimCommand MagnetosRight8;
FlightSimCommand MagnetosBoth;
FlightSimCommand EngageStarters;


// setup function is called once when Teensy boots up
void setup_flipswitch()
{
    // initialize hardware pins
    pinMode(25, INPUT_PULLUP);
    pinMode(26, INPUT_PULLUP);
    pinMode(38, INPUT_PULLUP);
    pinMode(39, INPUT_PULLUP);
    pinMode(40, INPUT_PULLUP);
    pinMode(41, INPUT_PULLUP);
    pinMode(42, INPUT_PULLUP);
    pinMode(43, INPUT_PULLUP);
    pinMode(44, INPUT_PULLUP);
    pinMode(45, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);
    pinMode(14, INPUT_PULLUP);
    pinMode(15, INPUT_PULLUP);
    pinMode(16, INPUT_PULLUP);
    pinMode(17, INPUT_PULLUP);

    pinMode(28, OUTPUT);            // LEDs on flipswitches
    pinMode(29, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(34, OUTPUT);
    pinMode(35, OUTPUT);
    pinMode(36, OUTPUT);
    pinMode(37, OUTPUT);
    pinMode(6,  OUTPUT);

    // configure the X-Plane variables
    Battery1On      = XPlaneRef("sim/electrical/battery_1_on");
    Battery1Off     = XPlaneRef("sim/electrical/battery_1_off");
    Battery2On      = XPlaneRef("sim/electrical/battery_2_on");
    Battery2Off     = XPlaneRef("sim/electrical/battery_2_off");
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
    TaxiLightOff    = XPlaneRef("sim/lights/taxi_lights_off");
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

    FDirOn          = XPlaneRef("sim/autopilot/flight_dir_on_only");
    FDirServosOn    = XPlaneRef("sim/autopilot/servos_and_flight_dir_on");

    MagnetosOff     = XPlaneRef("sim/magnetos/magnetos_off");
    MagnetosLeft1   = XPlaneRef("sim/magnetos/magnetos_left_1");
    MagnetosLeft2   = XPlaneRef("sim/magnetos/magnetos_left_2");
    MagnetosLeft3   = XPlaneRef("sim/magnetos/magnetos_left_3");
    MagnetosLeft4   = XPlaneRef("sim/magnetos/magnetos_left_4");
    MagnetosLeft5   = XPlaneRef("sim/magnetos/magnetos_left_5");
    MagnetosLeft6   = XPlaneRef("sim/magnetos/magnetos_left_6");
    MagnetosLeft7   = XPlaneRef("sim/magnetos/magnetos_left_7");
    MagnetosLeft8   = XPlaneRef("sim/magnetos/magnetos_left_8");
    MagnetosRight1  = XPlaneRef("sim/magnetos/magnetos_right_1");
    MagnetosRight2  = XPlaneRef("sim/magnetos/magnetos_right_2");
    MagnetosRight3  = XPlaneRef("sim/magnetos/magnetos_right_3");
    MagnetosRight4  = XPlaneRef("sim/magnetos/magnetos_right_4");
    MagnetosRight5  = XPlaneRef("sim/magnetos/magnetos_right_5");
    MagnetosRight6  = XPlaneRef("sim/magnetos/magnetos_right_6");
    MagnetosRight7  = XPlaneRef("sim/magnetos/magnetos_right_7");
    MagnetosRight8  = XPlaneRef("sim/magnetos/magnetos_right_8");
    MagnetosBoth    = XPlaneRef("sim/magnetos/magnetos_both");
    EngageStarters  = XPlaneRef("sim/engines/engage_starters");

    // Synchronize state of X-plane to flipswitches
    if (switchBattery.read() == LOW)
    {
        digitalWrite(25, LOW);
        Battery1Off.once();
        Battery2Off.once();
    }
    else if (switchBattery.read() == HIGH)
    {
        digitalWrite(25, HIGH);
        Battery1On.once();
        Battery2On.once();
    }
    if (switchGenerator.read() == LOW)
    {
        digitalWrite(26, LOW);
        Generator1Off.once();
        Generator2Off.once();
        Generator3Off.once();
        Generator4Off.once();
        Generator5Off.once();
        Generator6Off.once();
        Generator7Off.once();
        Generator8Off.once();
    }
    else if (switchGenerator.read() == HIGH)
    {
        digitalWrite(26, HIGH);
        Generator1On.once();
        Generator2On.once();
        Generator3On.once();
        Generator4On.once();
        Generator5On.once();
        Generator6On.once();
        Generator7On.once();
        Generator8On.once();

    }
    if (switchBeacon.read() == LOW)
    {
        digitalWrite(30, LOW);
        BeaconOff.once();
    }
    else if (switchBeacon.read() == HIGH)
    {
        digitalWrite(30, HIGH)
        BeaconOn.once();
    }
    if (switchStrobe.read() == LOW)
    {
        digitalWrite(31, LOW);
        StrobeOff.once();
    }
    else if (switchStrobe.read() == HIGH)
    {
        digitalWrite(31, HIGH);
        StrobeOn.once();
    }
    if (switchNavLight.read() == LOW)
    {
        digitalWrite(32, LOW);
        NavLightOff.once();
    }
    else if (switchNavLight.read() == HIGH)
    {
        digitalWrite(32, HIGH);
        NavLightOn.once();
    }
    if (switchLanding.read() == LOW)
    {
        digitalWrite(33, LOW);
        LandingLightOff.once();
    }
    else if (switchLanding.read() == HIGH)
    {
        digitalWrite(33, HIGH);
        LandingLightOn.once();
    }
    if (switchTaxi.read() == LOW)
    {
        digitalWrite(34, LOW);
        TaxiLightOff.once();
    }
    else if (switchTaxi.read() == HIGH)
    {
        digitalWrite(34, HIGH);
        TaxiLightOn.once();
    }
    if (switchFuelPump.read() == LOW)
    {
        digitalWrite(35, LOW);
        FuelPump1Off.once();
        FuelPump2Off.once();
        FuelPump3Off.once();
        FuelPump4Off.once();
        FuelPump5Off.once();
        FuelPump6Off.once();
        FuelPump7Off.once();
        FuelPump8Off.once();
    }
    else if (switchFuelPump.read() == HIGH)
    {
        digitalWrite(35, HIGH);
        FuelPump1On.once();
        FuelPump2On.once();
        FuelPump3On.once();
        FuelPump4On.once();
        FuelPump5On.once();
        FuelPump6On.once();
        FuelPump7On.once();
        FuelPump8On.once();
    }
    if (switchPitotHeat.read() == LOW)
    {
        digitalWrite(36, LOW);
        PitotHeatOff.once();
    }
    else if (switchPitotHeat.read() == HIGH)
    {
        digitalWrite(36, HIGH);
        PitotHeatOn.once();
    }
    if (switchAvionics.read() == LOW)
    {
        digitalWrite(37, LOW);
        AvionicsOff.once();
    }
    else if (switchAvionics.read() == HIGH)
    {
        AvionicsOn.once(37, HIGH);
    }
    if (switchAutoPilot.read() == LOW)
    {
        digitalWrite(6, LOW);
        FDirOn.once();
    }
    else if (switchAutoPilot.read() == HIGH)
    {
        digitalWrite(6, HIGH);
        FDirServosOn.once();
    }
    // read state of input pin for rotary switch and send
    // corresponding command to X-plane
    if (rsIgnitionOff.read() == LOW)
    {
        MagnetosOff.once();
    }
    if (rsIgnitionLeft.read() == LOW)
    {
        MagnetosLeft1.once();
        MagnetosLeft2.once();
        MagnetosLeft3.once();
        MagnetosLeft4.once();
        MagnetosLeft5.once();
        MagnetosLeft6.once();
        MagnetosLeft7.once();
        MagnetosLeft8.once();
    }
    if (rsIgnitionRight.read() == LOW)
    {
        MagnetosRight1.once();
        MagnetosRight2.once();
        MagnetosRight3.once();
        MagnetosRight4.once();
        MagnetosRight5.once();
        MagnetosRight6.once();
        MagnetosRight7.once();
        MagnetosRight8.once();
    }
    if (rsIgnitionBoth.read() == LOW)
    {
        MagnetosBoth.once();
    }
    if (rsIgnitionStart.read() == LOW)
    {
        EngageStarters.once();
    }
}

// loop function is called repeteadtly as long as Teensy is powered
void loop_flipswitch()
{
    // read state of input pins for flipswitches and send corresponding
    // command(s) to X-plane
    if (switchBattery.update())             // battery switch changed
        if (switchBattery.read() == LOW)
        {
            digitalWrite(28, LOW);
            Battery1Off.once();
            Battery2Off.once();
        }
        else if (switchBattery.read() == HIGH)
        {
            digitalWrite(28, HIGH);
            Battery1On.once();
            Battery2On.once();
        }
    if (switchGenerator.update())             // generator switch changed
        if (switchGenerator.read() == LOW)
        {
            digitalWrite(29, LOW);
            Generator1Off.once();
            Generator2Off.once();
            Generator3Off.once();
            Generator4Off.once();
            Generator5Off.once();
            Generator6Off.once();
            Generator7Off.once();
            Generator8Off.once();
        }
        else if (switchGenerator.read() == HIGH)
        {
            digitalWrite(29, HIGH);
            Generator1On.once();
            Generator2On.once();
            Generator3On.once();
            Generator4On.once();
            Generator5On.once();
            Generator6On.once();
            Generator7On.once();
            Generator8On.once();

        }
    if (switchBeacon.update())             // beacon switch changed
        if (switchBeacon.read() == LOW)
        {
            digitalWrite(30, LOW);
            BeaconOff.once();
        }
        else if (switchBeacon.read() == HIGH)
        {
            digitalWrite(30, HIGH);
            BeaconOn.once();
        }
    if (switchStrobe.update())             // strobe switch changed
        if (switchStrobe.read() == LOW)
        {
            digitalWrite(31, LOW);
            StrobeOff.once();
        }
        else if (switchStrobe.read() == HIGH)
        {
            digitalWrite(31, HIGH);
            StrobeOn.once();
        }
    if (switchNavLight.update())             // navlight switch changed
        if (switchNavLight.read() == LOW)
        {
            digitalWrite(32, LOW);
            NavLightOff.once();
        }
        else if (switchNavLight.read() == HIGH)
        {
            digitalWrite(32, HIGH);
            NavLightOn.once();
        }
    if (switchLanding.update())             // landing light switch changed
        if (switchLanding.read() == LOW)
        {
            digitalWrite(33, LOW);
            LandingLightOff.once();
        }
        else if (switchLanding.read() == HIGH)
        {
            digitalWrite(33, HIGH);
            LandingLightOn.once();
        }
    if (switchTaxi.update())                // taxi light switch changed
        if (switchTaxi.read() == LOW)
        {
            digitalWrite(34, LOW);
            TaxiLightOff.once();
        }
        else if (switchTaxi.read() == HIGH)
        {
            digitalWrite(34, HIGH);
            TaxiLightOn.once();
        }
    if (switchFuelPump.update())             // fuel pump switch changed
        if (switchFuelPump.read() == LOW)
        {
            digitalWrite(35, LOW);
            FuelPump1Off.once();
            FuelPump2Off.once();
            FuelPump3Off.once();
            FuelPump4Off.once();
            FuelPump5Off.once();
            FuelPump6Off.once();
            FuelPump7Off.once();
            FuelPump8Off.once();
        }
        else if (switchFuelPump.read() == HIGH)
        {
            digitalWrite(35, HIGH);
            FuelPump1On.once();
            FuelPump2On.once();
            FuelPump3On.once();
            FuelPump4On.once();
            FuelPump5On.once();
            FuelPump6On.once();
            FuelPump7On.once();
            FuelPump8On.once();
        }
    if (switchPitotHeat.update())             // pitot heat switch changed
        if (switchPitotHeat.read() == LOW)
        {
            digitalWrite(36, LOW);
            PitotHeatOff.once();
        }
        else if (switchPitotHeat.read() == HIGH)
        {
            digitalWrite(36, HIGH);
            PitotHeatOn.once();
        }
    if (switchAvionics.update())             // avionics switch changed
        if (switchAvionics.read() == LOW)
        {
            digitalWrite(37, LOW);
            AvionicsOff.once();
        }
        else if (switchAvionics.read() == HIGH)
        {
            digitalWrite(37, HIGH);
            AvionicsOn.once();
        }
    if (switchAutoPilot.update())             // autopilot switch changed
        if (switchAutoPilot.read() == LOW)
        {
            digitalWrite(6, LOW);
            FDirOn.once();
        }
        else if (switchAutoPilot.read() == HIGH)
        {
            digitalWrite(6, HIGH);
            FDirServosOn.once();
        }
    // read state of input pin for rotary switch and send
    // corresponding command to X-plane
    if (rsIgnitionOff.update())             // Ign. Off selected
        if (rsIgnitionOff.read() == LOW)
        {
            MagnetosOff.once();
        }
    if (rsIgnitionLeft.update())             // Ign. Left selected
        if (rsIgnitionLeft.read() == LOW)
        {
            MagnetosLeft1.once();
            MagnetosLeft2.once();
            MagnetosLeft3.once();
            MagnetosLeft4.once();
            MagnetosLeft5.once();
            MagnetosLeft6.once();
            MagnetosLeft7.once();
            MagnetosLeft8.once();
        }
    if (rsIgnitionRight.update())             // Ign. Right selected
        if (rsIgnitionRight.read() == LOW)
        {
            MagnetosRight1.once();
            MagnetosRight2.once();
            MagnetosRight3.once();
            MagnetosRight4.once();
            MagnetosRight5.once();
            MagnetosRight6.once();
            MagnetosRight7.once();
            MagnetosRight8.once();
        }
    if (rsIgnitionBoth.update())             // Ign. Both selected
        if (rsIgnitionBoth.read() == LOW)
        {
            MagnetosBoth.once();
        }
    if (rsIgnitionStart.update())             // Ign. Start selected
        if (rsIgnitionStart.read() == LOW)
        {
            EngageStarters.once();
        }
}


#endif // FLIPSWITCH_H
