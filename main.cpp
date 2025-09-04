#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "DataUpdater.h" // 添加头文件包含

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // 注册DataUpdater类型到QML，这样QML中就可以使用DataUpdater类型
    // 参数：类型名空间、主版本号、次版本号、QML中使用的类名
    qmlRegisterType<DataUpdater>("DataUpdater", 1, 0, "DataUpdater");

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("qt_quick_test01", "Main");

    return app.exec();
}

#include "main.moc" // 添加moc文件包含
