#include<iostream>
#include "myqueue.h"
template<class Tq>
MyQueue<Tq>::MyQueue()
{
    head = new qnode<Tq>;
    rear = new qnode<Tq>;
    length=0;
}

template<class Tq>
MyQueue<Tq>::~MyQueue()
{
    delete head;
    delete rear;
}

template<class Tq>
void MyQueue<Tq>::MakeNull()
{
  head->next = NULL;
  head = rear;              //表头是第一个节点，也是第二个节点
}

template<class Tq>
bool MyQueue<Tq>::IsEmpty()
{
 if(head==rear)
    return true;
 else return false;
}

template<class Tq>
int MyQueue<Tq>::QueueLength()
{
 return length;
}

template<class Tq>
Tq MyQueue<Tq>::Front()
{
    if(!IsEmpty())
        return head->data;
}
template<class Tq>
void MyQueue<Tq>::EnQueue(Tq t)
{
    rear->next = new qnode<Tq>;
    rear = rear->next;
    rear->data = t;
    rear->next = NULL;
    length++;
}

template<class Tq>
void MyQueue<Tq>::DeQueue()
{
 qnode<Tq> *temp = new qnode<Tq>;
 if(IsEmpty())      cout<<"Queue is empty !"<<endl;
 else {
    temp = head->next;
    head->next = temp->next;
    delete temp;
    length--;
    if(head->next==NULL)
        rear = head;
 }
}

template<class Tq>
void MyQueue<Tq>::Displayq()
{
  qnode<Tq> *p = head;
  while(p&&p->next)
  {
       p=p->next;
      cout<<p->data<<" ";

  }
  cout<<endl;
}
