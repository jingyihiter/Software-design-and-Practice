#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED
using namespace std;

template<class T>
struct qnode{
T data;
qnode *next;
};

template<class Tq>
class MyQueue{
public:
    MyQueue();
    ~MyQueue();
    void  MakeNull();          //置成空队
    bool IsEmpty();            //判断空队
    int QueueLength();          //返回队列的长度
    Tq Front();                 //返回队首元素
    void EnQueue(Tq);              //入队
    Tq DeQueue();               //出队
    void Displayq();               //输出队
private:
    qnode<Tq> *head,*rear;
    int length;
};



#endif // MYQUEUE_H_INCLUDED
