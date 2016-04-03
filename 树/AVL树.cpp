#include <iostream>
#include<queue>
using namespace std;

bool unbalanced=false;
template <class S>
struct node
{
    S data;
    int bf;
    node<S> *lchild ;
    node<S> *rchild;
};
template <class S>
class BST
{
public:
    node<S>* Search(S k,node<S> *F);
    void AVLInsert(node<S> *&T,S R);
    void PreOrder(node<S> *p);
    void Inorder(node<S>*p);
    void Postorder(node<S>*p);
    void LevelOrder(node<S>*p);
private:
    void LeftRotation(node<S> * &T);
    void RightRotation(node<S>* &T);
};
template<class S>
node<S>*BST<S>::Search (S k,node<S>* F)
{
    if(F==NULL)
        return NULL;
    else if (k==F->data)
        return F;
    else if(k<F->data)
        return(Search(k,F->lchild));
    else
        return(Search(k,F->rchild));
}
template<class S>
void BST<S>::AVLInsert(node<S>*&T,S R)
{
    if(!T)
    {
        unbalanced=true;
        T=new node<S>;
        T->data=R;
        T->lchild=T->rchild=NULL;
        T->bf=0;
    }
    else if(R<T->data)
    {
        AVLInsert(T->lchild,R);
        if(unbalanced)
        {


            switch (T->bf)
            {
            case -1:T->bf=0;
            unbalanced=false;
            break;
            case 0:T->bf=1;
            break;
            case 1:LeftRotation(T);
            }
        }
    }
    else if(R>T->data)
    {
        AVLInsert(T->rchild,R);
        if(unbalanced)
        {
            switch(T->bf)
            {
                case 1:T->bf=0;
                unbalanced=false;
                break;
                case 0:T->bf=-1;
                break;
                case -1:RightRotation(T);
            }
        }
        else
            unbalanced=false;
    }
}
template<class S>
void BST<S>::LeftRotation(node<S>* &T)
{
    node<S>* lc;
    node<S>* gc;
    lc=T->lchild;
    if(lc->lchild)
    {
        T->lchild=lc->rchild;
        lc->rchild=T;
        T->bf=0;
        T=lc;
    }
    else
    {
        gc=lc->rchild;
        lc->rchild=gc->lchild;
        gc->lchild=lc;
        T->lchild=gc->rchild;
        gc->rchild=T;
        switch(gc->bf)
        {
            case 1:T->bf=-1;
            lc->bf=0;break;
            case 0:
                T->bf=lc->bf=0;
                break;
            case -1:T->bf=0;
                lc->bf=1;
        }
        T=gc;
        }
        T->bf=0;
        unbalanced=false;
}
template<class S>
void BST<S>::RightRotation(node<S>* &T)
{
    node<S>* gc;
    node<S>* lc;
    lc=T->rchild;
    if(lc->rchild)
    {
        T->rchild=lc->lchild;
        lc->lchild=T;
        T->bf=0;
        T=lc;
    }
    else
    {
        gc=lc->lchild;
        lc->lchild=gc->rchild;
        gc->rchild=lc;
        T->rchild=gc->lchild;
        gc->lchild=T;
        switch(gc->bf)
        {
            case 1:T->bf=-1;
            lc->bf=0;break;
            case 0:
                T->bf=lc->bf=0;
                break;
            case -1:T->bf=0;
                lc->bf=1;
        }
        T=gc;
        }
        T->bf=0;
        unbalanced=false;
}
template<class S>
void BST<S>::PreOrder(node<S>*p)   //先序遍历
{
    if(p)
    {
        cout<<p->data<<" ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

template<class S>
void BST<S>::Inorder(node<S>*p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

template<class S>
void BST<S>::Postorder(node<S>*p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}
template<class S>
void BST<S>::LevelOrder(node<S> *tree)
{
 queue<node<S>*> q;
 node<S> *newtree = tree;
 if(newtree!=NULL)
    q.push(newtree);
 while(!q.empty())
 {
     newtree = q.front();
     q.pop();
	 cout << newtree->data << " ";
     if(newtree->lchild!=NULL)
        q.push(newtree->lchild);
     if(newtree->rchild!=NULL)
        q.push(newtree->rchild);
 }
}

int main()
{
	BST<int> A;
	int p, q;
	cout << "input number(<0 stop):" << endl;
	cin >> p;
	node<int> *a = NULL;
	node<int> *b;

    while(p>=0)
    {
		A.AVLInsert(a, p);
		cin >> p;
    }
	cout <<"get the tree:"<< endl;
	A.PreOrder(a);
	cout << endl;
	A.Inorder(a);
	cout<<endl;
	A.Postorder(a);
	cout<<endl;
	A.LevelOrder(a);
	cout << endl;
	cout << "input search number"<< endl;
	cin >> q;
	b = A.Search(q, a);
	if (b)
		cout << "b address:" << b << endl;
	else
		cout << "search error" << endl;
	system("pause");
     return 0;
}
/*
input number(<0 stop):
1 2 3 4 5 6 7 8 9 -1
get the tree:
4 2 1 3 6 5 8 7 9       //先序遍历
1 2 3 4 5 6 7 8 9      //中序遍历
1 3 2 5 7 9 8 6 4     //后序遍历
4 2 6 1 3 5 8 7 9    //层序遍历
input search number
3
b address:005B94E0


树的结构：
             4

		2         6

	1      3     5     8
	                
					 7     9
  

请按任意键继续. . .

*/