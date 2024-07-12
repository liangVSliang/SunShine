#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QRunnable>
#include <QObject>
#include <QThread>

class Generate : public QObject,public QRunnable
{
    Q_OBJECT

private:
    int m_num;
public:
    explicit Generate(QObject *parent = nullptr);
    void run();
    void recvNum(int num);
signals:
    void sendArray(QVector<int> list);
};


class BubbleSort: public QObject,public QRunnable
{
    Q_OBJECT
private:
    QVector<int> m_list;
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void run();
    void recvArray(QVector<int> m_list);
signals:
    void finish(QVector<int> list);

};

class QuickSort : public QObject,public QRunnable
{
    Q_OBJECT
private:
    QVector<int> m_list;
     void quickSort(QVector<int> &s,int l,int r);
public:
    explicit QuickSort(QObject *parent = nullptr);

    void recvArray(QVector<int> list);

    void run();
signals:
    void finish(QVector<int> list);

};

#endif // MYTHREAD_H
