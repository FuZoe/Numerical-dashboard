// DataUpdater.h
#ifndef DATAUPDATER_H
#define DATAUPDATER_H

#include <QObject>
#include <QTimer>
#include <random>

class DataUpdater : public QObject
{
    Q_OBJECT
    // 添加QML属性声明，使QML可以访问这些属性
    Q_PROPERTY(double value1 READ getValue1 NOTIFY valuesChanged)
    Q_PROPERTY(double value2 READ getValue2 NOTIFY valuesChanged)
    Q_PROPERTY(double value3 READ getValue3 NOTIFY valuesChanged)

public:
    explicit DataUpdater(QObject *parent = nullptr);

    // 添加getter方法供QML属性系统使用
    double getValue1() const { return value1; }
    double getValue2() const { return value2; }
    double getValue3() const { return value3; }

signals:
    // 添加信号，当数值改变时通知QML更新界面
    void valuesChanged();

public slots:
    // 添加公共槽函数，供QML调用启动和停止定时器
    void start();
    void stop();

private slots:
    void updateValues(); // 定时器触发的槽函数

private:
    QTimer *timer;
    std::mt19937 gen;
    std::uniform_real_distribution<double> dis;

    double value1 = 0.0;
    double value2 = 0.0;
    double value3 = 0.0;
};

#endif // DATAUPDATER_H
