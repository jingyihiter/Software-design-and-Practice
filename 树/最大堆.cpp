#include <iostream>

using namespace std;

template<class T>
class MaxHeap
{
public:
    MaxHeap(int MaxHeapSize=100);
    ~MaxHeap(){delete []heap;}
    int Size()const{return counter;}
    T Max(){
        if(counter==0)
            {
                cout<<"堆空"<<endl;
                return NULL;
            }
        else return heap[1];}                //最大堆中最大元素
    MaxHeap<T>&Insert(const T&x);             //插入一个元素到最大堆
    MaxHeap<T>&DeleteMax(T&x);                //删除最大堆中一个元素
    void Initialize(T a[],int size,int ArraySize); //初始化最大堆
    void Output();                       //输出最大堆，数组形式
private:
    int MaxSize,counter;             //最大堆当前大小，最大值
    T *heap;
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{
    MaxSize = MaxHeapSize;
    heap = new T[MaxSize+1];
    counter = 0;
}

template<class T>
MaxHeap<T>&MaxHeap<T>::Insert(const T&x)
{
    if(counter == MaxSize)
        {
            cout<<"堆满"<<endl;

        }
    int i;
    i=++counter;
    //cout<<"i="<<i<<endl;
    //i++;
    heap[counter]=0;
    //cout<<"i="<<i<<endl;
    while(i!=1&&x>heap[i/2])
    {
        heap[i]=heap[i/2];
        i/=2;
        //cout<<"堆大小："<<counter<<endl;
    }
    heap[i] = x;
    //cout<<"堆大小："<<counter<<endl;
    //cout<<"堆数组最后一个数："<<heap[counter]<<"----"<<heap[6]<<endl;
    return *this;
}

template<class T>
MaxHeap<T>&MaxHeap<T>::DeleteMax(T&x)
{
    if(counter==0)
        cout<<"堆空"<<endl;
    x = heap[1];
    T y = heap[counter--];
    int i=1;
    int ci = 2;
    while(ci<=counter)
    {
        if(ci<counter&&heap[ci]<heap[ci+1]) ci++;
        if(y>=heap[ci]) break;
        heap[i]=heap[ci];
        i = ci;
        ci*=2;
     }
     heap[i]=y;
    return *this;
}

template<class T>
void MaxHeap<T>::Initialize(T a[],int size,int ArraySize)
{
    delete []heap;
    heap = a;
    counter = size;
    MaxSize = ArraySize;
    for(int i = counter/2;i>=1;i--)
    {
        T y=heap[i];

        int c = 2*i;
        while(c<=counter)
        {
            if(c<counter&&heap[c]<heap[c+1])
            {
                c++;
            }
            if(y>=heap[c]) break;
            heap[c/2] =heap[c];
            c*=2;
        }
        heap[c/2] = y;
    }
}

template<class T>
void MaxHeap<T>::Output()
{//写的是最大堆，不是堆排序，只是根据根节点比左右儿子都大
	cout << "最大堆数组形式：" << endl;
	for (int i = 1; i <= counter; i++)
		cout << heap[i] << " ";
	cout << endl;
	cout << "排序结果：" << endl;
	T *arr = new T[counter+1];
	for (int i = 1; i <= counter; i++)
		arr[i] = heap[i];
	for (int i = 1; i <= counter; i++)
	{
		for (int j = counter; j > i; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				T temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	for (int k = 1; k <= counter; k++)
		cout << arr[k] << " ";
	cout << endl;
}
int main()
{
    MaxHeap<int> heap;
    int n=5;
    cout<<"初始数组大小："<<n<<endl;;
    //cin>>n;
    cout<<"输入的数组：";
    //a = new int[n];
    int a[6]={0,5,4,11,3,7};
    for(int i=1;i<=n;i++)
        //cin>>a[i];
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"初始化为最大堆："<<endl;
    heap.Initialize(a,n,100);
    heap.Output();
    cout<<"\n插入10之后的最大堆：\n";
    heap.Insert(10);
    heap.Output();
    cout<<"当前堆的大小："<<heap.Size()<<endl;
    cout<<"\n删除最大数之后的最大堆：\n";
    int b=0;
    heap.DeleteMax(b);
    heap.Output();
    cout<<"当前堆的大小："<<heap.Size()<<endl;
	getchar();
    return 0;
}
/*
初始数组大小：5
输入的数组：5 4 11 3 7
初始化为最大堆：
最大堆数组形式：
11 7 5 3 4
排序结果：
11 7 5 4 3

插入10之后的最大堆：
最大堆数组形式：
11 7 10 3 4 5
排序结果：
11 10 7 5 4 3
当前堆的大小：6

删除最大数之后的最大堆：
最大堆数组形式：
10 7 5 3 4
排序结果：
10 7 5 4 3
当前堆的大小：5


*/