/*等价类的划分*/
#include<iostream>
#define Max 100
using namespace std;
class node
{
public:
	node()
	{
		father = count = 0;
	}
	int father;
	int count;
};

class MFEST
{
public:
	MFEST()
	{
		arr = new node[Max];
	}

	~MFEST(){
		delete[]arr;
	}
	void Initial(int);
	void Union(int, int);
	int Find(int);
	void EQUIVA(int);
private:
	node *arr;
};

void MFEST::Initial(int i)
{
	arr[i].count = 1;
	arr[i].father = 0;
}

void MFEST::Union(int a, int b)
{
	if (arr[a].count > arr[b].count)
	{
		arr[b].father = a;
		arr[a].count += arr[b].count;
	}
	else
	{
		arr[a].father = b;
		arr[b].count += arr[a].count;
	}
	cout << "并入成功！" << endl;
}


int MFEST::Find(int i)
{
	int f = i;
	while (arr[f].father != 0)
		f = arr[f].father;
	return f;
}

void MFEST::EQUIVA(int n)
{
	int i, j, k, m;
	for (i = 1; i < n + 1; i++)
		Initial(i);//集合i只包含元素i
	cout << "读入等价对（0 0结束）：" << endl;
	cin >> i >> j;
	while (!(i == 0 && j == 0))
	{
		k = Find(i); //i和j的根
		m = Find(j);
		if (k != m)   //i 和 j 不在一棵树上
			Union(i, j);
		else cout << "i和j已经在一棵树上，不用合并" << endl;
		cin >> i >> j;
	}
}

int main()
{
	 MFEST mfe;          
	mfe.Initial(1);
	cout << "集合个数：";
	int n;
	cin >> n;
	mfe.EQUIVA(n);
	int b;
	cin >> b;
	cout<<"b所在树根节点："<<mfe.Find(b);
	return 0;
}


/*
集合个数：5
读入等价对（0 0结束）：
1 3
并入成功！
3 4
并入成功！
4 6
并入成功！
5 4
并入成功！
3 6
i和j已经在一棵树上，不用合并
3 5
i和j已经在一棵树上，不用合并
0 0
5
b所在树根节点：3

*/