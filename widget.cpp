#include "widget.h"
#include "ui_widget.h"

#include <iostream>

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  connect(ui->startTimer, &QPushButton::clicked, this, &Widget::CreateTimerBasedThread);
  connect(ui->stopButton, &QPushButton::clicked, this, &Widget::StopThread);
  connect(ui->sendMessage, &QPushButton::clicked, this, &Widget::SendMessage);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::CreateTimerBasedThread()
{
    std::cout << "Starting timer-based thread. Thread ID: " << QThread::currentThreadId() << "\n";

    // Create thread
    thread = new QThread(this);

    // Create worker and move to thread
    worker = new ThreadChild();
    deletedWorker = false;
    connect(this, &Widget::StartTimer, worker, &ThreadChild::Start);
    connect(this, &Widget::StopTimer, worker, &ThreadChild::stop);
    connect(this, &Widget::SendMessage, worker, &ThreadChild::printMessage);
    worker->moveToThread(thread);

    thread->start();
    emit StartTimer(500);
}

void Widget::StopThread()
{
  if (thread->isRunning())
  {
    emit StopTimer();
    thread->quit();
    thread->wait();
  }
  if (!deletedWorker)
  {
    delete worker;
    deletedWorker = true;
    std::cout << "Thread finished running!\n";
  }
  else
  {
    std::cout << "Thread not running.\n";
  }
}
