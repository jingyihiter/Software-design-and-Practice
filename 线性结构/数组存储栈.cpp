#include <iostream>
#define Max 100

using namespace std;

template<class T>
struct Stack{
 int top;
 T  *ele;
};
template<class T>
class Mystack{
public:
    Mystack();
    ~Mystack();
    void MakeNull();
    bool IsEmpty();
    T GetTopEle();
    void Pop();
    void Push(T);
    void DisplayStack();
private:
    Stack<T> *s;
};

template<class T>
Mystack<T>::Mystack()         //构造函数
{
    s = new Stack<T>;
    s->ele = new T[Max];
}
template<class T>
Mystack<T>::~Mystack()             //析构函数
{
    delete s;
    delete []s->ele;
}

template<class T>
void Mystack<T>::MakeNull()           //栈置空
{
    s->top = Max;
}

template<class T>
bool Mystack<T>::IsEmpty()            //判空
{
    if(s->top > Max-1)
         return true;
    else
        return false;
}

template<class T>                        //返回当前栈顶元素
T Mystack<T>::GetTopEle()
{
    if(IsEmpty())
        return NULL;
    else
        return s->ele[s->top];
}

template<class T>
void Mystack<T>::Pop()                 //删除栈顶元素
{
    if(IsEmpty())
        cout<<"Empty !"<<endl;
    else s->top=s->top+1;
}

template<class T>
void Mystack<T>::Push(T x)              //入栈
{
    if(s->top==0)
        cout<<"Full !"<<endl;
    else{
        s->top--;
        s->ele[s->top]=x;
    }
}
template<class T>
void Mystack<T>::DisplayStack()        //打印栈
{
    cout<<"输出栈：";
    int i=s->top;
   while(s->ele!=NULL&&i<Max)
   {
       cout<<s->ele[i]<<" ";
       i++;
   }
   cout<<endl;
}

int main()
{
    Mystack<int> news;
    int i;
    news.MakeNull();
    for(int i=0;i<30;i++)
        news.Push(i);
    news.DisplayStack();

    cout<<"入栈:";
    cin>>i;
    news.Push(i);
    news.DisplayStack();

    cout<<"栈顶元素出栈"<<endl;;
    news.Pop();
    news.DisplayStack();
	system("pause");
    return 0;
}
/*
输出栈：29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4
3 2 1 0
入栈:34
输出栈：34 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5
4 3 2 1 0
栈顶元素出栈
输出栈：29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4
3 2 1 0
请按任意键继续. . .
*/