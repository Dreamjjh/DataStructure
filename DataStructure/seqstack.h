#pragma once
const int MAX = 100;  //栈空间大小
typedef int element_type;

class Stack
{
public:
	bool Push(element_type);//入栈
	bool Pop();//出栈
	
	bool IsEmpty();//判断栈是否为空
	bool IsFull();//判断栈是否满

	element_type Top();  //获取栈顶元素值

	Stack();  //构造函数，完成栈的初始化
	~Stack(); //析构函数，释放内存空间

private:	
	element_type* s;  //数据成员，栈空间首地址（栈底指针）
	int top;  //栈顶指针，指向栈顶元素的下一个位置
};

//判断栈是否为空
inline bool Stack::IsEmpty()
{
	return top == 0;
}

//判断栈是否满
inline bool Stack::IsFull()
{
	return top == MAX;
}

//构造函数
Stack::Stack()
{ 
	top = 0;
	s = new element_type[MAX];
}

//析构函数
Stack::~Stack()
{ 
	delete s;
}

//入栈
bool Stack::Push(element_type data)
{
	//首先判断栈是否满
	if (IsFull())
		return false;
	s[top++] = data; //元素值放入top指向位置，然后下移一个空间
	return true;
}

//出栈
bool Stack::Pop()
{
	//首先判断栈是否为空
	if (IsEmpty())
		return false;
	top--;  //top指针指向下一个元素
	return true;
}

//获取栈顶元素值
element_type Stack::Top()
{
	if (IsEmpty())
		throw "The stack is empty!";
	return s[top - 1];
}

