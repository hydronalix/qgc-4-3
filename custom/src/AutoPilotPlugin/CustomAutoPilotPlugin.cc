/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 * @file
 *   @brief Custom Autopilot Plugin
 *   @author Gus Grubba <gus@auterion.com>
 */

#include "CustomAutoPilotPlugin.h"

#include "QGCApplication.h"
#include "QGCCorePlugin.h"

CustomAutoPilotPlugin::CustomAutoPilotPlugin(Vehicle* vehicle, QObject* parent)
    : APMAutoPilotPlugin(vehicle, parent)
{
    // Whenever we go on/out of advanced mode the available list of settings pages will change
    // connect(qgcApp()->toolbox()->corePlugin(), &QGCCorePlugin::showAdvancedUIChanged, this, &CustomAutoPilotPlugin::_advancedChanged);
    /* who cares about that actual cringe lmao */
}

// called when you hit the "vehicle setup" button
const QVariantList& CustomAutoPilotPlugin::vehicleComponents()
{
    if (_components.count() == 0 && !_incorrectParameterVersion) {
        if (_vehicle->parameterManager()->parametersReady()) {
            /* basically the stuff from the apm autopilot plugin sans the version/esp8266 crap */
            _airframeComponent = new APMAirframeComponent(_vehicle, this);
            _airframeComponent->setupTriggerSignals();
            _components.append(QVariant::fromValue((VehicleComponent*)_airframeComponent));

            _sensorsComponent = new APMSensorsComponent(_vehicle, this);
            _sensorsComponent->setupTriggerSignals();
            _components.append(QVariant::fromValue((VehicleComponent*)_sensorsComponent));

            _powerComponent = new APMPowerComponent(_vehicle, this);
            _powerComponent->setupTriggerSignals();
            _components.append(QVariant::fromValue((VehicleComponent*)_powerComponent));

            _safetyComponent = new APMSafetyComponent(_vehicle, this);
            _safetyComponent->setupTriggerSignals();
            _components.append(QVariant::fromValue((VehicleComponent*)_safetyComponent));

            _tuningComponent = new APMTuningComponent(_vehicle, this);
            _tuningComponent->setupTriggerSignals();
            _components.append(QVariant::fromValue((VehicleComponent*)_tuningComponent));

            if(_vehicle->parameterManager()->parameterExists(-1, "MNT1_TYPE")) {
                _cameraComponent = new APMCameraComponent(_vehicle, this);
                _cameraComponent->setupTriggerSignals();
                _components.append(QVariant::fromValue((VehicleComponent*)_cameraComponent));
            }

            _apmRemoteSupportComponent = new APMRemoteSupportComponent(_vehicle, this);
            _apmRemoteSupportComponent->setupTriggerSignals();
            _components.append(QVariant::fromValue((VehicleComponent*)_apmRemoteSupportComponent));
        } else {
            qWarning() << "Call to vehicleCompenents prior to parametersReady";
        }
    }
    return _components;
}
