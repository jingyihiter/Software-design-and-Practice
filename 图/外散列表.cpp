#include<iostream>

#define B 10
using namespace std;



template<class T>
struct node
{
	T data;
	node *next;
};

template<class T>
class OutHashTable
{
public:
	OutHashTable();
	~OutHashTable();
	int h(T k);
	void Insert(T t);
	node<T>* Search(T t);
	void Delete(T t);
	void Output();
private:
	node<T> *hash[B];
};

template<class T>
OutHashTable<T>::OutHashTable()
{
	for (int i = 0; i < B; i++)
		hash[i] = NULL;   //初始化
}


template<class T>
OutHashTable<T>::~OutHashTable()
{
	delete []hash;
}

template<class T>
int OutHashTable<T>::h(T k)
{
	return k%B;           //先取最简单的除法
}


template<class T>
void OutHashTable<T>::Insert(T t)
{
	int bucket;
	node<T>* oldheader;
	if (Search(t) == NULL)
	{
		bucket = h(t);
		oldheader = hash[bucket];
		hash[bucket] = new node<T>;
		hash[bucket]->data = t;
		hash[bucket]->next = oldheader;
	}
}

template<class T>
node<T>* OutHashTable<T>::Search(T k)
{
	node<T>* bptr;
	bptr = hash[h(k)]; //桶的首节点指针
	while (bptr != NULL)
	{
		if (bptr->data == k)
			return bptr;
		else bptr = bptr->next;
	}
	return bptr;
}

template<class T>
void OutHashTable<T>::Delete(T k)
{
	int bucket;
	node<T>*bptr=NULL;
	bool b;
	bucket = h(k);
	b = false;
	if (hash[bucket] != NULL)
	{
		if (hash[bucket]->data == k)
			hash[bucket] = hash[bucket]->next;
		else
		{
			bptr = hash[bucket];
			while ((bptr->next != NULL) && (b == false)) 
			if (bptr->next->data == k)
			{
				bptr->next = bptr->next->next;
				b = true;
			}
		}
	}
	else   bptr = bptr->next;
}

template<class T>
void OutHashTable<T>::Output()
{
	int i = 0;
	while (hash[i]->data)
	{
		cout << hash[i]->data << " ";
		i++;
	}
	cout << endl;
}

int main()
{
	OutHashTable<int> hashtable;
	int a=1;
	cout << "输入散列表：";
	while (a != 0)
	{
		cin >> a;
		hashtable.Insert(a);
	}
	int  b;
	cout << "查找a：" << endl;
	cin >> a;
	node<int> *p = hashtable.Search(a);
	if (p == NULL) cout << "没有！" << endl;
	else cout << p << endl;
	cout << "删除b：" << endl;
	cin >> b;
	hashtable.Delete(b);
	cout << "查找b:";
	cout << hashtable.Search(b);

	return 0;
}
/*
输入散列表：21 11 13 3 0
查找a：
21
00F191F0
删除b：
3
查找b:00000000
*/