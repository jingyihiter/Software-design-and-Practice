#include <iostream>

using namespace std;
template<class T>
struct node{
	T ele;
	node *next;
};

template<class T>
class reacl{
public:
	reacl();                  //析构函数
	~reacl();                 //构造函数
	int getLength();           //得到线性表的表长
	T getEle(int);             //得到某个位置的节点值
	void getList(T);            //得到所在的位置
	void insertl(T, int);      //插入
	void deletel(int);        //删除
	void displayl();          //打印输出
private:
	node<T> *L;
	int length;
};

template<class T>
reacl<T>::reacl()
{
	L = new node<T>;
	length = 0;
	L->next = NULL;
}

template<class T>
reacl<T>::~reacl()
{
	delete L;
}

template<class T>
int reacl<T>::getLength()
{
	return length;
}

template<class T>
T reacl<T>::getEle(int x)
{
	node<T> *p = L;
	for (int i = 0; i < x && (p->next != NULL); i++)
		p = p->next;
	return p->ele;
}

template<class T>
void reacl<T>::getList(T t)
{
	node<T> *p = L;
	int i = 0, temp = 0;
	while (p->next != NULL)
	{
		if (p->ele == t)
		{
			temp = 1;
			cout << "位置：" << i << endl;
			break;
		}
		i++;
		p = p->next;
	}
	if (temp == 0) cout << "没有" << endl;
}
template<class T>
void reacl<T>::insertl(T t, int x)
{
	node<T> *datal = new node<T>;
	node<T> *p = L;
	datal->next = NULL;
	datal->ele = t;
	for (int i = 0; i<x && (p->next != NULL); i++)
		p = p->next;
	datal->next = p->next;
	p->next = datal;
	length++;
}

template<class T>
void reacl<T>::deletel(int x)
{
	node<T> *temp = new node<T>;
	node<T> *p = L;
	for (int i = 0; i<x - 1; i++)
		p = p->next;
	temp = p->next;
	p->next = temp->next;
	length--;
}

template<class T>
void reacl<T>::displayl()
{
	node<T> *p = L;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->ele << " ";
	}
}
int main()
{
	reacl<int> newl;
	for (int i = 0; i < 30; i++)      //初始线性表
	{
		newl.insertl(i, i);
	}
	cout << "线性表长：" << newl.getLength() << endl;
	newl.displayl();
	cout << "得到值是：" << newl.getEle(10) << endl;;
	newl.getList(25);
	newl.insertl(100, 20);         //插入
	newl.displayl();
	cout << "线性表长：" << newl.getLength() << endl;
	newl.deletel(21);               //删除
	newl.displayl();
	cout << "线性表长：" << newl.getLength() << endl;
	system("pause");
	return 0;
}
/*
线性表长：30
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
得到值是：9
位置：26
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 100 20 21 22 23 24 25 26 27 28
29 线性表长：31
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
线性表长：30
请按任意键继续. . .
*/