#include "mystack.h"
#include<iostream>

template<class Ts>
Mystack<Ts>::Mystack()
{
	s = new snode<Ts>;
}

template<class Ts>
Mystack<Ts>::~Mystack()
{
	delete s;
}

template<class Ts>
void Mystack<Ts>::MakeNull()
{
	s->next = NULL;
	length = 0;

}
template<class Ts>
bool Mystack<Ts>::IsEmpty()
{
	if (length!=0)
		return false;
	else
		return true;
}

template<class Ts>
void Mystack<Ts>::Pop()
{
	snode<Ts> *p = new snode<Ts>;
	if (s->next != NULL)
	{
		p = s->next;
		s->next = p->next;
		length--;
		delete p;
	}
}

template<class Ts>
void Mystack<Ts>::Push(Ts t)
{
	snode<Ts> *p = new snode<Ts>;
	p->ele = t;
	p->next = s->next;
	s->next = p;
	length++;
}

template<class Ts>
Ts Mystack<Ts>::GetTop()
{
	if (IsEmpty())
	{
		cout << "Õ»¿Õ" << endl;
		return NULL;
	}
	else{
		snode<Ts> *p = new snode<Ts>;
		p=s->next;
		return p->ele;
	}
}

template<class Ts>
void Mystack<Ts>::Display()
{
	snode<Ts> *p = new snode<Ts>;
	p = s;
	while (p&&p->next)
	{
		p = p->next;
		cout << p->ele << " ";

	}
	cout << endl;
}
