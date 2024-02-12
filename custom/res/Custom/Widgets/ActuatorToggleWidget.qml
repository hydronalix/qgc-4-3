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

    function doSomething(arg1, arg2) {
        if (arg1) {
            showCriticalVehicleMessage("cringe! x" + arg2);
        } else {
            /* ... */
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
            property var _num: 1
            checked: false
            text: "actuator " + _num
            onClicked: doSomething(checked, _num)
            textBold: true
            textColor: "black"
        }

        QGCCheckBox {
            property var _num: 2
            checked: false
            text: "actuator " + _num
            onClicked: doSomething(checked, _num)
            textBold: true
            textColor: "black"
        }
    }

}
