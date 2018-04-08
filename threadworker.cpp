#include "threadworker.h"

#include<iostream>
#include <QThread>

ThreadWorker::ThreadWorker(QObject *parent) : QObject(parent)
{
  std::cout << "In ThreadWorker::ThreadWorker(). Thread ID: " << QThread::currentThreadId() << "\n";
}

ThreadWorker::~ThreadWorker()
{

}

void ThreadWorker::Start(int msec)
{
  std::cout << "In ThreadWorker::Initialize(). Thread ID: " << QThread::currentThreadId() << "\n";
  timer = new QTimer(this);
  timer->setInterval(msec);
  connect(timer, &QTimer::timeout, this, &ThreadWorker::run);
  timer->start();
}


void ThreadWorker::run()
{
}

void ThreadWorker::stop()
{
  std::cout << "In ThreadWorker::stop(). Thread ID: " << QThread::currentThreadId() << "\n";
  timer->stop();
}
