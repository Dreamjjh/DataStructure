#ifndef _SORT_H_
#define  _SORT_H_
#include <iostream>
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
	void Merge_Sort(T*& elem, int low, int high); //归并排序
	void Merge(T*& elem, int left, int mid, int right); //合并左右两个子序列
	void AdjustHeap(T*& elem, int root, int lenth); //调整堆为大根堆
	void Heap_Sort(T*& elem, int n);

public:
	Sort(int n) :size(n) //构造函数
	{
		elem = new T[size + 1];
		if (!elem)
			throw "Memory allocated failed!";
	}
	Sort(T* a, int n) :size(n)
	{
		elem = new T[size + 1];
		if (!elem)
			throw "Memory allocated failed!";
		for (int i = 0; i < size; i++)
			elem[i] = a[i];
	}
	~Sort() //析构函数
	{
		delete[]elem;
	}

	void StringInssertSort()//直接插入排序
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
	void MergeSort(int low, int high)//归并排序
	{
		Merge_Sort(elem, low, high);
	}
	void HeapSort()
	{
		Heap_Sort(elem, size);
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

template<typename T>
void Sort<T>::Merge_Sort(T*& elem, int low, int high)
{
	if (low >= high)  //出口
		return;
	int mid = (low + high) / 2;  //计算中间节点
	Merge_Sort(elem, low, mid);    //分开处理左边部分
	Merge_Sort(elem, mid + 1, high); //分开处理右边部分
	//归并数组左右两边的子序列
	Merge(elem, low, mid, high);
}

template<typename T>
void Sort<T>::Merge(T*& elem, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left; //i,j作为子序列循环变量，k作为临时数组循环变量
	T* temp = new T[size];  //申请辅助数组
	while (i <= mid && j <= right) //两个子序列均没有结束
	{
		if (elem[i] < elem[j]) //前一半的子序列当前元素小于后一半的子序列当前元素
			temp[k++] = elem[i++];
		else
			temp[k++] = elem[j++];
	}
	while (i <= mid)  //前一半子序列未结束，复制剩下的元素
		temp[k++] = elem[i++];
	while (j <= right) //后一半子序列未结束，复制剩下的元素
		temp[k++] = elem[j++];
	//复制临时数组到原始数组
	for (int i = left; i <= right; i++)
		elem[i] = temp[i];
}

template<typename T>
 void Sort<T>::AdjustHeap(T*& elem, int root, int lenth)
{
	 for (root *= 2; root <= lenth; root *= 2)
	 {
		 if (root < lenth && elem[root] < elem[root + 1])//若右孩子大，则让root指向右孩子
			 root++;
		 if (elem[root] > elem[root / 2])  //若子结点大于父结点，则交换
			 swap(elem[root], elem[root / 2]);
		 else
			 break;
	 }
}

template<typename T>
 void Sort<T>::Heap_Sort(T*& elem, int n)
{
	 
	 for (int i = lenth / 2; i >= 1; i--)//建大根堆，从下向上调整
		 AdjustHeap(elem, i, lenth);

	 for (int i = lenth; i >= 2; i--)
	 {
		 swap(elem[i], elem[1]);  //把大的元素交换到后面
		 AdjustHeap(elem, 1, i - 1);
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
		std::cout << elem[i] << " ";
		if ((i + 1) % 5 == 0)	//5个元素一行
			std::cout << std::endl;
	}
}

#endif