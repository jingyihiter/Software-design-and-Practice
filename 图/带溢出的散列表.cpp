#include<iostream>

#define B 10

using namespace std;

template<class T>
struct celltype
{
	T data;
	celltype *next;
};

template<class T>
class HashTable
{
public:
	HashTable();
	int h(T);
	void Insert(T);
	celltype<T>* Search(T k);
	void Delete(T k);
private:
	celltype<T> *hash[B];
};

template<class T>
int HashTable<T>::h(T k)
{
	return k%B;        
}
template<class T>
HashTable<T>::HashTable()
{
	for (int i = 0; i < B; i++)
	{
		hash[i] = NULL;
	}
}
template <class T>
void HashTable<T>::Insert(T k)
{
	int first = h(k);  //散列地址
	if (Search(k) == NULL)   //之前不在散列表中
	{
		if (hash[first] != NULL)
		{
			celltype<T> *p = new celltype<T>;
			celltype<T> *temp = new celltype<T>;
			temp->data = k;
			temp->next = NULL;

			p = hash[first];
			while (p->next!=NULL)
			{
				p = p->next;
			}
			p->next = temp;
		}
		else
		{
			celltype<T> *p = new celltype<T>;
			p->data = k;
			p->next = NULL;
			hash[first] = p;
		}
	}
}

template<class T>
celltype<T>* HashTable<T>::Search(T k)
{
	int locat = h(k);    //找到k的散列地址
	celltype<T> *bptr;
	bptr = hash[locat];
	while( bptr != NULL)
	{
		if (bptr->data == k)
			return bptr;
		else 
			bptr = bptr->next;

	}
	return bptr;
}

template<class T>
void HashTable<T>::Delete(T k)
{
	int locat = h(k);
	if (Search(k)!=NULL)  //k存在
	{
		celltype<T> *p = hash[locat];
		while (p!= NULL)
		{
			if (p->data == k)
			{
				if (p->next != NULL)
					p->data = p->next->data;
				p = p->next;
			}
			else  p=p->next;
			
		}
		if (Search(k)!=NULL) cout << "删除失败！" << endl;
		else cout << "删除成功！" << endl;
		return;
	}
	cout << "没有k" << endl;
}

int main()
{
	HashTable<int> hashtable;
	int a = 1;
	cout << "带溢出表的散列表：" << endl;
	cout << "输入散列表:" << endl;
	while (a != -1)
	{
		cin >> a;
		if(a!=-1) hashtable.Insert(a);
	}
	cout << "输入查找的值：";
	cin >> a;
	if (hashtable.Search(a)) cout<<"所在指针：" << hashtable.Search(a) << endl;
	else cout << "没有找到！" << endl;
	cout << "输入删除的值：";
	cin >> a;
	hashtable.Delete(a);
	getchar();
	return 0;
}
/*
带溢出表的散列表：
输入散列表:
12 2 32 4 31 -1
输入查找的值：2
所在指针：011192B8
输入删除的值：2
删除成功！


*/

