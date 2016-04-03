#include<iostream>
#include "tree.h"

using namespace std;

template<class T>
void Tree<T>::Creat(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "输入第" << i << "个节点：";
		cin >> head[i].data;
		cout << "输入其子树的个数：";
		int m;
		cin >> m;
		if (m == 0) continue;
		cout << "输入其子树：";
		head[i].Treelist[0] = head[i].data;
		for (int j = 1; j <= m; j++)
			cin >> head[i].Treelist[j];
	}
	cout << endl;
}

template<class T>
T Tree<T>::GetLeftMostChild(int i)
{
	if (head[i].Treelist[i] > 0)
		return head[i].Treelist[1];
	else return NULL;
}

template<class T>
T Tree<T>::GetRightMostChild(int i)
{
	int flag = 0;
	for (int j = 1;; j++)
	{
		if (head[i].Treelist[1] < 0) return NULL;
		if (head[i].Treelist[j]<0)
		{
			flag = 1;
			return head[i].Treelist[j - 1];
		}
	}
	if (flag == 0) return NULL;
}

template<class T>
T Tree<T>::GetData(int i)
{
	return head[i].data;
}

template<class T>
T Tree<T>::GetRoot()
{
	return head[1].data;
}

template<class T>
T Tree<T>::GetParent(int i)
{
	for (int j = 1; j < i; j++)
	{
		for (int k = 1; head[j].Treelist[k] != NULL; k++)
		{
			if (head[i].data == head[j].Treelist[k])
			{
				return head[j].data;
			}
		}
	}
	return NULL;
}

template<class T>
void Tree<T>::Display(int n)         //输出算法有问题
{
	cout << "树的简单输出：" << endl;
	int count = 0, i, j;
	cout << head[1].Treelist[0] << " ";
	for (i = 1; i < n; i++)
	{
		for (j = 1;; j++)
		{
			if (head[i].Treelist[j] < 0) break;
			else
			{
				cout << head[i].Treelist[j] << " ";
				count++;
			}
		}
		if (count>=n) return;
	}
	cout << endl;
}

template<class T>
int Tree<T>::GetPosition(T t,int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (head[i].data == t)
			return i;
	}
	return NULL;
}
