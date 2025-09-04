// DataUpdater.cpp
#include "DataUpdater.h"
#include <QDebug>

DataUpdater::DataUpdater(QObject *parent)
    : QObject(parent)
{
    // 初始化随机数生成器
    std::random_device rd;
    gen = std::mt19937(rd());
    dis = std::uniform_real_distribution<double>(0.0, 100.0);

    // 创建并配置定时器
    timer = new QTimer(this);
    timer->setInterval(500); // 500毫秒
    timer->setSingleShot(false); // 重复运行

    // 连接信号槽
    connect(timer, &QTimer::timeout, this, &DataUpdater::updateValues);
}

void DataUpdater::start()
{
    timer->start();
}

void DataUpdater::stop()
{
    timer->stop();
}

void DataUpdater::updateValues()
{
    // 模拟随机数值更新
    value1 = dis(gen);
    value2 = dis(gen);
    value3 = dis(gen);

    // 发出信号通知QML数据已更新
    emit valuesChanged();

    qDebug() << "Values updated:" << value1 << value2 << value3;
}
