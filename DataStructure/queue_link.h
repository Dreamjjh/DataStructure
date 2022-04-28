#pragma once

typedef int element_type;

struct Node  //链表结点类型
{
	element_type data;  //数据域
	Node* next; //指针域
	Node() :next(nullptr), data(-1) {}  //构造函数完成数据成员的初始化
};

class Queue  //链队列，带头结点
{
public:
	Queue()//构造函数，完成初始化
	{
		last = first = new Node;
		if (!first)
			throw "Initializing failed!";
	}  
	bool Push(element_type data);  //入队
	bool Pop();  //出队
	bool Empty();  //判断是否为空
	int Size();  //队列大小
	element_type Front();  //获取队首元素

private:
	Node* first;  //队首指针
	Node* last;   //队尾指针
};

//入队
bool Queue::Push(element_type data)
{
	Node* node = new Node;  //新建结点
	if (!node)
		return false;   //申请空间失败
	node->data = data;  //数据域赋值
	node->next = nullptr;  //指针域赋值

	last->next = node;  //新结点链接在队尾
	last = node;        //队尾指针指向尾结点
	return true;
}

//判断队列是否为空
inline bool Queue::Empty()
{
	return first->next == nullptr;
}

//计算队列大小
int Queue::Size()
{
	int size = 0;
	Node* node = first->next;
	for (Node* node = first->next; node; node = node->next)
		size++;
	return size;
}

//出队
bool Queue::Pop()
{
	if (Empty())  //队列为空
		return false;
	Node* temp = first->next; //保存待删除的结点
	first->next = temp->next; //修改链的指向关系
	delete temp;
	return true;
}
//获取队首元素
inline element_type Queue::Front()
{
	if (Empty())  //队列为空
		throw "Queue is empty!";
	return first->next->data;
}
