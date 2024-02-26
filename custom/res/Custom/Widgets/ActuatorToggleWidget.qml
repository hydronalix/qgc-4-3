import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QGroundControl
import QGroundControl.Controls
import QGroundControl.Palette
import QGroundControl.ScreenTools


// ui element for doing actuator toggle cringe ripped from FlyViewInsetViewer.qml
Rectangle  {
    height: actuatorscolumn.height
    width: actuatorscolumn.width
    color: "dimgray"

    function doSomething(checked, actuatorNum)
    {
        // /* obvious command for stinky simulator test (it works lol) */
        // if (checked) {
        //     _activeVehicle.sendCommand(1,                   // comp id (MAV_COMP_ID_AUTOPILOT1)
        //                                20,                  // MAV_CMD_NAV_RETURN_TO_LAUNCH
        //                                true)                // show error
        //     showCriticalVehicleMessage("cringe!");
        // }

        return 1
    }

    ColumnLayout {
        id: actuatorscolumn
        Text {
            text: "guh"
            horizontalAlignment: parent.AlignHCenter
        }

        DelayButton {
            id: launcherButton
            text: "launch sonobuoy"
            delay: 2000
            onActivated: {
                showCriticalVehicleMessage("sonobuoy launched")
                _activeVehicle.sendCommand(1,                   // comp id
                                           184,                 // MAV_CMD_DO_REPEAT_SERVO
                                           true,                // show error
                                           4,                   // servo instance
                                           2000,                // servo value in us
                                           1,                   // cycle count
                                           2)                   // cycle time in s
                launcherButton.progress = 0
            }
        }
    }

}
