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

    function doSomething(checked, servonum) {
        /* to be uncommented when actual builds happen */
        // var pwm = 0
        // if (checked) {
        //     pwm = 2000
        // } else {
        //     pwm = 1500
        // }

        // _activeVehicle.sendCommand(1,      // comp id
        //                            183,                 // MAV_CMD_DO_SET_SERVO
        //                            true,                // show error
        //                            4 + servonum,        // servo instance (start at 4 and go up)
        //                            pwm)                 // servo value in us

        /* obvious command for stinky simulator test (it works lol) */
        if (checked) {
            _activeVehicle.sendCommand(1,                   // comp id (MAV_COMP_ID_AUTOPILOT1)
                                       20,                  // MAV_CMD_NAV_RETURN_TO_LAUNCH
                                       true)                // show error
        }

        return 1
    }

    ColumnLayout {
        id: actuatorscolumn
        Text {
            text: "guh"
            horizontalAlignment: parent.AlignHCenter
        }

        QGCCheckBox {
            property var _num: 0
            checked: false
            text: "actuator " + _num
            onClicked: doSomething(checked, _num)
            textBold: true
            textColor: "black"
        }

        QGCCheckBox {
            property var _num: 1
            checked: false
            text: "actuator " + _num
            onClicked: doSomething(checked, _num)
            textBold: true
            textColor: "black"
        }
    }

}
