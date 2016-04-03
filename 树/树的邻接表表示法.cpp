#include<iostream>
#define MAX 100
using namespace std;
template<class T>
class  node
{
public:
	node()
	{
		next = NULL;
		Treelist = new T[MAX];
	}
	~node()
	{
		delete[]Treelist;
	}
	T data;
	T *Treelist;
	node *next;
};

template<class T>
class Tree
{
public:
	Tree()
	{
		head = new node<T>[MAX];
	}

	~Tree()
	{
		delete []head;
	}
	void Creat(int);
	T GetLeftMostChild(int);
	T GetRightMostChild(int);
	T GetData(int);
	T GetParent(int);
	T GetRoot();
private:
	node<T> *head;
};

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
	for (int i = 1; i <= n; i++)
	{
		cout << head[i].data << "->";
		int j = 1;
		while (head[i].Treelist[j] > 0)
		{
			cout << head[i].Treelist[j] << " ";
			j++;
		}
		cout <<  endl;
	}
}

template<class T>
T Tree<T>::GetLeftMostChild(int i)
{
	if (head[i].Treelist[0] > 0 && head[i].Treelist[1] > 0)
		return head[i].Treelist[1];
	else return NULL;
}

template<class T>
T Tree<T>::GetRightMostChild(int i)    
{
	int flag = 0;
	for (int j = 2;; j++)
	{
	if (head[i].Treelist[0] < 0||head[i].Treelist[1]<0) return NULL;
		if (head[i].Treelist[j]<0)
		{
			flag = 1;
			if (j == 2) return NULL;
			return head[i].Treelist[j - 1];
		}
	}
	if(flag==0) return NULL;
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
int main()
{
	Tree<int> newtree;
	int n;
	cout << "树的邻接表表示ADT（默认输入的数字都为比0大的数）" << endl;
	cout << "输入树节点数目：";
	cin >> n;
	newtree.Creat(n);
	cout << "得到的为0表示没有符合要求的" << endl;
	cout << "树的根节点：" << newtree.GetRoot() << endl;
	cout << "第2个节点的数据：" << newtree.GetData(2) << endl; //2作为测试用例，可以更改
	cout << "第2个节点的父亲：" << newtree.GetParent(2) << endl;
	cout << "第2个节点的最左子树：" << newtree.GetLeftMostChild(2) << endl;
	cout << "第2个节点的最右子树：" << newtree.GetRightMostChild(2) << endl;
	getchar();
	return 0;
}

/*
输入其子树：6 7
输入第4个节点：4
输入其子树的个数：0
输入第5个节点：5
输入其子树的个数：0
输入第6个节点：6
输入其子树的个数：0
输入第7个节点：7
输入其子树的个数：0

1->2 3 4
2->5
3->6 7
4->
5->
6->
7->
得到的为0表示没有符合要求的
树的根节点：1
第2个节点的数据：2
第2个节点的父亲：1
第2个节点的最左子树：5
第2个节点的最右子树：0

*/