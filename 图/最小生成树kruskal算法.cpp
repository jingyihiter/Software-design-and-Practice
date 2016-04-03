/*最小生成树kruskal算法*/

#include<iostream>

#define maxn 20
using namespace std;
template<class T>
class edgenode
{
public:
	int first;//边的起点顶点序号
	int next; //边终点顶点序号
	int weight;//边的权值

};

template<class T>
class Kruskal
{
public:
	void kruskal();
	void creatGraph();
	void weightOrder();//按权值排序边
	void kruskalTree();
	bool judge(int,int);
private:
	T adj[maxn];      //顶点表
	int n, e;         //顶点数，边数
	edgenode<T> edge[maxn];
	int tree[maxn];
};

template<class T>
void Kruskal<T>::kruskal()
{
	for (int i = 1; i <= maxn; i++)
	{
		tree[i] = -1;//初始父亲为-1
	}
}
template<class T>
void Kruskal<T>::creatGraph()
{
	cout << "输入顶点数目：";
	cin >> n;
	cout << "输入边条数：";
	cin >> e;
	cout << "输入顶点：";
	for (int i = 1; i <= n; i++)
		cin >> adj[i];
	cout << "输入边起点顶点序号，终点顶点序号，权值："<<endl;
	for (int i = 1; i <= e; i++)
	{
		cin >> edge[i].first >> edge[i].next >> edge[i].weight;
		//tree[edge[i].next] = edge[i].first;  //终点的父亲是起点
	}
}

template<class T>
void Kruskal<T>::weightOrder()//希尔排序将边按权值由小到大排序
{
	for (int i = 1; i <= e; i++)
	{
		int j = i;
		while (edge[j].weight < edge[i].weight)
		{
			edgenode<T> *p = new edgenode<T>;
			*p = edge[i];
			edge[i] = edge[j];
			edge[j] = *p;
			j--;
		}
	}
}
template<class T>
bool Kruskal<T>::judge(int first, int next)
{
	if (tree[first] != -1 && tree[next] != -1)
		return false;//都没有父亲
	while (tree[first] != -1)
		first = tree[first];
	while (tree[next] != -1)
		next = tree[next];
	if (first == next)
		return true;
	return false;
}

template<class T>
void Kruskal<T>::kruskalTree()
{
	int j = 1;
	for (int i = 1; i < n; i++,j++)  //n-1条边
	{
		
		if (judge(edge[j].first, edge[j].next))
		{
			i--;
			continue;
		}
		int first = edge[j].first;
		int next = edge[j].next;
		while (tree[first] != -1)
			first = tree[first];
		tree[first] = next;
		//edge[i].first = first;
		//edge[i].next = next;
	}
	int sum = 0;//权值
	for (int i = 1; i < n; i++)
	{
		if (tree[i] == -1)
			continue;
		cout << "(" << adj[edge[i].first] << "," << adj[edge[i].next] << ")";
		sum += edge[i].weight;
	}
	cout << "总权值：" << sum << endl;
}

int main()
{
	Kruskal<char> k;
	k.kruskal();
	k.creatGraph();
	k.weightOrder();
	k.kruskalTree();
	getchar();
	return 0;
}
/*
输入顶点数目：5
输入边条数：6
输入顶点：a b c d e
输入边起点顶点序号，终点顶点序号，权值：
1 2 1
1 3 2
1 4 3
2 5 4
3 5 5
3 4 6
输出：
(a,b)(a,c)(a,d)(b,e)总权值：10


*/
