#include<iostream>
#include<stack>
#define Max 30 //图最大顶点数、边数
using namespace std;
template<class T>
struct edgenode
{ //边表
	int adjvex;
	int weight;
	struct edgenode<T> *nextedge;
};

template<class T>
struct vexnode
{//顶点表
	T vex;
	int indegree;
	struct edgenode<T> *firstedge;
};

template<class T>
class AOE
{
public:
	
	void CreatAoe();       //构造AOE网，有向图
	void TopSort();        //拓扑排序各顶点最早发生时间及拓扑逆序
	void KeyPath();        //关键路径组成的图
private:
	vexnode<T> vex[Max];
	int n, e;
	T adj[Max];  //存储图的顶点
	int ve[Max], vl[Max]; //最早发生时间和最迟发生时间
	int tuopu_arr[Max];  //存放拓扑排序后的节点序号
};


template<class T>
void AOE<T>::CreatAoe()
{
	cout << "构建AOE网："<<endl;
	cout << "输入顶点个数：";
	cin >> n;
	cout << "输入边条数：";
	cin >> e;
	cout << "输入AOE网的顶点：";
	for (int i = 0; i < n; i++)
	{
		cin >> vex[i].vex;
		vex[i].firstedge = NULL;//初始化为空
	}
	int a, b, w;
	for (int j = 0; j < e; j++) 
	{
		edgenode<T> *p=new edgenode<T>;
		cout << "输入i,j及i->j的权值w:";
		cin >> a >> b >> w;
		p->adjvex = b-1;
		p->weight = w;
		p->nextedge = vex[a-1].firstedge;
		vex[a-1].firstedge = p;  //头插法
	}
}
template<class T>
void AOE<T>::TopSort()
{
	stack<T> s;
	edgenode<T> *p;

	int count = 0;
	int i;
	for (i = 0; i < n; i++)
		vex[i].indegree = 0;            //初始化入队为0
	for (i = 0; i < n; i++)
	{
		p = vex[i].firstedge;
		while (p)
		{
			vex[p->adjvex].indegree++;  //入度加一
			p = p->nextedge;
		}
	} 
	for (i = 0; i < n;i++)
	   if (vex[i].indegree == 0)
		   s.push(i);          //度为0的顶点序号入栈
	for (i = 0; i < n; i++)
		ve[i] = 0;//初始化顶点事件的最早发生时间
	while (!s.empty())
	{
		i = s.top();
		tuopu_arr[count] = i;//存放拓扑排序的序号
	    s.pop();
		cout << vex[i].vex << " ";//栈顶元素输出
		count++;
		p = vex[i].firstedge;
		while (p)
		{
			int k, weight;
			weight = p->weight;
			k = p->adjvex;
			vex[k].indegree--;//删除边
			if (vex[k].indegree == 0)
			{
				s.push(k);
			}
			
			if (ve[i] + weight > ve[k])
				ve[k] = ve[i] + weight;  //计算顶点所有邻接点的最早发生时间
			p = p->nextedge;
			if (count >= n)  break;
		}
	}
	if (count < n) cout << "有环路" << endl;
}
template<class T>
void AOE<T>::KeyPath()
{
	int i, j,m, weight;
	int ee, el;
	edgenode<T>*p;
	cout << "拓扑排序结果：" <<endl;
	TopSort();
	cout << endl;
	for (i = 0; i < n; i++)
		vl[i] = ve[n - 1];//初始化
	
	for (i = 0; i < n; i++)
	{
		int k = tuopu_arr[n - 1 - i];//拓扑的逆序
		for (p = vex[k].firstedge; p; p = p->nextedge)
		{
			m = p->adjvex;
			weight = p->weight;
			if (vl[m] - weight < vl[k])
				vl[k] = vl[m] - weight;
		}
	}
	int k;
	for (i = 0; i < n; i++)
	{
		for (p = vex[i].firstedge; p; p = p->nextedge)
		{
			 k = p->adjvex;
			weight = p->weight;
			ee = ve[i];
			el = vl[k] - weight;
		}
		if (ee == el)
			if(vex[i].vex!=vex[k].vex)cout << "(" << vex[i].vex << "->" << vex[k].vex << ") ";
	}
}
int main()
{
	AOE<char> aoe;
	aoe.CreatAoe();
	aoe.KeyPath();
	getchar();
	system("pause");
	return 0;
}
/*
顶点数：9
边数：11
顶点：a b c d e f g h i
i j 权值：
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
输出：
拓扑排序结果：a b c e g d f h i
(a->b) (b->e) (e->g) (g->i) (h->i) 

*/