#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#define MAX 100
template<class T>
class  node
{
public:
	node()
	{
		next = NULL;
		Treelist = new T[MAX];
	}
	~node()
	{
		delete[]Treelist;
	}
	T data;
	T *Treelist;
	node *next;
};

template<class T>
class Tree
{
public:
	Tree()
	{
		head = new node<T>[MAX];
	}

	~Tree()
	{
		delete[]head;
	}
	void Creat(int);
	T GetLeftMostChild(int);
	T GetRightMostChild(int);
	T GetData(int);
	T GetParent(int);
	T GetRoot();
	void Display(int);
	int GetPosition(T,int);

	node<T> *head;
};



#endif // TREE_H_INCLUDED
