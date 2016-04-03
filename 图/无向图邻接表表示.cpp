#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<queue>
#define NUM 100

using namespace std;

bool visited[NUM];    //访问信息

struct node  //邻接表-线性表
{
	int  index;          //邻接顶点的编号
	struct node *next;   //下一个边节点
};

template<class T>
struct vnode{
	T adjvex;          //顶点数据域
	struct node *fp;    //指向第一个边节点 
};

template<class T>
class  Agraph      //图A的顶点表
{
public:
	vnode<T>  alist[NUM];
	int n, e;
};

template<class T>
class graph
{
public:
	void creatAfraph();

	void dfs();
	void Dfs(int i);
	void bfs();
	void Bfs(int k);
private:
	Agraph<T> A;
};

template<class T>
void graph<T>::creatAfraph()
{
	srand((unsigned)time(NULL));
	cout << "请输入图的顶点数：";
	cin >> A.n;
	cout << "请输入图的边数：";
	cin >> A.e;
	int i, j, k;
	for (i = 0; i < A.n; i++)
	{ 
		A.alist[i].adjvex = i;    //输入顶点的数据域
		A.alist[i].fp = NULL;
	}
	for (k = 0; k < A.e; k++)
	{
		cout << "输入 i,j(0~n-1)（i与j相连接）:" << endl;
		cin >> i >> j;
		node* s = new node;
		s->index = j;
		s->next = A.alist[i].fp;
		A.alist[i].fp = s;
	}
}
template<class T>
void graph<T>::dfs()                  //邻接表存储图的先深遍历
{
	int i;
	for (i = 0; i < A.n; i++)
	{
		visited[i] = false;
	}
	cout << "邻接表存储图的先深遍历" << endl;
	for (i = 0; i < A.n; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
	cout << endl;
}

template<class T>
void graph<T>::Dfs(int i)
{
	node *p;
	cout << A.alist[i].adjvex;
	visited[i] = true;
	p = A.alist[i].fp;
	while (p)
	{
		if (!visited[p->index])
			Dfs(p->index);
		p = p->next;
	}
}
template<class T>
void graph<T>::bfs()           //邻接表存储图的先广遍历
{
	int i;
	for (i = 0; i < A.n; i++)
	{
		visited[i] = false;
	}
	cout << "邻接表存储图的先广遍历" << endl;
	for (i = 0; i < A.n; i++)
	{
		if (visited[i] == false)
			Bfs(i);
	}
}
template<class T>
void graph<T>::Bfs(int k)
{
	int i;
	queue<int>q;
	node *p;
	p = NULL;
	if (!q.empty()) return;
	cout << A.alist[k].adjvex;
	visited[k] = true;
	q.push(k);

	while (q.empty() == false)
	{
		i = q.front();
		q.pop();
		p = A.alist[i].fp;
		while (p)
		{
			if (!visited[p->index])
			{
				cout << A.alist[p->index].adjvex;
				visited[p->index] = true;
				q.pop();

			}
			p = p->next;
		}
	}

}
int main()                //在visual studio 2013运行时，在使用断言的时候，与库内的一些冲突（没找到解决方法）
{                         //请选择忽略,可以正常得出先广遍历的结果
	graph<int> T;
	T.creatAfraph();
	T.dfs();
	T.bfs();
	return 0;
}
/*
请输入图的顶点数：4
请输入图的边数：5
输入 i,j(0~n-1)（i与j相连接）:
0 1
输入 i,j(0~n-1)（i与j相连接）:
0 3
输入 i,j(0~n-1)（i与j相连接）:
1 2
输入 i,j(0~n-1)（i与j相连接）:
1 3
输入 i,j(0~n-1)（i与j相连接）:
2 3
邻接表存储图的先深遍历
0312
邻接表存储图的先广遍历
0312



*/