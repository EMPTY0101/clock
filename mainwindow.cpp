#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clock.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
    QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber->display(time);

    Clock *clock = new Clock(this);
    clock->setGeometry(20,20,300,30);
    clock->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_timer()
{

    QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber->display(time);
}
