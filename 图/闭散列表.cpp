/*闭散列表*/
#include<iostream>

#define B 10       //除数

using namespace std;

template<class T>
struct node  //散列元素
{
	T ht;         //元素值域
	int keys;       //元素keys域，可以取%
};

template<class T>   //T是元素的数据域，K是数据的key域
class MyHash
{
public:
	MyHash();
	~MyHash();
	void insert(T,int);      //插入
	void search(int);      //查找关键值为k的元素
	void Delete(T);      //删除
	void Output();       //输出散列表
private:
	node<T> hash[B];               //散列表
	bool empty[B];
};

template<class T>
MyHash<T>::MyHash()
{
	for (int i = 0; i < B; i++)  //初始都为空
		empty[i] = true;
}

template<class T>
MyHash<T>::~MyHash()
{
	delete[]hash;
	delete[]empty;
}

template<class T>
void MyHash<T>::insert(T t,int k)
{
	int locat = k%B;     //对B取模
	while (locat < B)
	{
		if (empty[locat])
		{
			hash[locat].ht = t;
			hash[locat].keys = k%B;
			empty[locat] = false;
			return;
		}
	 locat++;
	}
	if (locat >= B) cout << "散列表已满(或溢出)！" << endl;
}

template<class T>
void MyHash<T>::search(int k)
{
	int flag = 0;
	for (int i = 0; i < B; i++)
	{
		if (!empty[i])
		{
			if (hash[i].keys == k)
			{
				flag = 1;
				cout << hash[i].ht << " ";
			}
		}
	}
	if (flag == 0) cout << "没有！";
	cout << endl;
}

template<class T>
void MyHash<T>::Delete(T t)
{
	int flag = 0;
	for (int i = 0; i < B; i++)
	{
		if (!empty[i])
		{
			if (hash[i].ht == t)
			{
				flag = 1;
				hash[i].ht = NULL;
				hash[i].keys = NULL;
				empty[i] = true;   //删除就可以直接将此处置空
			}
		}
	}
}

template<class T>
void MyHash<T>::Output()
{
	cout << "散列表为：" << endl;
	for (int i = 0; i < B; i++)
		cout << i<<"\t";
	cout << endl;
	for (int i = 0; i < B; i++)
	{
		if (!empty[i])
			cout << hash[i].ht << '\t';  //输出元素值
		else cout << " " << '\t';
	}
	cout << endl;
}

int main()                                      //内散列表，在vs中也出现于库中断言冲突而泄露内存，还没解决，但是可以得到正确的结果
{                                               //散列函数用最简单的除法
	MyHash<int> myhash;
	int n;
	int e, k;
	cout << "输入要插入的散列表元素个数（小于B=10)：" << endl;
	cin >> n;
	cout << "输入插入的元素及关键值："<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> e >> k;
		myhash.insert(e, k);
	}
	myhash.Output();
	cout << "输入要查找的元素的关键值" << endl;
	int num;
	cin >> num;
	myhash.search(num);
	cout << "输入要删除的元素：" << endl;
	int t;
	cin >> t;
	myhash.Delete(t);
	myhash.Output();
	getchar();
	return 0;
}

/*
输入要插入的散列表元素个数（小于B=10)：
6
输入插入的元素及关键值：
1 23
2 45
3 65
4 3
5 7
6
9
散列表为：
0       1       2       3       4       5       6       7       8       9

1       4       2       3       5               6

输入要查找的元素的关键值
3
1 4
输入要删除的元素：
4
散列表为：
0       1       2       3       4       5       6       7       8       9

1               2       3       5               6
*/