#pragma once
#ifndef __SEARCH_H__
#define __SEARCH_H__

#include <iostream>

template <typename T>  //抽象数据类型
class Search
{
public:
	void Input();  //输入数组元素
	T* SeqSearch(T key);  //顺序查找
	T* SeqSearch_opt(T key);  //顺序查找（优化）
	T* BinSearch(T key, int low, int high); //二分查找（递归实现）
	T* BinSearch_NR(T key);  //二分查找（非递归实现）
	Search(int n = 10);   //默认数组长度为10
	~Search();   //析构函数，释放空间
	
private:
	int number;  //数组的长度
	T* data;     //顺序存储数据元素（下标0用作哨兵）
};

template<typename T>
void Search<T>::Input()//输入数组元素
{
	for (T* temp = data + 1; temp <= data + number; temp++)
		std:: cin >> *temp;
}

template<typename T>
T* Search<T>::SeqSearch(T key) //顺序查找，需要每次判断是否超过边界
{
	for (T* temp = data + 1; temp <= data + number; temp++)
		if (*temp == key)
			return temp;
	return nullptr;
}

template<typename T>
T* Search<T>::SeqSearch_opt(T key)//顺序查找，采用哨兵优化
{
	*data = key;    //数组首元素当作哨兵
	T* temp = data + number;
	while (*temp != key)
		temp--;
	if (temp == data)  //找到头，说明查找元素不存在
		return nullptr;
	return temp;
}

template<typename T>
T* Search<T>::BinSearch(T key, int low, int high)//二分查找（递归实现）
{
	if(low > high)  //查找不到
		return nullptr;
	int mid = (low + high) / 2; //中间点下标
	if (key == *(data + mid))   //查找成功
		return data + mid;
	else if (key < *(data + mid)) //查找关键字小于中间点
		return BinSearch(key, low, mid - 1);
	else
		return BinSearch(key, mid + 1, high);
}

template<typename T>
inline T* Search<T>::BinSearch_NR(T key)//二分查找（非递归实现）
{
	int low = 1, high = number;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (key == *(data + mid)) //查找成功
			return data + mid;
		else if (key < *(data + mid))//查找关键字小于中间点
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
	data = new T[number];  //申请空间
	if (!data)
		throw "Memory allocate failed!";
}

template <typename T>
Search<T>::~Search()
{
	//delete[]data;  //释放空间
}


#endif // !__SEARCH_H__
