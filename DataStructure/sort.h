#ifndef _SORT_H_
#define  _SORT_H_
template <typename T>
class Sort
{
private://数据成员
	T* elem;
	int size;
	void Str_Insert_Sort(T*& elem, int n);//直接插入排序
	void Bin_Insert_Sort(T*& elem, int n);//二分插入排序
	void PrintElems();	//输出全部数组元素
	void Shell_Sort(T*& elem, int n);//希尔排序
	void Bubble_Sort(T*& elem, int n);//冒泡排序
	void Quick_Sort(T*& elem, int low, int high);//快速排序
	int Partition(T*& elem, int low, int high);//快速排序的一次划分
	void Simple_Selection_Sort(T*& elem, int n);//简单选择排序


public:
	Sort(int n) :size(n) //构造函数
	{
		elem = new T[size];
		if (!elem)
			throw "Memory allocated failed!";
	}
	Sort(int n, T* a) :size(n)
	{
		elem = new T[size];
		if (!elem)
			throw "Memory allocated failed!";
		for (int i = 0; i < size; i++)
			elem[i] = a[i];
	}
	~Sort() //析构函数
	{
		delete[]elem;
	}

	void Str_Ins_Sort()//直接插入排序
	{
		Str_Insert_Sort(elem, size);
	}
	void BinIntertSort()//二分插入排序
	{
		Bin_Insert_Sort(elem, size);
	}
	void ShellSort()//希尔插入排序
	{
		Shell_Sort(elem, size);
	}
	void SimpleSelectSort()//简单选择排序
	{
		Simple_Selection_Sort(elem, size);
	}
	void BubbleSort()//冒泡排序
	{
		Bubble_Sort(elem, size);
	}
	void QuickSort(int low, int high)//快速排序
	{
		Quick_Sort(elem, 0, size);
	}
	void Print()//输出数组元素
	{
		PrintElems();
	}
};

//冒泡排序
template <typename T>
void Sort<T>::Bubble_Sort(T*& elem, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (elem[j] > elem[j + 1])//如果逆序，交换
			{
				T temp = elem[j];
				elem[j] = elem[j + 1];
				elem[j + 1] = temp;
			}
		}
}

//简单选择排序
template <typename T>
void Sort<T>::Simple_Selection_Sort(T*& elem, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (elem[k] > elem[j])	//发现有比较小的元素，更新k的值
				k = j;
		if (i != k)	//如果k的值不是最开始赋的值，交换
		{
			T temp = elem[i];
			elem[i] = elem[k];
			elem[k] = temp;
		}
	}
}

template <typename T>
int Sort<T>::Partition(T*& elem, int low, int high)
{
	T pivot = elem[low];//设置基准数据
	while (low < high)
	{
		while (low < high && elem[high] >= pivot)//high所指元素大于基准数据继续向左移动
			high--;
		elem[low] = elem[high];	//将比较小的元素置于low指针所指位置
		while (low < high && elem[low] <= pivot)//low所指元素小于基准数据继续向右移动
			low++;
		elem[high] = elem[low];	//将比较大的元素置于high指针所指位置
	}
	elem[low] = pivot;	//设置基准数据为分割位置
	return low;
}

//对从low~high的记录进行快速排序
template <typename T>
void Sort<T>::Quick_Sort(T*& elem, int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(elem, low, high);
		Quick_Sort(elem, low, pivotloc - 1);
		Quick_Sort(elem, pivotloc + 1, high);
	}
}

template <typename T>
void Sort<T>::Shell_Sort(T*& elem, int n)
{
	unsigned gap = size / 2;//设置增量，原始为数据列表长度/2
	while (gap)
	{
		for (int i = gap; i < n; i++)
		{
			T insertdata = elem[i];
			int j = i;
			while (j >= gap && insertdata < elem[j - gap])
			{
				elem[j] = elem[j - gap];
				j = j - gap;
			}
			elem[j] = insertdata;
		}
		gap = gap / 2;//增量缩小一半，为下一次排序做准备
	}
}

template <typename T>
void Sort<T>::Str_Insert_Sort(T*& elem, int n)
{
	for (int i = 1; i < n; i++)//待插入的元素个数是size-1
	{
		T x = elem[i];//暂存待排序的记录
		int j = i - 1;
		for (; j >= 0 && x < elem[j]; j--)
			elem[j + 1] = elem[j];	//比x大的元素都往后移
		elem[j + 1] = x;//找到x的合适位置，插入
	}
}


template <typename T>
void Sort<T>::Bin_Insert_Sort(T*& elem, int n)
{
	for (int i = 1; i < n; i++)//待插入的元素个数是size-1
	{
		T x = elem[i];//暂存待排序的记录
		//二分查找合适位置
		int low = 0, high = i - 1;
		int mid = (low + high) / 2;
		int pos = 0;
		while (low < high)
		{
			mid = (low + high) / 2;
			if (elem[mid] == x)//找到合适位置
				break;
			else if (elem[mid] < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		for (int j = i - 1; j >= pos; j--)
			elem[j + 1] = elem[j];	//比x大的元素都往后移
		elem[pos] = x;//找到x的合适位置，插入
	}
}


template <typename T>
void Sort<T>::PrintElems()
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (i % 5 == 0)	//5个元素一行
			cout << endl;
		cout << elem[i] << " ";
	}
}

#endif