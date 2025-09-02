import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 600
    height: 500
    title: "数值仪表盘"

    // 用于存储三个数值
    property real value1: 0.0
    property real value2: 0.0
    property real value3: 0.0

    // 控制显示的数值个数 (1, 2, 或 3)
    property int displayCount: 3

    // 每秒更新一次数值
    Timer {
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            // 模拟随机数值更新
            value1 = Math.random() * 100
            value2 = Math.random() * 100
            value3 = Math.random() * 100
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        // 显示控制按钮
        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "显示1个值"
                onClicked: displayCount = 1
            }

            Button {
                text: "显示2个值"
                onClicked: displayCount = 2
            }

            Button {
                text: "显示3个值"
                onClicked: displayCount = 3
            }
        }

        // 数值显示区域
        Column {
            spacing: 15

            Text {
                text: "数值 1: " + value1.toFixed(2)
                font.pixelSize: 24
                visible: displayCount >= 1
            }

            Text {
                text: "数值 2: " + value2.toFixed(2)
                font.pixelSize: 24
                visible: displayCount >= 2
            }

            Text {
                text: "数值 3: " + value3.toFixed(2)
                font.pixelSize: 24
                visible: displayCount >= 3
            }
        }

        // 显示当前状态
        Text {
            text: "当前显示: " + displayCount + " 个数值"
            font.pixelSize: 16
            color: "gray"
        }
    }
}
