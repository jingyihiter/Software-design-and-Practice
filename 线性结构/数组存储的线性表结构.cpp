#include <iostream>

#define MAX  100
using namespace std;
template<class T>
struct node{
	T *ele;
	int lengthl, sizel;
};

template<class T>
class arrayl
{
public:
	arrayl();               //构造函数
	~arrayl();              //析构函数
	bool isNull();          //判断是否为空
	bool isFull();          //判断是否满
	int getLength();        //返回当前线性表的实际长度
	void getEle(int);       //某个位置的节点值
	void getL(T);            //此值在线性表中第一个位置
	void insertl(T, int);   //插入到某个位置
	void deletel(int);      //删除某个位置
	void displayl();        //打印
private:
	node<T> *p;
};

template<class T>
arrayl<T>::arrayl()
{
	p = new node<T>;
	p->sizel = MAX;
	p->ele = new T[p->sizel];
	p->lengthl = 0;
}

template<class T>
arrayl<T>::~arrayl(){
	delete[]p->ele;
}

template<class T>
bool arrayl<T>::isNull()
{
	if (p->lengthl>0)
		return false;
	else return true;
}

template<class T>
bool arrayl<T>::isFull()
{
	if (p->lengthl == p->sizel)
		return true;
	else return false;
}

template<class T>
int arrayl<T>::getLength()
{
	return p->lengthl;
}

template<class T>
void arrayl<T>::getEle(int x)
{
    if(x>p->lengthl||x<0)
        cout<<"Error !"<<endl;
    else {
        cout<<"值为："<<p->ele[x]<<endl;
    }
}

template<class T>
void arrayl<T>::getL(T t)
{
    int temp=0;
    for(int i=0;i<p->lengthl;i++)
    {
        if(t==p->ele[i])
        {
            temp=1;
            cout<<"位置为："<<i<<endl;
            break;
        }
    }
    if(temp==0) cout<<"没有"<<endl;
}
template<class T>
void arrayl<T>::insertl(T t, int x)     //插入到排在x处
{
	if (isFull()) cout << "Full !" << endl;
	else {
		if (x>p->lengthl) cout << "Error !" << endl;
		else{
			p->ele[x] = t;
			for (int i = p->lengthl - 1; i > x; i--)
				p->ele[i + 1] = p->ele[i];
			p->lengthl++;
		}
	}
}
template<class T>
void arrayl<T>::deletel(int x)       //删除第x个节点
{
	if (x>p->lengthl || x<0) cout << "Error !" << endl;
	else {
		for (int j = x - 1; j<p->lengthl; j++)
			p->ele[j] = p->ele[j + 1];
		p->lengthl--;
	}
}

template<class T>
void arrayl<T>::displayl()
{
	if (isNull()) cout << "Null !" << endl;
	else {
		for (int j = 0; j<p->lengthl; j++)
			cout << p->ele[j] << " ";
		cout << endl;
	}
}
int main()
{
	arrayl<int> newl;
	int t, x;
	for (int i = 0; i<30; i++)     //初始线性表
		newl.insertl(i, i);
	cout << "当前线性表的长度：" << newl.getLength() << endl;
	newl.displayl();
	cout<<"输入要查询的位置：";
	cin>>x;
	newl.getEle(x);
    cout<<"输入要查询的节点：";
	cin>>t;
	newl.getL(t);
	cout << "输入要插入的t,插入的位置x:";
	cin >> t >> x;
	newl.insertl(t, x);
    cout << "当前线性表的长度：" << newl.getLength() << endl;
	newl.displayl();
	cout << "输入要删除的位置x:";
	cin >> x;
	newl.deletel(x);
	cout << "当前线性表的长度：" << newl.getLength() << endl;
	newl.displayl();
	system("pause");
	return 0;
}
/*
当前线性表的长度：30
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

输入要查询的位置：4
值为：4
输入要查询的节点：23
位置为：23
输入要插入的t,插入的位置x:90 3
当前线性表的长度：31
0 1 2 90 4 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
29
输入要删除的位置x:7
当前线性表的长度：30
0 1 2 90 4 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

请按任意键继续. . .

*/