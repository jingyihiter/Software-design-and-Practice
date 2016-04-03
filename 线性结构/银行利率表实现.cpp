/*数组存储结构及其操作算法
实现 银行利率表的管理*/
#include <iostream>
#define Max 20
using namespace std;
template<class T>
struct rate
{
	T date[Max];
	char name[Max];
};

template<class T>
class bank{
public:
	bank();
	~bank();
	void input(int n);               //输入
	void insert(int banklist, int n);//插入
	void deletel(int banklist, int n);//删除
	void output(int n);               //输出
private:
	rate<T> *b;
	int count;
};

template<class T>
bank<T>::bank()
{
	b = new rate<T>[Max];
	count = 0;
}

template<class T>
bank<T>::~bank()
{
	delete[]b;
}

template<class T>
void bank<T>::input(int n)
{
	count = n;
	for (int i = 0; i<n; i++)
	{
		cout << "输入名字：";
		cin >> b[i].name;
		cout << "输入利率：";
		for (int j = 0; j<5; j++)
			cin >> b[i].date[j];
	}
}

template<class T>
void bank<T>::insert(int banklist, int n)
{
	rate<T> *p = new rate<T>;
	for (int i = count - 1; i >= banklist; i--)
		b[i + 1] = b[i];
	cout << "输入银行名字：";
	cin >> p->name;
	cout << "输入利率：";
	for (int i = 0; i < 5; i++)
		cin >> p->date[i];
	b[banklist] = *p;
	count++;                    //n值增加1
}

template<class T>
void bank<T>::deletel(int banklist, int n)
{
	for (int i = banklist; i < count; i++)
		b[i] = b[i + 1];        //覆盖即删除
	count--;
}

template<class T>
void bank<T>::output(int n)
{
	cout << "name \t" << "3 months \t" << "6 months \t" << "1 year\t\t" << "3 years \t" << "5 years \t" << endl;
	for (int i = 0; i<count; i++)
	{
		cout << b[i].name << '\t';
		for (int j = 0; j < 5; j++)
			cout << b[i].date[j] << '\t' << '\t';
		cout << endl;
	}
}

int main()
{
	bank<float> B;
	int n, i, j;
	cout << "输入银行个数：";
	cin >> n;
	B.input(n);
	B.output(n);
	cout << "输入插入的序号： ";
	cin >> i;
	B.insert(i, n);
	B.output(n);
	cout << "输入删除的序号：";
	cin >> j;
	B.deletel(j, n);
	B.output(n);
	system("pause");
	return 0;
}
/*
输入银行个数：3
输入名字：商业
输入利率：0.1 0.2 0.3 0.4 0.5
输入名字：农业
输入利率：0.2 0.4 0.5 0.6 0.7
输入名字：工商
输入利率：0.23 0.4 0.5 0.7 0.8
name    3 months        6 months        1 year          3 years         5 years

商业    0.1             0.2             0.3             0.4             0.5

农业    0.2             0.4             0.5             0.6             0.7

工商    0.23            0.4             0.5             0.7             0.8

输入插入的序号： 1
输入银行名字：中国
输入利率：0.23 0.3 0.4 0.5 0.7
name    3 months        6 months        1 year          3 years         5 years

商业    0.1             0.2             0.3             0.4             0.5

中国    0.23            0.3             0.4             0.5             0.7

农业    0.2             0.4             0.5             0.6             0.7

工商    0.23            0.4             0.5             0.7             0.8

输入删除的序号：3
name    3 months        6 months        1 year          3 years         5 years

商业    0.1             0.2             0.3             0.4             0.5

中国    0.23            0.3             0.4             0.5             0.7

农业    0.2             0.4             0.5             0.6             0.7

*/