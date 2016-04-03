/*树的双亲表示法*/
#include<iostream>

#define MAX 100
using namespace std;

template<class T>
class node
{
public:
	T data;
	int parent;
};

template<class T>
class Tree
{
public:
	Tree()
	{
		Treenode = new node<T>[MAX];
	}
	~Tree()
	{
		delete []Treenode;
	}
	T GetParent(int);
	T GetLeftMostChild(int,int);
	T GetRightMostChild(int,int);
	T GetData(int);
	void CreatK(int);
	T GetRoot();
private:
	node<T> *Treenode;
};

template<class T>
void Tree<T>::CreatK(int n)
{
	cout << "输入树的节点，及其父亲的位置：" << endl;
	cout << "输入根节点：";
	cin >> Treenode[1].data;
	Treenode[1].parent = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> Treenode[i].data;
		cin >> Treenode[i].parent;
	}
}

template<class T>
T Tree<T>::GetParent(int i)
{
	int p = Treenode[i].parent;
	return Treenode[p].data;
}

template<class T>
T Tree<T>::GetData(int i)
{
	return Treenode[i].data;
}

template<class T>
T Tree<T>::GetRoot()
{
	return Treenode[1].data;
}

template<class T>
T Tree<T>::GetLeftMostChild(int i,int n) //最先出现的是最左节点，最后出现的是最右节点
{
	for (int k = 1; k <= n; k++)
	{
		if (Treenode[k].parent == i)
			return Treenode[k].data;
	}
	return NULL;//没有最左节点
}

template<class T>
T Tree<T>::GetRightMostChild(int i, int n)
{
	int flag = 0,j;
	for (int k = n; k > 0; k--)
	{
		if (Treenode[k].parent == i)
		{
			for (j = k - 1; j > 0; j--)
			{
				if (Treenode[j].parent == i)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1) return Treenode[k].data;
		}
	}
	return NULL;//没有最右节点
}
//测试
int main()
{
    cout<<"树的双亲表示法"<<endl;
	Tree<char> newtree;
	int n;
	cout << "输入树节点数目：";
	cin >> n;
	newtree.CreatK(n);
	cout << "当没有对应数据输出，表示没有" << endl;
	cout << "第三个节点的树的值：" << newtree.GetData(3) << endl;
	cout << "第三个节点的最左子树根节点值：" << newtree.GetLeftMostChild(3, n) << endl;
	cout << "第三个节点的最右子树根节点值：" << newtree.GetRightMostChild(3, n) << endl;
	cout << "第三个节点的父亲节点值：" << newtree.GetParent(3) << endl;
	cout << "根节点值：" << newtree.GetRoot() << endl;
	getchar();
	return 0;
}
/*
树的双亲表示法
输入树节点数目：7
输入树的节点，及其父亲的位置：
输入根节点：a
b 1
c 2
d 1
e 4
f 3
g 2
当没有对应数据输出，表示没有
第三个节点的树的值：c
第三个节点的最左子树根节点值：f
第三个节点的最右子树根节点值：

*/


