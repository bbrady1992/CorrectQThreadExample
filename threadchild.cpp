#include "threadchild.h"

#include <iostream>
#include <QThread>

ThreadChild::ThreadChild(QObject *parent)
  : ThreadWorker(parent)
{
  std::cout << "In ThreadChild::ThreadChild(). Thread ID " << QThread::currentThreadId() << "\n";
}

void ThreadChild::run()
{
  std::cout << "In ThreadChild::runSingleEvent(). Thread ID is " << QThread::currentThreadId() << "\n";
}

void ThreadChild::printMessage()
{
  std::cout << "In ThreadChild::printMessage(). Thread ID is " << QThread::currentThreadId() << "\n";
}
