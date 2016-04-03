/**< 气泡排序，快速排序，插入排序，希尔排序，
选择排序，堆排序 ，归并排序，基数排序*/
#include <iostream>
#include<ctime>

#define Max 100000000
using namespace std;

template<class T>
class SortR
{
public:
	SortR()
	{
		arr = new T[Max];
	}
	~SortR(){
		delete[]arr;
	}
	void InputValue();
	void BubbleSort();              //冒泡排序
	void QuickSort();               //快速排序
	void InsertSort();              //插入排序
	void HillSort();                //希尔排序
	void SelectSort();              //选择排序
	void HeapSort();                //堆排序
	void MergeSort();               //归并排序
	void BaseSort();                //基数排序
	void Display(T*);               //输出排序结果
private:
	void Swap(T*, T*)const;

	int findPivot(int, int, T*)const;
	int Partition(int, int, T, T*)const;
	void QuickSortRev(int, int, T*);     //快排递归

	void PushDown(int, int,T*)const;      //堆排序，整理堆

	void  Merge_array(T*,int,int,int,T*);        //合并两个数组
	void merge_sort(T*, int, int, T*);         //归并排序，递归实现

	T GetDigit(T x, int d);
	void msdradix_sort(T*,int,int,int);

	T *arr;
	int n;
};

template<class T>
void SortR<T>::InputValue()
{
	cout << "输入数组大小：";
	//cin >> n;
	n = 10000;
	cout << "输入数组元素：";
	srand((T)time(NULL));
	for (int i = 0; i < n; i++)
		//cin >> arr[i];
		arr[i] = rand() %100000;
}

template<class T>
void SortR<T>::Swap(T*t1, T*t2)const   //交换
{
	T temp;
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

/**< --------冒泡排序------- */
template<class T>
void SortR<T>::BubbleSort()
{
	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();
//----------------------------------------------------
	T *bubble_arr = new T[n];
	for (int i = 0; i < n; i++)
		bubble_arr[i] = arr[i];

	for (int i = 0; i<n; i++)
	{
		for (int j = n - 1; j>i; j--)
		{
			if (bubble_arr[j]<bubble_arr[j - 1])         //后面的比前一个小就交换
				Swap(&bubble_arr[j], &bubble_arr[j - 1]);
		}
	}

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;

	//Display(bubble_arr);
	//Display(arr);

}
/**< -------快速排序-------- */
template<class T>
int SortR<T>::findPivot(int i, int j, T*quick_arr)const    
{
	T firstkey;
	int k;
	firstkey = quick_arr[i];
	for (k = i + 1; k <= j; k++)
	{
		if (quick_arr[k]>firstkey) return k;
		else if (quick_arr[k]<firstkey) return i;
		else  return -1;   //没有不同关键字
	}
	return 0;
}

template<class T>
int SortR<T>::Partition(int i, int j, T piovt, T *quick_arr)const
{
	int l = i, r = j;
	do{
		Swap(&quick_arr[l], &quick_arr[r]);
		while (quick_arr[l]<piovt) l++;
		while (quick_arr[r] >= piovt) r--;
	} while (l <= r);
	return l;
}

template<class T>
void SortR<T>::QuickSortRev(int i, int j, T *quick_arr)
{
	T piovt;
	int piovtindex;
	int k;
	piovtindex = findPivot(i, j, quick_arr);
	if (piovtindex >= 0)
	{
		piovt = quick_arr[piovtindex];
		k = Partition(i, j, piovt, quick_arr);
		//Display(quick_arr);            //输出
		return;                      
		QuickSortRev(i, k - 1, quick_arr);
		QuickSortRev(k, j, quick_arr);
	}
}

template<class T>
void SortR<T>::QuickSort()
{
	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *quick_arr = new T[n];
	for (int i = 0; i < n; i++)
		quick_arr[i] = arr[i];

	QuickSortRev(0, n - 1, quick_arr);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;
	//Display(arr);
}
/*------插入排序------*/
template<class T>
void SortR<T>::InsertSort()     //插入排序
{
	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *insert_arr = new T[n];
	for (int i = 0; i < n; i++)
		insert_arr[i+1] = arr[i];
	insert_arr[0] = -1;
	for (int i = 1; i<n; i++)
	{
		int j = i;
		while (insert_arr[j]<insert_arr[j - 1])
		{
			Swap(&insert_arr[j], &insert_arr[j - 1]);
			j--;
		}
	}
	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;

	//for (int i = 1; i <= 20; i++)
	//	cout << insert_arr[i] << " ";
	//cout << endl;
	//Display(arr);

}
/*-------希尔排序-----------*/
template<class T>
void SortR<T>::HillSort()
{

	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();


	T *hill_arr = new T[n];
	for (int i = 0; i<n; i++)
		hill_arr[i] = arr[i];

	int j, gap;
	for (gap = n / 2; gap > 0;gap/=2)
	for (j = gap; j < n; j++)
	{
		if (hill_arr[j] < hill_arr[j - gap])
		{
			T temp = hill_arr[j];
			int k = j - gap;
			while (k >= 0 && hill_arr[k]>temp)
			{
				hill_arr[k + gap] = hill_arr[k];
				k -= gap;
			}
			hill_arr[k + gap] = temp;
		}
	}
	//Display(hill_arr);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;

}
/*--------选择排序--------*/
template<class T>
void SortR<T>::SelectSort()
{

	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *select_arr = new T[n];
	for (int i = 0; i < n; i++)
		select_arr[i] = arr[i];

	T minindex;  //存储最小的元素
	for (int i = 0; i<n; i++)
	{
		minindex = select_arr[i];
		for (int j = i + 1; j<n; j++)
		{
			if (select_arr[j]<minindex)
			{
				minindex = select_arr[j];
			}
		}
		Swap(&select_arr[i], &minindex);
	}
	//Display(select_arr);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;
}
/*--------堆排序---------*/            
template<class T>
void SortR<T>::PushDown(int first, int last,T *heap_arr)const
{

	int r;
	r = first;
	while (r <= last/2)
	if ((r == last / 2) && (last % 2 ==0))         //r有一个儿子，在2*r
	{
		if (heap_arr[r] > heap_arr[2 * r])
			Swap(&heap_arr[2*r],&heap_arr[r]);
		r = last;
	}
	else if ((heap_arr[r] > heap_arr[2 * r]) && (heap_arr[2*r] <= heap_arr[2 * r + 1]))
	{                                            //r与左儿子交换
		Swap(&heap_arr[2*r], &heap_arr[r]);
		r = 2 * r;
	}
	else if ((heap_arr[r]> heap_arr[2 * r + 1]) && (heap_arr[2 * r+1] <= heap_arr[2*r]))
	{                                             //r与右儿子交换
		Swap(&heap_arr[2*r+1], &heap_arr[r]);
		r = r * 2 + 1;
	}
	else  r = last; 
}

template<class T>
void SortR<T>::HeapSort()
{

	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *heap_arr = new T[n];
	for (int i = 0; i < n; i++)
		heap_arr[i + 1] = arr[i];

	int i;
	for (i = n / 2; i >= 1; i--)
		PushDown(i, n, heap_arr);
	for (i = n; i>1; i--)
	{
		Swap(&heap_arr[1], &heap_arr[i]);

		PushDown(1,i-1, heap_arr);
	}

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;

	/*for (int i = n; i> 0; i--)
		cout << heap_arr[i] << " ";
	cout << endl;*/
}
/*----------归并排序-----------*/
template<class T>
void SortR<T>::Merge_array(T*merge_arr, int first, int midle, int last, T*temp)
{
	int i = first, j = midle + 1;
	int m = midle, l = last, k = 0;
	while (i <= m && j <= l)
	{
		if (merge_arr[i] <= merge_arr[j])
			temp[k++] = merge_arr[i++];
		else
			temp[k++] = merge_arr[j++];
	}
	while (i <= m)
		temp[k++] = merge_arr[i++];
	while (j <= l)
		temp[k++] = merge_arr[j++];
	for (i = 0; i < k; i++)
		merge_arr[first + i] = temp[i];
}

template<class T>
void SortR<T>::merge_sort(T*merge_arr,int first,int last,T*temp)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		merge_sort(merge_arr, first, mid, temp);
		merge_sort(merge_arr, mid + 1, last, temp);
		Merge_array(merge_arr, first, mid, last, temp);
	}
}

template<class T>
void SortR<T>::MergeSort()
{

	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *merge_arr = new T[n];
	for (int i = 0; i < n; i++)
		merge_arr[i + 1] = arr[i];

	T *p = new T[n];
	merge_sort(merge_arr, 1, n, p);


	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;

	/*for (int i = 1; i <= n; i++)
		cout << merge_arr[i] << " ";
	cout << endl;*/
}
/*---------基数排序------------*/
template<class T>
T SortR<T>::GetDigit(T x, int d)
{
	int a[] = { 1, 1, 10};//排的是100以内的
	return (x / a[d]) % 10;
}

template<class T>
void SortR<T>::msdradix_sort(T *base_arr,int first,int last,int d)
{
	int radix = 10;
	int count[10], i, j;
	for (i = 0; i < radix; i++)
		count[i] = 0;
	T*bucker = new T[n];
	for (i = first; i <= last; i++)
		count[GetDigit(base_arr[i], d)]++;

	for (i = 1; i < radix; i++)
		count[i] += count[i - 1];

	for (i = last; i >= first; --i)
	{
		j = GetDigit(base_arr[i], d);
		bucker[count[j] - 1] = base_arr[i];
		--count[j];
	}

	for (i = first,j = 0; i <= last; i++,j++)
		base_arr[i] = bucker[j];

	for (i = 0; i < radix; i++)
	{
		int p1 = first + count[i];
		int p2 = first + count[i + 1] - 1;
		if (p1<p2&&d>1)
			msdradix_sort(base_arr, p1, p2, d - 1);
	}
}

template<class T>
void SortR<T>::BaseSort()
{
	/*cout << "输入所要排的数（先默认0-99的,n值还是最开始的）："<<endl;
	T *base_arr = new T[n];
	for (int i = 0; i < n; i++)
		cin >> base_arr[i];*/

	//---时间测试
	clock_t start, finish;
	double totaltime;
	start = clock();

	T *base_arr = new T[n];
	for (int i = 0; i < n; i++)
		base_arr[i] = arr[i];

	msdradix_sort(base_arr, 0, n - 1, 2);

	//-----------
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "运行时间：" << totaltime << "秒" << endl;

	cout << "排序结果：" << endl;
	//Display(base_arr);

}
/*----------输出函数---------*/
template<class T>
void SortR<T>::Display(T *newarray)
{
	for (int i = 0; i<20; i++)
		cout << newarray[i] << " ";
	cout << endl;

}
/*--------主函数-----------*/
int main()
{
	cout << "排序方法（从小到大）：" << endl;
	SortR<int> mysort;
	mysort.InputValue();
	cout << "气泡排序：" << endl;
	mysort.BubbleSort();
	cout << "快速排序：" << endl;
	mysort.QuickSort();
	cout << "插入排序：" << endl;
	mysort.InsertSort();
	cout << "希尔排序：" << endl;                  
	mysort.HillSort();
	cout << "选择排序：" << endl;
	mysort.SelectSort();
	cout << "堆排序：" << endl;              
	mysort.HeapSort();
	cout << "归并排序：" << endl;           
	mysort.MergeSort();
	cout << "基数排序：" << endl;           
	mysort.BaseSort();
	system("pause");
	return 0;
}
/*
测试100000
排序方法（从小到大）：
输入数组大小：输入数组元素：气泡排序：
运行时间：96.723秒
快速排序：
运行时间：0.001秒
插入排序：
运行时间：73.361秒
希尔排序：
运行时间：0.027秒
选择排序：
运行时间：13.033秒
堆排序：
运行时间：0.065秒
归并排序：
运行时间：0.027秒
基数排序：
运行时间：0.02秒
排序结果：
请按任意键继续. . .


*/