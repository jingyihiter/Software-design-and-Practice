#include<iostream>
#define Max 30  //图中最大顶点数
#define inital 65535
using namespace std;

template<class T>
class Dijkstra
{
public:
	Dijkstra()
	{
		for (int i = 1; i <= Max; i++)
		for (int j = 1; j <= Max; j++)
		{
			if(i==j) 
				GraphC[i][j] = 0;
			else 
				GraphC[i][j] = inital;
		}
	}
	void creatGraph(int,int);
	void dijkstraTree(int);
	void Floyd(int);
private:
	int GraphC[Max][Max];//邻接矩阵
	T adjlist[Max];  //存储顶点
	T mark[Max];  //当前顶点集合
	int D[Max];//存储当前点到源点的集合

	int A[Max][Max];   //Floyd存储两个顶点最短路长的矩阵
};

template<class T>
void Dijkstra<T>::creatGraph(int n,int e)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "输入第" << i << "个顶点：";
		cin >> adjlist[i];
	}
	int x, y, w;
	for (int k = 1; k <= e; k++)
	{
		cout << "输入第" << k << "条边(i->j,权值w)：";
		cin >> x >> y >> w;
		GraphC[x][y] =w;

	}
	cout << "有向图的邻接矩阵：" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << GraphC[i][j] << '\t';
		cout << endl;
	}
}

template<class T>
void Dijkstra<T>::dijkstraTree(int n)
{
	int i, j, min, pos;
	for (i = 1; i <= n; i++)
	{
		mark[i] = 0;//没有点加入
		D[i] = GraphC[1][i];//D置初值
	}
	mark[1] = 1;//源点1加入
	D[1] = 0;
	for (int k = 1;k <= n;k++)
	{
		min = inital;
		for (j = 1; j <= n; j++)
		{
			if ((!mark[j]) && D[j] < min)
			{//取出不在V中的最小的w
				min = D[j];
				pos = j;
			}
		}
		if (min == inital)
			break;
		mark[pos] = 1;
		for (j = 1; j <= n; j++)
		{
			if (!mark[j] && (D[j] > D[pos] + GraphC[pos][j]))
				D[j] = D[pos] + GraphC[pos][j];
		}
	}
	cout << "输出源点1到其他顶点的最短路径：" << endl;
	for (i = 1; i <= n; i++)
		cout << "1->" << i << " :" << D[i] << endl;
}

template<class T>
void Dijkstra<T>::Floyd(int n)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			A[i][j] = GraphC[i][j];//A的初值
		}
	}
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if ((A[i][k] + A[k][j]) < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
	cout << "任意两个顶点之间最短路长矩阵A：" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << A[i][j] << '\t';
		cout << endl;
	}
}
int main()
{
	int n,e;
	Dijkstra<int> dijtree;
	cout << "输入图的顶点数：";
	cin >> n;
	cout << "输入图边条数：";
	cin >> e;
	dijtree.creatGraph(n,e);
	cout << "单源最短路径Dijkstra算法" << endl;
	dijtree.dijkstraTree(n);
	cout << "单源最短路径Floyd算法：" << endl;
	dijtree.Floyd(n);
	getchar();
	return 0;
}
/*
输入：5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
输出：
Dijkstra:
1->1  0
1->2  10
1->3 50
1->4 30
1->5  60
floyd
0       10      50      30      60
65535   0       50      65535   60
65535   65535   0       65535   10
65535   65535   20      0       30
65535   65535   65535   65535   0
*/