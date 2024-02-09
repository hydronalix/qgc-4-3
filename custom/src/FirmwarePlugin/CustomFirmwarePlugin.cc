/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 * @file
 *   @brief Custom Firmware Plugin (PX4)
 *   @author Gus Grubba <gus@auterion.com>
 *
 */

#include "CustomFirmwarePlugin.h"
#include "CustomAutoPilotPlugin.h"
#include "QGCApplication.h"

/* [audible groaning] */
APMHydronalixMode::APMHydronalixMode(uint32_t mode, bool settable)
    : APMCustomMode(mode, settable)
{
    setEnumToStringMapping({
        {MANUAL,         "Manual"},
        {ACRO,           "Acro"},
        {STEERING,       "Steering"},
        {HOLD,           "Hold"},
        {LOITER,         "Loiter"},
        {FOLLOW,         "Follow"},
        {SIMPLE,         "Simple"},
        {AUTO,           "Auto"},
        {RTL,            "RTL"},
        {SMART_RTL,      "Smart RTL"},
        {GUIDED,         "Guided"},
        {INITIALIZING,   "Initializing"},
    });
}

//-----------------------------------------------------------------------------
CustomFirmwarePlugin::CustomFirmwarePlugin()
{
    /* below is the px4 firmware plugin way of setting up flight modes, but we have to do something
     * different for APM stuff
     */
    // for (int i = 0; i < _flightModeInfoList.count(); i++) {
    //     FlightModeInfo_t& info = _flightModeInfoList[i];
    //     //-- Narrow the flight mode options to only these
    //     if (*info.name != _holdFlightMode && *info.name != _rtlFlightMode && *info.name != _missionFlightMode) {
    //         // No other flight modes can be set
    //         info.canBeSet = false;
    //     }
    // }

    /* below is taken from ArduRoverFirmwarePlugin.cc but modified slightly */
    setSupportedModes({
        APMHydronalixMode(APMHydronalixMode::MANUAL       ,true),
        APMHydronalixMode(APMHydronalixMode::ACRO         ,false),
        APMHydronalixMode(APMHydronalixMode::STEERING     ,false),
        APMHydronalixMode(APMHydronalixMode::HOLD         ,false),
        APMHydronalixMode(APMHydronalixMode::LOITER       ,true),
        APMHydronalixMode(APMHydronalixMode::FOLLOW       ,false),
        APMHydronalixMode(APMHydronalixMode::SIMPLE       ,false),
        APMHydronalixMode(APMHydronalixMode::AUTO         ,true),
        APMHydronalixMode(APMHydronalixMode::RTL          ,true),
        APMHydronalixMode(APMHydronalixMode::SMART_RTL    ,true),
        APMHydronalixMode(APMHydronalixMode::GUIDED       ,true),
        APMHydronalixMode(APMHydronalixMode::INITIALIZING ,false),
    });
}

//-----------------------------------------------------------------------------
AutoPilotPlugin* CustomFirmwarePlugin::autopilotPlugin(Vehicle* vehicle)
{
    return new CustomAutoPilotPlugin(vehicle, vehicle);
}

const QVariantList& CustomFirmwarePlugin::toolIndicators(const Vehicle* vehicle)
{
    if (_toolIndicatorList.size() == 0) {
        // First call the base class to get the standard QGC list. This way we are guaranteed to always get
        // any new toolbar indicators which are added upstream in our custom build.
        _toolIndicatorList = FirmwarePlugin::toolIndicators(vehicle);
        // Then specifically remove the RC RSSI indicator.
        // _toolIndicatorList.removeOne(QVariant::fromValue(QUrl::fromUserInput("qrc:/toolbar/RCRSSIIndicator.qml")));

        /* doing this as is in the apm plugin */
        _toolIndicatorList.append(QVariant::fromValue(QUrl::fromUserInput("qrc:/toolbar/APMSupportForwardingIndicator.qml")));
    }
    return _toolIndicatorList;
}



// Tells QGC that your vehicle has a gimbal on it. This will in turn cause thing like gimbal commands to point
// the camera straight down for surveys to be automatically added to Plans.
// bool CustomFirmwarePlugin::hasGimbal(Vehicle* /*vehicle*/, bool& rollSupported, bool& pitchSupported, bool& yawSupported)
// {
//     rollSupported = false;
//     pitchSupported = true;
//     yawSupported = true;

//     return true;
// }
