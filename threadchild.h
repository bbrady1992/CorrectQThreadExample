#ifndef THREADCHILD_H
#define THREADCHILD_H

#include <QObject>

#include <string>

#include "threadworker.h"

class ThreadChild : public ThreadWorker
{
  Q_OBJECT

public:
  ThreadChild(QObject *parent = nullptr);

public slots:
  virtual void run(); // override;
  void printMessage();
};

#endif // THREADCHILD_H
