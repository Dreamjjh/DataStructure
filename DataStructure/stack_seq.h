#pragma once
#define EMPTY -1
#define FAIL 0
#define SUCCESS 1
const int MAX = 100;  //ջ�ռ��С
typedef int element_type;

class Stack
{
public:
	int Push(element_type);//��ջ
	int Pop(element_type&);//��վ
	
	bool IsEmpty();//�ж�ջ�Ƿ�Ϊ��
	bool IsFull();//�ж�ջ�Ƿ���

	Stack();
	~Stack();

private:	
	element_type* s;
	int top;
};

//�ж�ջ�Ƿ�Ϊ��
inline bool Stack::IsEmpty()
{
	return top == EMPTY;
}

//�ж�ջ�Ƿ���
inline bool Stack::IsFull()
{
	return top == MAX - 1;
}

//���캯��
Stack::Stack()
{ 
	top = -1;
	s = new element_type[MAX];
}

//��������
Stack::~Stack()
{ 
	delete s;
}

//��ջ
int Stack::Push(element_type x)
{
	//�����ж�ջ�Ƿ���
	if (top == MAX - 1)
		return FAIL;
	s[++top] = x;
	return SUCCESS;
}

//��ջ
int Stack::Pop(element_type& x)
{
	//�����ж�ջ�Ƿ�Ϊ��
	if (top == EMPTY)
		return EMPTY;
	x = s[top--];  //��ȡջ��Ԫ�ز�ָ����һ��Ԫ��
	return SUCCESS;
}


