/*二叉树数组存储结构*/
#include <iostream>

#define Max 100
using namespace std;

template<class T>
class Mytree
{
public:
    Mytree()
    {
        treeA = new T[Max];
    }
    ~Mytree()
    {
        delete []treeA;
    }
    void CreatTree();       //构造满二叉树
    bool Isempty();           //是否为空
    T GetParent(T);          //得到它的父亲
    T GetLchild(T);          //得到它的左儿子
    T GetRchild(T);          //得到它的右儿子

    T GetLbrother(T);         //得到它的左兄弟
    T GetRbrother(T);         //得到它的右兄弟
private:
    T *treeA;
    int treeL;
};

template<class T>
void Mytree<T>::CreatTree()
{
    cout<<"数组长度：";
    cin>>treeL;
    for(int i=1;i<=treeL;i++)     //完全二叉树
    {
        cin>>treeA[i];
    }
}
template<class T>
bool Mytree<T>::Isempty()
{
    return (!treeA);
}
template<class T>
T Mytree<T>::GetParent(T t)
{
    int flag=0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
            {
                flag=1;
                return treeA[i/2];
            }
    }
    if(!flag) return NULL;         //没有父亲节点
}
template<class T>
T Mytree<T>::GetLchild(T t)
{
    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            flag =1;
            return treeA[2*i];
        }
    }
    if(!flag) return NULL;
}

template<class T>
T Mytree<T>::GetRchild(T t)
{

    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            flag =1;
            return treeA[2*i+1];
        }
    }
    if(!flag) return NULL;
}

template<class T>
T Mytree<T>::GetLbrother(T t)
{

    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            if(i!=1&&i%2==1)
            {
                flag =1;
                 return treeA[i-1];
            }
        }
    }
    if(!flag) return NULL;
}

template<class T>
T Mytree<T>::GetRbrother(T t)
{

    int flag =0;
    for(int i=1;i<=treeL;i++)
    {
        if(treeA[i]==t)
        {
            if(i%2==0)
            {
                flag =1;
                return treeA[i+1];
            }
        }
    }
    if(!flag) return NULL;
}
int main()
{
    Mytree<char> tree;
    char a;
    cout<<"一维数组存储二叉树"<<endl;
    tree.CreatTree();
    if(tree.Isempty())
    {
        cout<<"树为空！"<<endl;
            return 0;
    }
    cout<<"输入查询的节点（当查询为空的时候表示没有当前要求的节点）：";
    cin>>a;
    cout<<"父亲节点："<<tree.GetParent(a)<<endl;
    cout<<"左儿子节点："<<tree.GetLchild(a)<<endl;
    cout<<"右儿子节点："<<tree.GetRchild(a)<<endl;
    cout<<"左兄弟节点："<<tree.GetLbrother(a)<<endl;
    cout<<"右兄弟节点："<<tree.GetRbrother(a)<<endl;
	system("PAUSE");
    return 0;
}
/*
一维数组存储二叉树
数组长度：10
a b c d e f g h i j
输入查询的节点（当查询为空的时候表示没有当前要求的节点）：d
父亲节点：b
左儿子节点：h
右儿子节点：i
左兄弟节点：

*/