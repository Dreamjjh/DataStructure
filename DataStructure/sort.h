#ifndef _SORT_H_
#define  _SORT_H_
template <typename T>
class Sort
{
private://���ݳ�Ա
	T* elem;
	int size;
	void Str_Insert_Sort(T*& elem, int n);//ֱ�Ӳ�������
	void Bin_Insert_Sort(T*& elem, int n);//���ֲ�������
	void PrintElems();	//���ȫ������Ԫ��
	void Shell_Sort(T*& elem, int n);//ϣ������
	void Bubble_Sort(T*& elem, int n);//ð������
	void Quick_Sort(T*& elem, int low, int high);//��������
	int Partition(T*& elem, int low, int high);//���������һ�λ���
	void Simple_Selection_Sort(T*& elem, int n);//��ѡ������


public:
	Sort(int n) :size(n) //���캯��
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
	~Sort() //��������
	{
		delete[]elem;
	}

	void Str_Ins_Sort()//ֱ�Ӳ�������
	{
		Str_Insert_Sort(elem, size);
	}
	void BinIntertSort()//���ֲ�������
	{
		Bin_Insert_Sort(elem, size);
	}
	void ShellSort()//ϣ����������
	{
		Shell_Sort(elem, size);
	}
	void SimpleSelectSort()//��ѡ������
	{
		Simple_Selection_Sort(elem, size);
	}
	void BubbleSort()//ð������
	{
		Bubble_Sort(elem, size);
	}
	void QuickSort(int low, int high)//��������
	{
		Quick_Sort(elem, 0, size);
	}
	void Print()//�������Ԫ��
	{
		PrintElems();
	}
};

//ð������
template <typename T>
void Sort<T>::Bubble_Sort(T*& elem, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (elem[j] > elem[j + 1])//������򣬽���
			{
				T temp = elem[j];
				elem[j] = elem[j + 1];
				elem[j + 1] = temp;
			}
		}
}

//��ѡ������
template <typename T>
void Sort<T>::Simple_Selection_Sort(T*& elem, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (elem[k] > elem[j])	//�����бȽ�С��Ԫ�أ�����k��ֵ
				k = j;
		if (i != k)	//���k��ֵ�����ʼ����ֵ������
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
	T pivot = elem[low];//���û�׼����
	while (low < high)
	{
		while (low < high && elem[high] >= pivot)//high��ָԪ�ش��ڻ�׼���ݼ��������ƶ�
			high--;
		elem[low] = elem[high];	//���Ƚ�С��Ԫ������lowָ����ָλ��
		while (low < high && elem[low] <= pivot)//low��ָԪ��С�ڻ�׼���ݼ��������ƶ�
			low++;
		elem[high] = elem[low];	//���Ƚϴ��Ԫ������highָ����ָλ��
	}
	elem[low] = pivot;	//���û�׼����Ϊ�ָ�λ��
	return low;
}

//�Դ�low~high�ļ�¼���п�������
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
	unsigned gap = size / 2;//����������ԭʼΪ�����б���/2
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
		gap = gap / 2;//������Сһ�룬Ϊ��һ��������׼��
	}
}

template <typename T>
void Sort<T>::Str_Insert_Sort(T*& elem, int n)
{
	for (int i = 1; i < n; i++)//�������Ԫ�ظ�����size-1
	{
		T x = elem[i];//�ݴ������ļ�¼
		int j = i - 1;
		for (; j >= 0 && x < elem[j]; j--)
			elem[j + 1] = elem[j];	//��x���Ԫ�ض�������
		elem[j + 1] = x;//�ҵ�x�ĺ���λ�ã�����
	}
}


template <typename T>
void Sort<T>::Bin_Insert_Sort(T*& elem, int n)
{
	for (int i = 1; i < n; i++)//�������Ԫ�ظ�����size-1
	{
		T x = elem[i];//�ݴ������ļ�¼
		//���ֲ��Һ���λ��
		int low = 0, high = i - 1;
		int mid = (low + high) / 2;
		int pos = 0;
		while (low < high)
		{
			mid = (low + high) / 2;
			if (elem[mid] == x)//�ҵ�����λ��
				break;
			else if (elem[mid] < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		for (int j = i - 1; j >= pos; j--)
			elem[j + 1] = elem[j];	//��x���Ԫ�ض�������
		elem[pos] = x;//�ҵ�x�ĺ���λ�ã�����
	}
}


template <typename T>
void Sort<T>::PrintElems()
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (i % 5 == 0)	//5��Ԫ��һ��
			cout << endl;
		cout << elem[i] << " ";
	}
}

#endif