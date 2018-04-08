#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <queue>
#include <string>

#include "threadchild.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

  void CreateTimerBasedThread();
  void StopThread();

signals:
  void StartTimer(int timerInterval);
  void StopTimer();
  void SendMessage();

private:
  Ui::Widget *ui;
  ThreadChild *worker;
  QThread *thread;
  bool deletedWorker;
};

#endif // WIDGET_H
