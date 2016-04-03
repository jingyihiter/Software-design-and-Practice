#include <iostream>

using namespace std;
template<class T>
struct node{
	T ele;
	node *next;
};
template<class T>
class Mystack{
public:
	Mystack();                //¹¹Ôìº¯Êý
	~Mystack();               //Îö¹¹º¯Êý
	void MakeNull();          //Õ»ÖÃ¿Õ
	bool IsEmpty();           //Õ»ÅÐ¿Õ
	void Pop();               //É¾³ýÕ»¶¥ÔªËØ
	void Push(T);              //Ñ¹Õ»
	T GetTop();              //µÃµ½Õ»¶¥ÔªËØ
	void Display();           //´òÓ¡Õ»
private:
	node<T> *s;
};

template<class T>
Mystack<T>::Mystack()
{
	s = new node<T>;
}

template<class T>
Mystack<T>::~Mystack()
{
	delete s;
}

template<class T>
void Mystack<T>::MakeNull()
{
	s->next = NULL;
}
template<class T>
bool Mystack<T>::IsEmpty()
{
	if (s->next)
		return false;
	else
		return true;
}

template<class T>
void Mystack<T>::Pop()
{
	node<T> *p = new node<T>;
	if (s->next != NULL)
	{
		p = s->next;
		s->next = p->next;
		delete p;
	}
}

template<class T>
void Mystack<T>::Push(T t)
{
	node<T> *p = new node<T>;
	p->ele = t;
	p->next = s->next;
	s->next = p;
	//cout << "tÑ¹Õ»£º" << p->ele << endl;
}

template<class T>
T Mystack<T>::GetTop()
{
	if (IsEmpty())
	{
		cout << "Õ»¿Õ" << endl;
		return NULL;
	}
	else{
		node<T> *p = new node<T>;
		p=s->next;
		return p->ele;
	}
}

template<class T>
void Mystack<T>::Display()
{
	node<T> *p = new node<T>;
	p = s;
	while (p&&p->next)
	{
		p = p->next;
		cout << p->ele << " ";

	}
	cout << endl;
}
int main()
{
	Mystack<int> mystack;
	int i;
	mystack.MakeNull();
	for (int i = 0; i<10; i++)
		mystack.Push(i);
	mystack.Display();

	cout << "Ñ¹Õ»i£º";
	cin >> i;
	mystack.Push(i);
	mystack.Display();
	cout << "É¾³ýÕ»¶¥ÔªËØ\n";
	mystack.Pop();
	mystack.Display();
	cout << "´ËÊ±Õ»¶¥ÔªËØ£º" << mystack.GetTop() << endl;
	system("pause");
	return 0;
}
/*
9 8 7 6 5 4 3 2 1 0
Ñ¹Õ»i£º34
34 9 8 7 6 5 4 3 2 1 0
É¾³ýÕ»¶¥ÔªËØ
9 8 7 6 5 4 3 2 1 0
´ËÊ±Õ»¶¥ÔªËØ£º9
Çë°´ÈÎÒâ¼ü¼ÌÐø. . .
*/