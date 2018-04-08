#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QObject>
#include <QTimer>

class ThreadWorker : public QObject
{
  Q_OBJECT

public:
  explicit ThreadWorker(QObject *parent = nullptr);
  virtual ~ThreadWorker();

public slots:
  void Start(int msec);
  virtual void run();
  void stop();

protected:
  QTimer *timer;
};

#endif // THREADWORKER_H
