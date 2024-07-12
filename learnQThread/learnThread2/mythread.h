#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>

class Generate : public QObject
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    void working(int m_num);
signals:
    void sendArray(QVector<int> list);


};

class BubbleSort: public QObject
{
    Q_OBJECT

public:
    explicit BubbleSort(QObject *parent = nullptr);

    void working(QVector<int> m_list);
signals:
    void finish(QVector<int> list);

};

class QuickSort : public QObject
{
    Q_OBJECT

public:
    explicit QuickSort(QObject *parent = nullptr);

    void quickSort(QVector<int> &s,int l,int r);

    void working(QVector<int> m_list);
signals:
    void finish(QVector<int> list);

};


#endif // MYTHREAD_H
