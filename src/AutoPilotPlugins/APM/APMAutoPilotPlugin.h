/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


#ifndef APMAutoPilotPlugin_H
#define APMAutoPilotPlugin_H

#include "AutoPilotPlugin.h"
#include "UAS.h"
#include "APMParameterMetaData.h"
#include "APMFirmwarePlugin.h"
#include "ArduCopterFirmwarePlugin.h"
#include "ArduRoverFirmwarePlugin.h"
#include "VehicleComponent.h"
#include "APMAirframeComponent.h"
#include "APMFlightModesComponent.h"
#include "APMRadioComponent.h"
#include "APMSafetyComponent.h"
#include "APMTuningComponent.h"
#include "APMSensorsComponent.h"
#include "APMPowerComponent.h"
#include "APMMotorComponent.h"
#include "APMCameraComponent.h"
#include "APMLightsComponent.h"
#include "APMSubFrameComponent.h"
#include "APMFollowComponent.h"
#include "ESP8266Component.h"
#include "APMHeliComponent.h"
#include "APMRemoteSupportComponent.h"
#include "QGCApplication.h"
#include "ParameterManager.h"
#include "Vehicle.h"

/// This is the APM specific implementation of the AutoPilot class.
class APMAutoPilotPlugin : public AutoPilotPlugin
{
    Q_OBJECT

public:
    APMAutoPilotPlugin(Vehicle* vehicle, QObject* parent);
    ~APMAutoPilotPlugin();

    // Overrides from AutoPilotPlugin
    const QVariantList& vehicleComponents(void) override;
    QString prerequisiteSetup(VehicleComponent* component) const override;

protected:
    bool                        _incorrectParameterVersion; ///< true: parameter version incorrect, setup not allowed
    APMAirframeComponent*       _airframeComponent;
    APMCameraComponent*         _cameraComponent;
    APMLightsComponent*         _lightsComponent;
    APMSubFrameComponent*       _subFrameComponent;
    APMFlightModesComponent*    _flightModesComponent;
    APMPowerComponent*          _powerComponent;
    APMMotorComponent*          _motorComponent;
    APMRadioComponent*          _radioComponent;
    APMSafetyComponent*         _safetyComponent;
    APMSensorsComponent*        _sensorsComponent;
    APMTuningComponent*         _tuningComponent;
    ESP8266Component*           _esp8266Component;
    APMHeliComponent*           _heliComponent;
    APMRemoteSupportComponent*  _apmRemoteSupportComponent;
#if 0
    // Follow me not ready for Stable
    APMFollowComponent*         _followComponent;
#endif

#if !defined(NO_SERIAL_LINK) && !defined(__android__)
private slots:
    void _checkForBadCubeBlack(void);
#endif

private:
    QVariantList                _components;
};

#endif
