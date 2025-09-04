import QtQuick
import QtQuick.Window
import DataUpdater 1.0  // 导入刚才注册的类型

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Data Updater Test")

    // 创建DataUpdater实例，就像创建其他QML对象一样
    DataUpdater {
        id: dataUpdater
        Component.onCompleted: {
            start() // 组件创建完成后启动定时器
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            // 直接绑定到DataUpdater的属性，属性变化时自动更新
            text: "Value 1: " + dataUpdater.value1.toFixed(2)
            font.pixelSize: 24
        }

        Text {
            text: "Value 2: " + dataUpdater.value2.toFixed(2)
            font.pixelSize: 24
        }

        Text {
            text: "Value 3: " + dataUpdater.value3.toFixed(2)
            font.pixelSize: 24
        }
    }

    // 连接信号处理（可选）
    Connections {
        target: dataUpdater
        function onValuesChanged() {
            console.log("QML: Values updated")
        }
    }
}
