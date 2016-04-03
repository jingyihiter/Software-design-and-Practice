#include <iostream>
#define Max 1024

using namespace std;

template<class T>
struct node{
	int row, col;
	T data;
};

template<class T>
class Matrix{
public:
	Matrix();
	~Matrix();
	void input(int, int, int);           //输入
	void Transpose(int, int, int);      //转置
	void output(int, int, int);         //输出
private:
	node<T> *p;
	int num;
};

template<class T>
Matrix<T>::Matrix()
{
	p = new node<T>[num];

}

template<class T>
Matrix<T>::~Matrix()
{
	delete[]p;
}

template<class T>
void Matrix<T>::input(int nrow, int ncol, int num)
{
	cout << "输入元素行、列、元素值：";
	for (int i = 0; i<num; i++)
		cin >> p[i].row >> p[i].col >> p[i].data;
	for (int i = 0; i < num; i++)
		cout << "第" << i + 1 << "个元素的第" << p[i].row + 1 << "行第" << p[i].col + 1 << "列元素值是：" << p[i].data << "\n";
}
template<class T>
void Matrix<T>::Transpose(int nrow, int ncol, int num)
{
	int temp = ncol;
	ncol = nrow;
	nrow = temp;
	for (int i = 0; i<num; i++)
	{
		int temp1 = p[i].col;
		p[i].col = p[i].row;
		p[i].row = temp1;
	}
}

template<class T>
void Matrix<T>::output(int nrow, int ncol, int num)
{
	for (int i = 0; i<nrow; i++)
	{
		for (int j = 0; j<ncol; j++)
		{
			int temp = 0;
			for (int count = 0; count < num; count++)
			{
				if (p[count].row == i&&p[count].col == j)
				{
					cout << p[count].data << " ";
					temp = 1;
					break;
				}
			}
			if (temp == 0) cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
	Matrix<int> news;
	int nrow, ncol, num;
	cout << "输入矩阵的行列，以及非0元素的个数：";
	cin >> nrow >> ncol >> num;
	news.input(nrow, ncol, num);
	cout << "矩阵：" << endl;
	news.output(nrow, ncol, num);
	cout << "转置矩阵：" << endl;
	news.Transpose(nrow, ncol, num);
	news.output(ncol, nrow, num);
	system("pause");
	return 0;
}
/*
输入矩阵的行列，以及非0元素的个数：5 5 5
输入元素行、列、元素值：1 1 2
2 3 8
4 3 6
1 4 3
0 3 2
第1个元素的第2行第2列元素值是：2
第2个元素的第3行第4列元素值是：8
第3个元素的第5行第4列元素值是：6
第4个元素的第2行第5列元素值是：3
第5个元素的第1行第4列元素值是：2
矩阵：
0 0 0 2 0
0 2 0 0 3
0 0 0 8 0
0 0 0 0 0
0 0 0 6 0
转置矩阵：
0 0 0 0 0
0 2 0 0 0
0 0 0 0 0
2 0 8 0 6
0 3 0 0 0
*/