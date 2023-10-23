#include "clock.h"

Clock::Clock(QWidget *parent) : QLCDNumber(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    start();
    currentTime = QTime::currentTime();
    this->setDigitCount(8);
    this->display(currentTime.toString("hh:mm:ss"));
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));



}

void Clock::start()
{
    timer->start();
}

void Clock::stop()
{
    timer->stop();
}

void Clock::on_timer()
{
    currentTime = QTime::currentTime();
    this->display(currentTime.toString("hh:mm:ss"));
}
