#include<iostream>
#define MAX 30           //树节点的最大数
using namespace std;

template<class T>
class node
{
public:
	node()
	{
		child = nextsibling = NULL;
	}
	T ele; //节点值
	node*child, *nextsibling;//左儿子右兄弟
};

template<class T>
class Mytree
{
public:
	Mytree()
	{
		tree = NULL;
	}
	~Mytree()
	{
		delete tree;
	}
	void CreatTree(node<T>**);               //构造孩子兄弟表示法的树

	T GetParent(node<T>*,T t);                       //返回树的父亲节点
	T GetLeftChild(node<T>*,T);               //返回树的最左儿子
	T GetRightsibling(node<T>*,T);            //返回树的最右兄弟
	T GetRoot(node<T>*);                    //返回树的根节点
	node<T>* RetPoint(T, node<T>*);        //返回值为t的节点的指针
	node<T>* RetParentPoint(T, node<T>*);//返回值为t的节点父亲指针

	void Display(node<T>*);        //树的左儿子右兄弟表示法的前序、中序、后序遍历
private:
	void preTraverseTree(node<T>*);   //递归先序遍历
	void InTraverseTree(node<T>*);    //递归中序遍历
	void PostTraverseTree(node<T>*);  //递归后序遍历
	node<T> *tree;
};

template<class T>
void Mytree<T>::CreatTree(node<T>**tree)                                     //构造左儿子右兄弟表示的树
{    
                                                                       //以tree为根节点构建
	if ((*tree) != NULL)
	{
		cout << "输入节点" << (*tree)->ele << "的左儿子右兄弟(没有的话输入#)：";
		node<T>*a = new node<T>;
		node<T>*b = new node<T>;
		cin >> a->ele >> b->ele;
		if (a->ele != '#') (*tree)->child = a; //有左儿子
		else (*tree)->child = NULL;
		if (b->ele != '#') (*tree)->nextsibling = b; //有有兄弟
		else (*tree)->nextsibling = NULL;
		CreatTree(&(*tree)->child);             //递归构造树
		CreatTree(&(*tree)->nextsibling);
	}
}

template<class T>
T Mytree<T>::GetParent(node<T> *tree,T t)                                   //返回节点值为t的父亲
{
	node<T>*p = RetParentPoint(t, tree);
	if (p)	return p->ele;
	else return NULL;
}

template<class T>
T Mytree<T>::GetRoot(node<T>*tree)                                          //返回树的根节点值
{
	return tree->ele;
}
template<class T>
T Mytree<T>::GetLeftChild(node<T>*tree,T t)                    //返回树的左儿子
{
	
	node<T>*p=RetPoint(t, tree);
	if (p&&p->child) return p->child->ele;
	else return NULL;
}

template<class T>
T Mytree<T>::GetRightsibling(node<T>*tree,T t)                //得到树tree的右兄弟
{
	node<T>*p=RetPoint(t, tree);
	if (p&&p->nextsibling) return p->nextsibling->ele;
	else return NULL;
}

template<class T>
void Mytree<T>::Display(node<T>*tree)                               //三种递归遍历
{
	cout << "先序递归遍历：";
	preTraverseTree(tree);
	cout << endl;
	cout << "中序递归遍历：";
	InTraverseTree(tree);
	cout <<endl;
	cout << "后序递归遍历：";
	PostTraverseTree(tree);
	cout << endl;
}

template<class T>
void Mytree<T>::preTraverseTree(node<T>*tree)  //先序递归遍历
{
	if (tree)
	{
		cout << tree->ele << " ";
		preTraverseTree(tree->child);
		preTraverseTree(tree->nextsibling);
	}
}

template <class T>
void Mytree<T>::InTraverseTree(node<T>*tree)  //中序递归遍历
{
	if (tree)
	{
		InTraverseTree(tree->child);
		cout << tree->ele << "　";
		InTraverseTree(tree->nextsibling);
	}
}

template<class T>
void Mytree<T>::PostTraverseTree(node<T>*tree)  //后序递归遍历
{
	if(tree)
	{
		PostTraverseTree(tree->nextsibling);
		PostTraverseTree(tree->child);
		cout << tree->ele << " ";
	}
}

template<class T>
node<T>* Mytree<T>::RetPoint(T t, node<T>* tree)     //返回树节点值为t的指针
{
	if (tree)
	{
		if (tree->ele == t) return tree;
		else if (RetPoint(t, tree->child)!=NULL)
		{
		return RetPoint(t, tree->child);
	
		}
		else if (RetPoint(t, tree->nextsibling) != NULL)
		{
		return RetPoint(t, tree->nextsibling);
		}
		else  return NULL;
	}
	else return NULL;
}

template<class T>
node<T>* Mytree<T>::RetParentPoint(T t, node<T>*tree)
{
	if (tree&&tree->child)
	{
		if (tree->ele == t)  return tree;
		else if (RetParentPoint(t, tree->child))
			return RetParentPoint(t, tree->child);
		else if (RetParentPoint(t, tree->nextsibling))
			return RetParentPoint(t, tree->nextsibling);
		else return NULL;
	}
}
int main()
{
	Mytree<char> mytree;
	node<char> *root = new node<char>;
	cout << "输入根节点：";
	cin >> root->ele;
	mytree.CreatTree(&root);
	cout<<"树的根："<<mytree.GetRoot(root)<<endl;

	cout << "输入t：";
	char t;
	cin >> t;
	cout << "t的左儿子" << mytree.GetLeftChild(root, t) << endl;
	cout << "t的右兄弟" << mytree.GetRightsibling(root, t) << endl;
	cout << "t的父节点：" << mytree.GetParent(root,t) << endl;
	cout << "树的左儿子右兄弟表示法的三种遍历：" << endl;
	mytree.Display(root);
	return 0;
}

/*
输入根节点：a
输入节点a的左儿子右兄弟(没有的话输入#)：b c
输入节点b的左儿子右兄弟(没有的话输入#)：d e
输入节点d的左儿子右兄弟(没有的话输入#)：# #
输入节点e的左儿子右兄弟(没有的话输入#)：f g
输入节点f的左儿子右兄弟(没有的话输入#)：# #
输入节点g的左儿子右兄弟(没有的话输入#)：# #
输入节点c的左儿子右兄弟(没有的话输入#)：h #
输入节点h的左儿子右兄弟(没有的话输入#)：# #
树的根：a
输入t：c
t的左儿子h
t的右兄弟



*/