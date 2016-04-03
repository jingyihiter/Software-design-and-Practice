/*邻接矩阵表示图，先深遍历和先广遍历*/
#include <iostream>
#include<ctime>
#include<stdlib.h>
#include<queue>

#define numV 100                 //顶点数
#define numE 100                 //边数

using namespace std;
         

bool visited[numV];            //访问标记数组
int  dfn[numV];                //顶点的先深编号
//int  count;                    //先深编号
template<class T>
struct MGraph
{
	T Vlist[numV];           //顶点表
	int edge[numE][numE];    //邻接矩阵
};
template<class T>
class Graph
{
public:
	void CreatGraph();      //邻接矩阵生成图
	void outGraph();        //输出邻接矩阵
	void DFST();            //先深遍历
	void DFS_1(MGraph<T>, int);   //先深遍历之邻接矩阵的实现
	void BFST();           //先广遍历
	void BFS_1(MGraph<T>, int);     //先广遍历之邻接矩阵的实现
private:
	int count;
	MGraph<T> G;
	int n;                 //当前定点的个数

};

template<class T>
void Graph<T>::CreatGraph()
{
	srand((unsigned)time(NULL));
	int j;
	cout << "请输入输入顶点数：";
	cin >>n;                   //输入顶点数
	for (int i = 0; i <n; i++)      //读入顶点信息，建立顶点表
	{
		cout << "输入第" << i+1 << "个顶点 ";
		cin >> G.Vlist[i];                        
	}
	cout << endl;
	for (int i = 0; i <n; i++)
	{
		for (j = i; j <n; j++)
		{
			if (i == j) G.edge[i][j] = 0;
			else G.edge[i][j] = rand() % 2;        //随机生成邻接矩阵
			G.edge[j][i] = G.edge[i][j];
		}
	}
}

template<class T>
void Graph<T>::outGraph()      //邻接矩阵的输出
{
	cout << "随机生成邻接矩阵的输出" << endl;
	int i, j;
	int n1;
	n1 = n;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << G.edge[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void Graph<T>::DFST()
{
	int i;
	count = 0;
	for (i = 0; i < n; i++)           //访问标记数组的初始化
	{
		visited[i] = false;
	}
	cout << "先深遍历的结果：" << endl;
	for (i = 0; i <n; i++)
	{
		if (!visited[i])
		{

			DFS_1(G, i);   //先深搜索

		}
	}
	cout << endl;
}
template<class T>
void Graph<T>::DFS_1(MGraph<T> G, int i)     //对邻接矩阵深度优先搜索
{
	int j;
	cout << G.Vlist[i] << " ";
	visited[i] = true;                 //标记已访问的
	dfn[i] = count++;                  //顶点的先深编号
	for (j = 0; j <n; j++)
	{
		if ((G.edge[i][j] == 1) && (visited[j] == false))
			DFS_1(G, j);
	}
}
template<class T>
void Graph<T>::BFST()
{
	int i;
	for (i = 0; i < n; i++)           //访问标记数组的初始化
	{
		visited[i] = false;
	}
	cout << "先广遍历的结果：" << endl;
	for (i = 0; i < n; i++)
	{

		if (visited[i] == false)
		{
			BFS_1(G, i);          //先广搜索
		}
	}
	cout << endl;
}

template<class T>
void Graph<T>::BFS_1(MGraph<T> G, int k)    //先广搜索 从第k号顶点开始 
{
	int  j;
	queue<int> Q;
	Q.push(k);
	while (!Q.empty())
	{

		k = Q.front();
		if (!visited[k]) cout << G.Vlist[k] << " ";
		visited[k] = true;
		Q.pop();
		for (j = 0; j < n; j++)
		{
			if (G.edge[k][j] == 1 && visited[j] == false)
			{
				Q.push(j);
			}
		}
	}
}


int main()
{
	Graph<char> T;                       //应用之前写的随机生成的邻接矩阵，改成了模板类
	T.CreatGraph();
	T.outGraph(); 
	T.DFST();
	T.BFST();
	return 0;
}
/*
请输入输入顶点数：6
输入第1个顶点 a
输入第2个顶点 b
输入第3个顶点 c
输入第4个顶点 d
输入第5个顶点 e
输入第6个顶点 f

随机生成邻接矩阵的输出
0 0 0 1 0 0
0 0 1 0 1 0
0 1 0 1 0 1
1 0 1 0 1 1
0 1 0 1 0 1
0 0 1 1 1 0
先深遍历的结果：
a d c b e f
先广遍历的结果：
a d c e f b
*/