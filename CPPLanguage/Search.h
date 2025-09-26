#pragma once
#ifndef __SEARCH_H__
#define __SEARCH_H__

#include <iostream>

template <typename T>  //������������
class Search
{
public:
	void Input();  //��������Ԫ��
	T* SeqSearch(T key);  //˳�����
	T* SeqSearch_opt(T key);  //˳����ң��Ż���
	T* BinSearch(T key, int low, int high); //���ֲ��ң��ݹ�ʵ�֣�
	T* BinSearch_NR(T key);  //���ֲ��ң��ǵݹ�ʵ�֣�
	Search(int n = 10);   //Ĭ�����鳤��Ϊ10
	~Search();   //�����������ͷſռ�
	
private:
	int number;  //����ĳ���
	T* data;     //˳��洢����Ԫ�أ��±�0�����ڱ���
};

template<typename T>
void Search<T>::Input()//��������Ԫ��
{
	for (T* temp = data + 1; temp <= data + number; temp++)
		std:: cin >> *temp;
}

template<typename T>
T* Search<T>::SeqSearch(T key) //˳����ң���Ҫÿ���ж��Ƿ񳬹��߽�
{
	for (T* temp = data + 1; temp <= data + number; temp++)
		if (*temp == key)
			return temp;
	return nullptr;
}

template<typename T>
T* Search<T>::SeqSearch_opt(T key)//˳����ң������ڱ��Ż�
{
	*data = key;    //������Ԫ�ص����ڱ�
	T* temp = data + number;
	while (*temp != key)
		temp--;
	if (temp == data)  //�ҵ�ͷ��˵������Ԫ�ز�����
		return nullptr;
	return temp;
}

template<typename T>
T* Search<T>::BinSearch(T key, int low, int high)//���ֲ��ң��ݹ�ʵ�֣�
{
	if(low > high)  //���Ҳ���
		return nullptr;
	int mid = (low + high) / 2; //�м���±�
	if (key == *(data + mid))   //���ҳɹ�
		return data + mid;
	else if (key < *(data + mid)) //���ҹؼ���С���м��
		return BinSearch(key, low, mid - 1);
	else
		return BinSearch(key, mid + 1, high);
}

template<typename T>
inline T* Search<T>::BinSearch_NR(T key)//���ֲ��ң��ǵݹ�ʵ�֣�
{
	int low = 1, high = number;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (key == *(data + mid)) //���ҳɹ�
			return data + mid;
		else if (key < *(data + mid))//���ҹؼ���С���м��
			high = mid - 1;
		else
			low = mid + 1;
	}
	return nullptr;
}

template <typename T>
Search<T>::Search(int n)
{
	number = n;
	data = new T[number];  //����ռ�
	if (!data)
		throw "Memory allocate failed!";
}

template <typename T>
Search<T>::~Search()
{
	//delete[]data;  //�ͷſռ�
}


#endif // !__SEARCH_H__
