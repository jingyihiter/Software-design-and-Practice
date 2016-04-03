#include <iostream>

#define Max 30

using namespace std;

template<class T>
struct myq{
	int head, rear;
	T *ele;
};

template<class T>
class MyQueue{
public:
	MyQueue();
	~MyQueue();
	void MakeNull();            //将队列置空
	bool IsEmpty();             //判断是否为空
	bool IsFull();              //判断是否满
	void EnQueue(T);            //入队
	T DeQueue();                //出队
	int lengthq();               //队列的长度
private:
	myq<T> *q;
};

template<class T>
MyQueue<T>::MyQueue()
{
	q = new myq<T>;
	q->ele = new T[Max];
}

template<class T>
MyQueue<T>::~MyQueue()
{
	delete q;
	delete[]q->ele;
}

template<class T>
void MyQueue<T>::MakeNull()
{
	q->head = q->rear = 0;
}

template<class T>
bool MyQueue<T>::IsEmpty()
{
	if (q->rear == q->head)
		return true;
	else
		return false;
}

template<class T>
bool MyQueue<T>::IsFull()
{
	if ((q->rear + 1) % Max == q->head)
		return true;
	else
		return false;
}

template<class T>
void MyQueue<T>::EnQueue(T t)
{
	if (IsFull())
		cout << "队满";
	else{
		q->rear = (q->rear + 1) % Max;
		q->ele[q->rear] = t;
		//cout<<t<<"入队"<<endl;
	}
}

template<class T>
T MyQueue<T>::DeQueue()
{
	if (IsEmpty())
	{
		cout << "队空！" << endl;
		return NULL;
	}
	else {
		q->head = (q->head + 1) % Max;
		// cout<<q->head<<"head"<<endl;
		//cout<<q->ele[q->head]<<"出队"<<endl;
		return q->ele[q->head];
	}
}

template<class T>
int MyQueue<T>::lengthq()
{
	return  (q->rear - q->head + Max) % Max;
}
int main()
{
	MyQueue<int> myqueue;
	myqueue.MakeNull();
	cout << "20个数入队：" << endl;
	for (int i = 0; i<20; i++)
		myqueue.EnQueue(i);
	cout << "当前队列长度：" << myqueue.lengthq() << endl;
	cout << "队列出队，输出" << endl;
	for (int i = 0; i<20; i++)
		cout << myqueue.DeQueue() << " ";
	cout << endl;
	system("pause");
	return 0;
}
/*
20个数入队：
当前队列长度：20
队列出队，输出
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
请按任意键继续. . .

*/