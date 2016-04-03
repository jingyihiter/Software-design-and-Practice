#include <iostream>
#include <string>
using namespace std;

#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

int OK = 1;
int OVER = 0;
int ERROR = 0;

typedef struct
{ 
	char num[10];   //编号
	char name[20];  //姓名
	char sex[6];    //性别
	char phone[13]; //电话
	char addr[31];  //地址
} DataType;

typedef struct
{
	DataType *elem;
	int length;   //当前长度
	int listsize; //线性表的长度
}SqList;

/*主菜单*/
int menu_select()
{
	int choice;
	cout << "\t\t个人通讯录管理系统\t\t\n";
	cout << "***************************************************\n";
	cout << "* 1.建立  " << "2.插入  " << "3.查询  " << "4.删除  " << "5.输出  " << "0.退出 *\n";
	cout << "***************************************************\n";
	cout << "请选择操作 0-5： ";
	for (;;)
	{
		cin >> choice;
		if (choice<0 || choice>5)//小于0大于5
			cout << "输入错误，重选0-5:";
		else
			break;
	}
	cout << endl;
	return choice;
}

void InitList(SqList &L)            //初始化线性表
{
	L.elem = (DataType *)malloc(LIST_INIT_SIZE*sizeof(DataType));

	if (!L.elem)
		exit(OVER);

	L.length = 0;
	L.listsize = LIST_INIT_SIZE;        
}

void CreateList(SqList &L) //建立通讯录
{
	L.elem = (DataType *)malloc(LIST_INIT_SIZE*sizeof(DataType));

	if (!L.elem)
		exit(OVER);

	L.length = 0;
	L.listsize = LIST_INIT_SIZE;//因为建立一个通讯录，即重新开始建立一个，所以要初始化

	int i = 0;
	int flag = 1;

	while (flag == 1)
	{
		cout << "编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)\n";

		cin >> L.elem[i].num >> L.elem[i].name >> L.elem[i].sex >> L.elem[i].phone >> L.elem[i].addr;
		i++;
		L.length++;

		cout << "是否还要继续添加？(0 or 1)：";
		cin >> flag;
		cout << endl;
	}
}

int InsertNode(SqList &L, int i, DataType x)
{
	if (i<1 || i>L.length + 1)//这里L.length加1的目的是，用户可能会在最后边接上元素，并不插，
		return ERROR;

	DataType * newbase;
	DataType * p, *q;
	if (L.length >= L.listsize)
	{
		newbase = (DataType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(DataType));
		if (!newbase)
			exit(OVER);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	/*插入操作*/
	q = &(L.elem[i - 1]);//q为第i个元素的位置
	for (p = &(L.elem[L.length - 1]); p >= q; p--)
	{
		strcpy_s((p + 1)->num, p->num);
		strcpy_s((p + 1)->name, p->name);
		strcpy_s((p + 1)->sex, p->sex);
		strcpy_s((p + 1)->phone, p->phone);
		strcpy_s((p + 1)->addr, p->addr);//i-1之后的元素依次后移一位
	}
	strcpy_s(q->num, x.num);
	strcpy_s(q->name, x.name);
	strcpy_s(q->sex, x.sex);
	strcpy_s(q->phone, x.phone);
	strcpy_s(q->addr, x.addr);

	L.length++;
	return OK;
}
//------通讯录查询------------

void computeLPSArray(char *pat, int M, int *lps);

int KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = (int *)malloc(sizeof(int)*M);
	int j = 0;  // index for pat[]

	computeLPSArray(pat, M, lps);

	int i = 0;  // index for txt[]
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == M)
		{
			j = lps[j - 1];
			return 1;//匹配到对应字符串
		}

		else if (pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	free(lps); 
	return 0;
}

void computeLPSArray(char *pat, int M, int *lps)
{
	int len = 0;  // 记录前一个[最长匹配的前缀和后缀]的长度
	int i;

	lps[0] = 0; // lps[0] 必须是 0
	i = 1;

	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else // 如果 (len == 0)
			{
				lps[i] = 0; //没有一个匹配的
				i++;
			}
		}
	}
}


void ListPhoneFind(char a[], SqList &L)   //动态查询号码
{
	int len = 0;
	for (int i = 0;; i++)
	{
		if (a[i] == '\0')
			break;
		else len++;
	}
	DataType *p;
	char *b=new char[len];
	p = L.elem;
	for (int i = 1; i <= L.length; i++)
	{
		for (int j = 0; j < len; j++)
		{
			b[j] = p[i - 1].phone[j];    //字符串的部分复制
		}
		b[len] = '\0';                  //加上字符串结尾符
		if (strcmp(a, b) == 0)
			cout << p[i - 1].num << " " << p[i - 1].name << " " << p[i - 1].sex << " " << p[i - 1].phone << " " << p[i - 1].addr << " "<<endl;
	}
	cout << "是否继续输入号码（0/1）";
	int nu;
	cin >> nu;
	if (nu)  {
		cout << a;
		char *a1=new char[11-len];
		cin >> a1;
		strcat_s(a,11,a1);    
		ListPhoneFind(a, L);
	}
	else return;
}

int ListFind(SqList &L)
{// 有序通讯录线性表上的查找
	int i = 1;
	int xz;
	DataType *p;
	p = L.elem;
	char SNum[5];
	char SName[9];
	char SPnum[11];
	char Saddr[30];

	do
	{
		cout << "1 按编号查询  2 按姓名查询  3按电话查询  4按地址查询\n";
		cin >> xz;
		cout << endl;
		if (xz != 1 && xz != 2&&xz!=3&& xz!=4)
			cout << "输入错误！\n";
	} while (xz != 1 && xz != 2 && xz!=3&&xz!=4);

	if (xz == 1)
	{
		int j = 0;
		cout << "输入编号：";
		cin >> SNum;
		cout << endl;
		while (i <= L.length && strcmp(p[i - 1].num, SNum) != 0)
			i++;
		if (i>L.length)
			return 0;
		else
			return i;
	}
	else if (xz==2)
	{
		cout << "输入姓名：";
		cin >> SName;
		cout << endl;

		while (i <= L.length && strcmp(p[i - 1].name, SName) != 0)
			i++;

		if (i>L.length)
			return 0;
		else
			return i;
	}

	else if (xz==3)
	{
		cout << "输入电话：";
		cin >> SPnum;
		ListPhoneFind(SPnum, L);                      //输入电话的动态查询
		return -1;
	}
	else
	{
		cout << "输入地址：";                       //输入地址的KMP匹配查询
		cin >> Saddr;
		int flag = 0;
		for (int i = 0; i < L.length; i++)
		{
			if (KMPSearch(Saddr, p[i].addr))
			{
				flag = 1;
				cout << p[i].num << " " << p[i].name << " " << p[i].sex << " " << p[i].phone << " " << p[i].addr << endl;
			}
		}
		if(flag) return -1;
		else return 0;
	}

}
/*删除联系人*/
int DelNode(SqList &L)
{
	DataType * p;
	DataType * q;
	int i;

	cout << "要删除哪个位置上的元素？:";
	cin >> i;
	cout << endl;

	if (i<1 || i>L.length)
		return ERROR;//特殊情况的处理

	p = &(L.elem[i - 1]);
	q = L.elem + L.length - 1;

	for (p; p<q; p++)
	{
		strcpy_s(p->num, (p + 1)->num);//i-1之后的元素依次后移一位
		strcpy_s(p->name, (p + 1)->name);
		strcpy_s(p->sex, (p + 1)->sex);
		strcpy_s(p->phone, (p + 1)->phone);
		strcpy_s(p->addr, (p + 1)->addr);
	}//i之后的元素依次左移
	L.length--;
	return OK;
}

void PrintList(SqList &L)  //输出通讯录
{
	int i;
	for (i = 0; i<L.length; i++)
	{
		cout << L.elem[i].num << " " << L.elem[i].name << " " << L.elem[i].sex << " "
			<< L.elem[i].phone << " " << L.elem[i].addr << endl;
	}
	if (L.length == 0)
		cout << "通讯录中没有元素！\n";
	cout << endl;
}

//主函数
void main()
{
	SqList L;
	InitList(L);
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			cout << "*    通 讯 录 线 性 表 的 建 立     *"<<endl;
			CreateList(L);
			break;
		case 2:
			cout << "*    通 讯 者 信 息 的 添 加     *"<<endl;
			cout << endl;
			cout << "编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)"<<endl;
			DataType p; //申请新结点
			cin >> p.num >> p.name >> p.sex >> p.phone >> p.addr;

			int i;
			int m;
			cout << "想插到哪个位置上？ ";
			cin >> i;
			cout << endl;

			m = InsertNode(L, i, p);

			if (m == ERROR)
				cout << "你输入的元素位置超过了界限！"<<endl;
			else
				cout << "已经插入了该元素！\n"<<endl;
			break;
		case 3:
			int a;
			cout << "*    通 讯 者 信 息 的 查 询     *\n";
			a = ListFind(L);

			if (a != 0&&a!=-1)
			{
				cout << "编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)"<<endl;
				cout << L.elem[a - 1].num << " " << L.elem[a - 1].name << " " << L.elem[a - 1].sex << " "
					<< L.elem[a - 1].phone << " " << L.elem[a - 1].addr << endl;
				cout << endl;
			}
			else if (a==0)
				cout << "没有查到要查询的通讯者！\n";
			break;
		case 4:
			int b;
			cout << "*    通 讯 者 信 息 的 删 除     *\n";
			b = DelNode(L);  //删除结点
			if (b == 0)
				cout << "你输入的元素位置超过界限！\n";
			else
				cout << "已经成功删除了该元素！\n";
			break;
		case 5:
			cout << "*    通 讯 者 信 息 的 输 出     *\n";
			PrintList(L);
			break;
		case 0:
			cout << "\t  通讯录退出，欢迎使用！ \n";
			system("pause");
			return;
		}
	}
}

/*
运行结果：

个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 1

*    通 讯 录 线 性 表 的 建 立     *
编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)
1 张三 男 1130310723 哈尔滨工业大学
是否还要继续添加？(0 or 1)：1

编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)
2 李四 男 11303107244 黑龙江哈尔滨
是否还要继续添加？(0 or 1)：1

编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)
3 王五 男 1130934 哈尔滨南岗区
是否还要继续添加？(0 or 1)：0

个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 2

*    通 讯 者 信 息 的 添 加     *

编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)
4 马良 女 12324 西大直街哈工大
想插到哪个位置上？ 4

已经插入了该元素！

个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 3

*    通 讯 者 信 息 的 查 询     *
1 按编号查询  2 按姓名查询  3按电话查询  4按地址查询
1

输入编号：1

编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)
1 张三 男 1130310723 哈尔滨工业大学

个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 3

*    通 讯 者 信 息 的 查 询     *
1 按编号查询  2 按姓名查询  3按电话查询  4按地址查询
2

输入姓名：张三

编号(4)-姓名(8)-性别(3)-电话(11)-地址(31)
1 张三 男 1130310723 哈尔滨工业大学

个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 3

*    通 讯 者 信 息 的 查 询     *
1 按编号查询  2 按姓名查询  3按电话查询  4按地址查询
3

输入电话：113
1 张三 男 1130310723 哈尔滨工业大学
2 李四 男 11303107244 黑龙江哈尔滨
3 王五 男 1130934 哈尔滨南岗区
是否继续输入号码（0/1）1
113031
1 张三 男 1130310723 哈尔滨工业大学
2 李四 男 11303107244 黑龙江哈尔滨
是否继续输入号码（0/1）1
1130310724
2 李四 男 11303107244 黑龙江哈尔滨
是否继续输入号码（0/1）0
个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 3

*    通 讯 者 信 息 的 查 询     *
1 按编号查询  2 按姓名查询  3按电话查询  4按地址查询
4

输入地址：哈尔滨
1 张三 男 1130310723 哈尔滨工业大学
2 李四 男 11303107244 黑龙江哈尔滨
3 王五 男 1130934 哈尔滨南岗区
个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 4

*    通 讯 者 信 息 的 删 除     *
要删除哪个位置上的元素？:2

已经成功删除了该元素！
个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 5

*    通 讯 者 信 息 的 输 出     *
1 张三 男 1130310723 哈尔滨工业大学
3 王五 男 1130934 哈尔滨南岗区
4 马良 女 12324 西大直街哈工大

个人通讯录管理系统
***************************************************
* 1.建立  2.插入  3.查询  4.删除  5.输出  0.退出 *
***************************************************
请选择操作 0-5： 0

通讯录退出，欢迎使用！
*/