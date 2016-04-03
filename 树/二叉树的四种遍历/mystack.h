#ifndef mystack_
#define mystack_

using namespace std;
template<class Ts>
struct snode{
	Ts ele;
	snode *next;
};
template<class Ts>
class Mystack{
public:
	Mystack();                //构造函数
	~Mystack();               //析构函数
	void MakeNull();          //栈置空
	bool IsEmpty();           //栈判空
	void Pop();               //删除栈顶元素
	void Push(Ts);              //压栈
	Ts GetTop();              //得到栈顶元素
	void Display();           //打印栈
private:
	snode<Ts> *s;
	int length;
};
#endif
