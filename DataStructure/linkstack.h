#pragma once

typedef int element_type;

struct Node
{
	element_type data; //数据域
	Node* next;  //指针域
};

class Stack
{
public:
	bool Push(element_type data);  //入栈
	bool Pop(); //出栈
	element_type Top();  //获取栈顶元素
	bool Empty();  //判断栈是否为空
	int Size();  //计算栈的大小
	Stack():top(nullptr){}  //构造函数完成栈的初始化
private:
	Node* top;  //栈顶指针
};

//入栈
bool Stack::Push(element_type data)
{
	Node* p = new Node;  //新建结点
	if (!p) //申请失败
		return false;

	p->data = data; //数据域赋值
	p->next = top;  //指针域赋值
	top = p; //栈顶指针指向新结点

	return true;
}

//出栈
bool Stack::Pop()
{
	if (!top) //栈空的判断
		return false;
	Node* temp = top; //临时指针用作删除结点
	top = top->next;  //出栈
	delete temp;      //释放结点

	return true;
}

inline element_type Stack::Top()
{
	if (Empty())
		throw "Stack is empty!";
	return top->data;
}

inline bool Stack::Empty()
{
	return top == nullptr;  //栈顶指针不为空则栈非空
}

inline int Stack::Size()
{
	int count = 0;
	for (Node* temp = top; temp; temp = temp->next)  //依次遍历链表
		count++;
	return count;
}
