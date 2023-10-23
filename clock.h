#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class Clock : public QLCDNumber
{
    Q_OBJECT

public:

    Clock(QWidget *parent = nullptr);
    void start();
    void stop();
    //get_time();
private slots:

    void on_timer();

private:

    QTime currentTime;
    QTimer *timer;
};

#endif // CLOCK_H
