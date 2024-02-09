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

#pragma once

#include "APMFirmwarePlugin.h"

class APMHydronalixMode : public APMCustomMode
{
public:
    enum Mode {
        MANUAL          = 0,
        ACRO            = 1,
        STEERING        = 3,
        HOLD            = 4,
        LOITER          = 5,
        FOLLOW          = 6,
        SIMPLE          = 7,
        AUTO            = 10,
        RTL             = 11,
        SMART_RTL       = 12,
        GUIDED          = 15,
        INITIALIZING    = 16,
    };

    APMHydronalixMode(uint32_t mode, bool settable);
};

class CustomFirmwarePlugin : public APMFirmwarePlugin
{
    Q_OBJECT
public:
    CustomFirmwarePlugin();

    // FirmwarePlugin overrides
    AutoPilotPlugin*    autopilotPlugin (Vehicle* vehicle) final;
    const QVariantList& toolIndicators  (const Vehicle* vehicle) final;
    // bool                hasGimbal       (Vehicle* vehicle, bool& rollSupported, bool& pitchSupported, bool& yawSupported) final;

private:
    QVariantList _toolIndicatorList;
};
