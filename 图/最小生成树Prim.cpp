
// Prim算法实现（采用邻接表存储）
//

#include<iostream>

using namespace std;

#define MAX 100
#define Infinity 65535

template<class T>
struct edgeNode
{
	int no; //边端的序号
	T info; //边端的名称
	int weight; //边的权值
	struct edgeNode * next; //下一个
};

template<class T>
struct vexNode
{
	T info;  //节点名称
    edgeNode<T> *link; //与之相连的端点
};


template<class T>
class Prim
{
public:
	bool visited[MAX];        //访问标志
	void creatGraph(int, int, int);
	 void primTree(int,int,int);
private:
	vexNode<T> adjlist[MAX]; //存储节点信息
	int lowcost[MAX];        //lowcost[j]存储从开始节点到节点j的最小花费
	int parent[MAX];          //parent[j]表示节点j的前驱节点
};


//建立邻接表存储
template<class T>
void Prim<T>::creatGraph(int n, int e, int v0)//从第V0个节点开始生成
{
	for (int i = 1; i <= n; i++)
	{
		cout << "请输入节点" << i << "的名称：";
		cin >> adjlist[i].info;
		adjlist[i].link = NULL;
		//初始化
		visited[i] = false;
		lowcost[i] = Infinity;
		parent[i] = v0;
	}
	edgeNode<T> *p1, *p2;
	int v1, v2;       
	int weight;
	for (int i = 1; i <= e; i++)
	{
		cout << "请输入边" << i << "的二端的节点序号：";
		cin >> v1 >> v2;
		cout << "此边的权值：";
		cin >> weight;
		p1 = new edgeNode<T>;
		p2 = new edgeNode<T>;

		p1->no = v1;
		p1->weight = weight;
		p1->info = adjlist[v1].info;
		p1->next = adjlist[v2].link;
		adjlist[v2].link = p1;
		p2->no = v2;
		p2->weight = weight;
		p2->info = adjlist[v2].info;
		p2->next = adjlist[v1].link;
		adjlist[v1].link = p2;
	}
}

template<class T>
void Prim<T>::primTree(int n, int e, int v)
{
	int sum = 0;     //生成树的权值
	edgeNode<T> *p, *q;
	p = adjlist[v].link;
	visited[v] = true;
	while (p != NULL)
	{
		lowcost[p->no] = p->weight;
		p = p->next;
	}
	int minCost;
	for (int i = 1; i<n; i++)
	{
		minCost = Infinity;
		int k;
		for (int j = 1; j <= n; j++)
		{
			if (minCost>lowcost[j] && !visited[j])
			{
				minCost = lowcost[j];
				k = j;
			}
		}
		sum += minCost;
		visited[k] = true;
		q = adjlist[k].link;
		while (q != NULL)
		{
			if (!visited[q->no] && q->weight < lowcost[q->no])
			{
				lowcost[q->no] = q->weight;
				parent[q->no] = k;
			}
			q = q->next;
		}
	}
	cout << "最小生成树的边为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i != v)
			cout << "(" << adjlist[parent[i]].info << "," << adjlist[i].info << ")" << " ";
	}
	cout << endl;
	cout << "最小生成树的权值为：" << sum << endl;

}

int main( )
{
	Prim<int> prim;
	int n, e;
	cout << "请输入节点数：";
	cin >> n;
	cout << "请输入边数：";
	cin >> e;
	cout << "请输入从哪一个节点开始：";
	int v;
	cin >> v;
	prim.creatGraph(n, e, v);
	prim.primTree(n, e, v);
	
	system("pause");
	return 0;
}
/*
输入节点数：5
边数：6
开始节点：1
节点名称：1 2 3 4 5 
边两端序号及权值：
1 2 1
1 3 2
1 4 3
2 5 4
3 5 5
3 4 6
输出：
最小生成树边：<1,2> <1,3> <1,4> <2,5>
最小生成树的权值：10

*/