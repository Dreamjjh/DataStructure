#pragma once

typedef int element_type;

struct Node  //链表结点类型
{
	element_type data;  //数据域
	Node* next; //指针域
	Node()
	{
		next = nullptr;
	}
};

struct Queue
{
	Node* first;  //队首指针
	Node* last;   //队尾指针
	Queue()
	{
		first = new Node;  //新建头结点
		last = first;  //队首、队尾指针指向同一个结点
	}
};

//入队
bool EnQueue(Queue* queue, element_type data)
{
	Node* node = new Node;  //新建结点
	if (!node)
		return false;  //申请空间失败
	node->data = data;  //数据域赋值
	node->next = nullptr;  //指针域赋值

	queue->last->next = node;
	queue->last = node;
	return true;
}

//判断队列是否为空
bool IsEmpty(Queue* queue)
{
	return queue->first->next == nullptr;
}

//出队
bool DeQueue(Queue* queue)
{
	if (IsEmpty(queue))  //队列为空
		return false;
	Node* temp = queue->first->next; //保存待删除的结点
	queue->first->next = temp->next; //修改链的指向关系
	delete temp;
	return true;
}
//获取队首元素
element_type GetFirst(Queue* queue)
{
	if (IsEmpty(queue))  //队列为空
		throw "Queue is empty!";
	return queue->first->next->data;
}
