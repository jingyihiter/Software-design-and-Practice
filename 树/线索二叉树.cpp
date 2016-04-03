#include <iostream>

using namespace std;

template<class T>
class Node
{
public:
    Node()
    {
        lchild = rchild = NULL;
    }
    T value;
    Node *lchild,*rchild;
    bool ltag,rtag;
};

template<class T>
class TBT
{
public:
    TBT();
    ~TBT();
    void CreatBitThrTree(Node<T>**); //构造二叉树
	void InThread(Node<T>*&,Node<T>*&);//中序线索化
	void Inorder(Node<T>*&);//中序遍历
	void InsertHead(Node<T>*&);
	void display(Node<T>*);
private:
    Node<T>*tree;
};

template<class T>
TBT<T>::TBT()
{
    tree = NULL;
}

template<class T>
TBT<T>::~TBT()
{
    delete tree;
}
template<class T>
void TBT<T>::CreatBitThrTree(Node<T>**tree)//先序建立二叉树
{
    T ch;
    cin>>ch;
    if(ch<0)
        {
            (*tree) = NULL;
			return;
        }
	(*tree) = new Node<T>;
    if(!(*tree)) return;
    (*tree)->value = ch;
    CreatBitThrTree(&(*tree)->lchild);
    CreatBitThrTree(&(*tree)->rchild);
}
template<class T>
void TBT<T>::display(Node<T>*tree)
{
	if (tree)
	{
		display(tree->lchild);
		cout << tree->value << " ";
		display(tree->rchild);
	}
}
template<class T>
void TBT<T>::InThread(Node<T>*&p,Node<T>*&pre)//中序线索化
{
	if (p)
	{
		InThread(p->lchild,pre);//左子树线索化
		if (!p->lchild)  
		{
			p->ltag = true;
			p->lchild = pre;
		}
		else p->ltag = false;

		if (!pre->rchild&&pre)
		{
			pre->rtag = true;
			pre->rchild = p;
		}
		pre = p;
		pre->rtag = false;
		InThread(p->rchild,pre);
	}
}

template<class T>
void TBT<T>::Inorder(Node<T>*&tree)
{
	Node<T>*p = tree->lchild;
	while (p != tree)
	{
		while (p->ltag == false)
		{
			p = p->lchild;
		}

		cout << p->value << " ";

		while (p->rtag == true && p->rchild != tree)
		{
			p = p->rchild;
			cout << p->value << " ";
		}

		p = p->rchild;
	}
	cout << p->value << " ";
	if (p->rchild) cout << p->rchild->value << " ";
}

template<class T>
void TBT<T>::InsertHead(Node<T>*&t)//添加头节点
{
	Node<T>*h = new Node<T>;
	Node<T>*pre = new Node<T>;
	h->rchild = h;
	h->ltag = false;
	h->rtag = true;
	if (!t)
	{
		h->lchild = h;
	}
	else
	{
	
		h->lchild = t;
		pre = h;
		InThread(t,pre);
		pre->rchild = h;
		pre->rtag = true;
		h->rchild = pre;
	}
}
int main()
{
   TBT<int> Tbtree;
   Node<int> *tree =new Node<int>;
   cout << "先序建立二叉树：" << endl;
   Tbtree.CreatBitThrTree(&tree);
   cout << "中序递归遍历二叉树：" << endl;
   Tbtree.display(tree);
   cout << endl;
   cout << "线索化之后中序遍历：" << endl;
   Tbtree.InsertHead(tree);
   Tbtree.Inorder(tree);
   cout << endl;
   system("PAUSE");
   return 0;
}

/*
先序建立二叉树：
1 2 4 -1 -1 5 -1 -1 3 -1 -1
中序递归遍历二叉树：
4 2 5 1 3
线索化之后中序遍历：
4 2 5 1 3


二叉树：
      1

	2   3

 4    5
*/