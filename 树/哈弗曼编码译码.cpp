/** 哈弗曼编码译码
*/

#include <iostream>
#include<string>
using namespace std;

#define Maxn 10
#define Maxm (2*Maxn)-1

class Node
{
public:
	Node()
	{
		weight = 0;
		lchild = rchild = parent = 0;
	}
	char data;
	double weight;
	int lchild, rchild, parent;
};
class code
{
public:
	char ch;
	int *bits;
};

class Huffman{
public:
	Huffman()
	{
		huff = new Node*;
		for (int i = 0; i < Maxn; i++)
			huff[i] = new Node;
		huffcode = new code[Maxn];
	}
	void InitHT(Node **huff);
	void InputWeight(Node **huff);
	void Creat()
	{
		CreatHT(huff);
	}
	void CreatHT(Node **huff);
	void SelectMin(Node **huff, int, int &p1, int &p2);
	void HuffEncode();//编码
	void printcode();//输出编码结果
	void HuffDecode();//译码
private:
	Node **huff;
	int n, m;
	code *huffcode;
};


void Huffman::InitHT(Node **huff)//初始化，将权值及左右子树输入到huff[n-1]
{
	for (int i = 0; i < Maxn; i++)
	{
		huff[i] = new Node;
		huff[i]->parent = -1;
		huff[i]->lchild = -1;
		huff[i]->rchild = -1;
		huff[i]->weight = 0;
	}
}

void Huffman::InputWeight(Node **huff)
{
	cout << "输入编码字符个数：";
	cin >> n;
	m = 2 * n - 1;
	cout << "输入字符及权值：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> huff[i]->data;
		cin >> huff[i]->weight;
	}
}
void Huffman::CreatHT(Node **huff)
{//构造哈弗曼树
	int i, p1 = 0, p2 = 1;
	InitHT(huff); //初始化，将权值及左右子树输入到huff[n-1]
	InputWeight(huff);
	for (i = n; i <= m; i++)
	{
		SelectMin(huff, i - 1, p1, p2);
		huff[p1]->parent = huff[p2]->parent = i;
		huff[i]->lchild = p1;
		huff[i]->rchild = p2;
		huff[i]->weight = huff[p1]->weight + huff[p2]->weight;
		
	}
}


void Huffman::SelectMin(Node **huff, int n1, int &p1, int &p2)
{
	int i, j;
	for (i = 0; i < n1; i++)
	{
		if (huff[i]->parent == -1)
		{
			p1 = i;
			break;
		}
	}
	for (j = i + 1; j <= n1; j++)
	{
		if (huff[j]->parent == -1)
		{
			p2 = j;
			break;
		}
	}
	for (i = 0; i < n1; i++)
	{
		if (huff[p1]->weight > huff[i]->weight&&huff[i]->parent == -1 && p2 != i)
			p1 = i;
	}
	for (j = 0; j < n1; j++)
	{
		if (huff[p2]->weight > huff[j]->weight&&huff[j]->parent == -1 && p1 != j)
			p2 = j;
	}
	if (huff[p1]->weight > huff[p2]->weight)
	{
		j = p1;
		p1 = p2;
		p2 = j;
	}

}
void Huffman::HuffEncode()
{
	int c, p, i;
	int start;
	for (i = 0; i < n; i++)
	{
		huffcode[i].bits = new int[n];
		for (int j = 0; j < n; j++)
			huffcode[i].bits[j] = -1;
		huffcode[i].ch = huff[i]->data;
		start = n;
		c = i;
		while ((p = huff[c]->parent) >= 0)
		{
			if (c == huff[p]->lchild)
				huffcode[i].bits[--start] = 0;
			else
				huffcode[i].bits[--start] = 1;
			c = p;
		}
	}
	printcode();
}

void Huffman::printcode()
{
	cout << "编码：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << huffcode[i].ch << " ";
		for (int j = 0; j < n; j++)
		{
			if (huffcode[i].bits[j] == -1)
				continue;
			cout << huffcode[i].bits[j] << " ";
		}
		cout << endl;
	}
}
void Huffman::HuffDecode()
{
	int i, j = 0, length;
	string s;
	cout << "输入译码0和1："<<endl;
	cin >> s;
	length = s.size();
	do{
		i = m;
		do
		{
			if (s[j] == '0')
			{
				i = huff[i]->lchild;
			}
			else if (s[j] == '1')
				i = huff[i]->rchild;
			j++;
		} while (huff[i]->rchild != -1 && j < length);
		cout << huff[i]->data;
	} while (j < length);
}
int main()
{
	Huffman huff;
	huff.Creat();
	huff.HuffEncode();
	huff.HuffDecode();
	getchar();
	system("pause");
	return 0;
}

/*
输入编码字符个数：5
输入字符及权值：
a 0.1
b 2
c 0.9
d 0.6
e 0.8
编码：
a 1 0 0
b 1 1
c 0 1
d 1 0 1
e 0 0
输入译码0和1：
10001010
acc请按任意键继续. . .

*/













