#include <iostream>
#include<queue>
#include"myqueue.h"
#include"myqueue.cpp"
using namespace std;
template<class T>
class Node                             //节点类
{
public:
    Node()
    {
        parent=lchild=rchild=NULL;
    }
    T value;
    Node *parent,*lchild,*rchild;
};

template<class T>
class Mytree
{
public:
    Mytree(){tree = new Node<T>;}
    ~Mytree(){delete tree;}


	void Creat(Node<T>**tree);
	void creatTree(Node<T>*&tree);

    bool Isempty(Node<T>*tree);                //判空
             
    T GetRoot(Node<T>*tree);                 //返回树的根
	T GetParent(Node<T>*tree,T);             //得到某个节点的双亲
	int  getheight(Node<T>*tree);            //返回树的高度

    void DeleteNode(Node<T>*,T);             //删除此节点的树
	void clearTree(Node<T>*&tree);
          
	void display(Node<T>*tree);             //先根遍历输出
	Node<T>* levelorder(Node<T>*tree, T);     //得打节点T的指针
	
private:
    Node<T> *tree;
    int flag=0;
};

/**< 构造三叉链表表示的二叉树 */
/**< 按先序遍历输入 */

template<class T>
void Mytree<T>::Creat(Node<T> **tree)   //构造二叉树
{
    T x;
    cin>>x;
    if(x=='#') *tree = NULL;
    else{
        if(!tree) return;
		(*tree) = new Node<T>;
        (*tree)->value = x;
        Creat(&(*tree)->lchild);
        Creat(&(*tree)->rchild);
    }
}
template<class T>
void Mytree<T>::creatTree(Node<T>*& tree)  //二叉树双亲的构造,层序遍历找到将对应的父亲赋给parent
{
  queue<Node<T>*> q;
  Node<T> *newtree=new Node<T>;
  Creat(&tree);        //构造二叉树（缺双亲）
  cout << "先序输出二叉树：" << endl;
  //display(tree); 
  if (tree)  //根节点父亲指针为空
  {
	  tree->parent = NULL;
  }

  q.push(tree);  //根节点入队
  while(!q.empty())
  {
      newtree = q.front();  
      q.pop();
      if(newtree->lchild)   
      {
          newtree->lchild->parent=newtree;
          q.push(newtree->lchild);
      }
      if(newtree->rchild)
      {
          newtree->rchild->parent=newtree;
          q.push(newtree->rchild);
      }
  }
}

template<class T>
bool Mytree<T>::Isempty(Node<T>*tree)
{
	if (tree) return false;
	else return true;
}
/**< 求树的高度 */

template<class T>
int Mytree<T>::getheight(Node<T>* tree)
{
    int lhigh=0,rhigh=0;
    if(!tree) return 0;
    if(tree->lchild)
        lhigh = getheight(tree->lchild);
    if(tree->rchild)
        rhigh = getheight(tree->rchild);
    return lhigh > rhigh ? lhigh+1: rhigh+1;
}
/**< 返回树的根 */

template<class T>
T Mytree<T>::GetRoot(Node<T>*tree)
{
	if (tree)
		return tree->value;
    else 
		return NULL;
}
/**< 树的删除 */

template<class T>
void Mytree<T>::clearTree(Node<T>* &tree)
{
    if(tree)
    { 
		
        clearTree(tree->lchild);   
        clearTree(tree->rchild);
		tree = NULL;
		delete tree;
    }
}
/**< 得到树中某个节点的双亲 */
template<class T>
T Mytree<T>::GetParent(Node<T>*tree,T t)
{
 Node<T>*p = levelorder(tree,t);     //得到节点t的位置
 if(p!=NULL) return p->parent->value;
 else return NULL;
}
/**< 树的先根遍历 */
template<class T>
Node<T>* Mytree<T>::levelorder(Node<T> *tree, T t)
{
	queue<Node<T>*> q;
	Node<T>*newtree =  new Node<T>;
	q.push(tree);
	while (!q.empty())
	{
		newtree = q.front();
		if (newtree->value == t)
			return newtree;
		q.pop();
		if (newtree->lchild)
			q.push(newtree->lchild);
		if (newtree->rchild)
			q.push(newtree->rchild);
	}
	return NULL;
}
/**< 删除二叉树某个节点的子树 */
template<class T>
void Mytree<T>::DeleteNode(Node<T>*tree,T t)
{
	Node<T>*p = levelorder(tree, t);
	if(p)
 {
     p->parent=NULL;
     clearTree(p);
 }
}
/**< 二叉树的输出 */
template<class T>
void Mytree<T>::display(Node<T>* tree)
{
    if(tree)
    {
        cout<<tree->value<<" ";
        display(tree->lchild);
        display(tree->rchild);
    }
}

int main()
{
    cout << "二叉树三叉链表的实现：" << endl;
    Mytree<char> tree;
	Node<char> *mytree=new Node<char>;
    char t,s;
	tree.creatTree(mytree);
	tree.display(mytree);
	cout << endl;
    cout<<"树的高度："<<tree.getheight(mytree)<<endl;
	cout << "树的根："<<tree.GetRoot(mytree)<<endl;
    cout<<"求t的根的双亲:";
    cin>>t;
    cout<<tree.GetParent(mytree,t)<<endl;
    cout<<"删除根节点为s的子树：";
    cin>>s;
    tree.DeleteNode(mytree,s);
	tree.display(mytree);
	getchar();
    return 0;
}
/*
二叉树三叉链表的实现：
a b d # # e # # c f # # #
先序输出二叉树：
a b d e c f
树的高度：3
树的根：a
求t的根的双亲:e
b
删除根节点为s的子树：c
a b d e c




*/