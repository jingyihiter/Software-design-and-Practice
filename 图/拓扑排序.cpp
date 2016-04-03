/*拓扑排序*/

#include<iostream>
#include<queue>
using namespace std;

#define Max 20

template<class T>
struct node
{
	T data;          //图顶点数据
	int next[Max];     //有向图顶点指向的下一节点序号
	int indegree;   //入度
};

template<class T>
class Graph
{
public:
	Graph()
	{
		for (int i = 1; i <= Max; i++)
		{
			adjlist[i].indegree = 0;
		}

	}
	void creatGraph(int);
	void TopoOrder(int);
private:
	node<T> adjlist[Max];
};

template<class T>
void Graph<T>::creatGraph(int n)
{
	int outdegree;
	int num;
	for (int i = 1; i <= n; i++)
	{
		cout << "输入第" << i << "个顶点：";
		cin >> adjlist[i].data;
		cout << "输入此节点出度：";
		cin >> outdegree;
		if (outdegree == 0) continue;
		cout << "输入此节点指向其他的顶点的序号：";
		for (int j = 1; j <= outdegree; j++)
		{
			cin >> num;
			adjlist[i].next[j] = num;
			adjlist[num].indegree++;
		}
	}

}

template<class T>
void Graph<T>::TopoOrder(int n)
{
	queue<T> q;
	int v, w;
	T lin;
	int nodecount;
	for (v = 1; v <= n; v++)
	{
		if (adjlist[v].indegree == 0)
		{
			q.push(adjlist[v].data);
		}
	}
	nodecount = 0;
	v = 1;
	while (!q.empty())
	{

		if (v > n) break;
		lin = q.front();
		q.pop();
		cout << lin << " ";
		nodecount++;  //输出顶点计数
		for (w = 1; adjlist[v].next[w]>=0&&adjlist[v].next[w]<=Max; w++) //临接于v的每个顶点w
		{
			int temp = adjlist[v].next[w]; //与v相连的节点序号
			adjlist[temp].indegree--;      //删除v发出的边
			if (adjlist[temp].indegree == 0)
				q.push(adjlist[temp].data);
		}
		v++;
	}
		if (nodecount < 0)
			cout << "有向图存在环路" << endl;

}

int main()
{
	Graph<char> graph;
	int n;
	cout << "构建有向图："<<endl;
	cout << "输入图的顶点个数：";
	cin >> n;
	graph.creatGraph(n);
	cout << "拓扑排序：" << endl;
	graph.TopoOrder(n);  //拓扑排序
	//getchar();
	return 0;
}
/*
输入顶点：5
第一个顶点：a 出度：2  指向其他顶点的序号：2 3
b 1 4
c 1 5
d 1 5
e 0
输出：
a b c d e

输入：5
*/
