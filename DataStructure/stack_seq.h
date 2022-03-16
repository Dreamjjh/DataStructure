#pragma once
#define EMPTY -1
#define FAIL 0
#define SUCCESS 1
const int MAX = 100;  //栈空间大小
typedef int element_type;

class Stack
{
public:
	int Push(element_type);//入栈
	int Pop(element_type&);//出站
	
	bool IsEmpty();//判断栈是否为空
	bool IsFull();//判断栈是否满

	Stack();
	~Stack();

private:	
	element_type* s;
	int top;
};

//判断栈是否为空
inline bool Stack::IsEmpty()
{
	return top == EMPTY;
}

//判断栈是否满
inline bool Stack::IsFull()
{
	return top == MAX - 1;
}

//构造函数
Stack::Stack()
{ 
	top = -1;
	s = new element_type[MAX];
}

//析构函数
Stack::~Stack()
{ 
	delete s;
}

//入栈
int Stack::Push(element_type x)
{
	//首先判断栈是否满
	if (top == MAX - 1)
		return FAIL;
	s[++top] = x;
	return SUCCESS;
}

//出栈
int Stack::Pop(element_type& x)
{
	//首先判断栈是否为空
	if (top == EMPTY)
		return EMPTY;
	x = s[top--];  //获取栈顶元素并指向下一个元素
	return SUCCESS;
}


