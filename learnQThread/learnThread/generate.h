#ifndef GENERATE_H
#define GENERATE_H

#include <QThread>
#include <QVector>

//生成随机数
class Generate : public QThread
{
    Q_OBJECT
private:
    int m_num;
public:
    explicit Generate(QObject *parent = nullptr);

    void recvNum(int num);

signals:
    void sendArray(QVector<int> num);
    // QThread interface
protected:
    void run() override;
};

class BubbleSort : public QThread
{
    Q_OBJECT
private:
    QVector<int> m_list;
public:
    explicit BubbleSort(QObject *parent = nullptr);

    void recvArray(QVector<int> list);

signals:
    void finish(QVector<int> num);
    // QThread interface
protected:
    void run() override;
};

class QuickSort : public QThread
{
    Q_OBJECT
private:
    QVector<int> m_list;

    void quickSort(QVector<int> &s,int l,int r);
public:
    explicit QuickSort(QObject *parent = nullptr);

    void recvArray(QVector<int> list);

signals:
    void finish(QVector<int> num);
    // QThread interface
protected:
    void run() override;
};

#endif // GENERATE_H
