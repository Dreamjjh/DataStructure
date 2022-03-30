#pragma once
const int MAX = 100;  //ջ�ռ��С
typedef int element_type;

class Stack
{
public:
	bool Push(element_type);//��ջ
	bool Pop();//��ջ
	
	bool IsEmpty();//�ж�ջ�Ƿ�Ϊ��
	bool IsFull();//�ж�ջ�Ƿ���

	element_type Top();  //��ȡջ��Ԫ��ֵ

	Stack();  //���캯�������ջ�ĳ�ʼ��
	~Stack(); //�����������ͷ��ڴ�ռ�

private:	
	element_type* s;  //���ݳ�Ա��ջ�ռ��׵�ַ��ջ��ָ�룩
	int top;  //ջ��ָ�룬ָ��ջ��Ԫ�ص���һ��λ��
};

//�ж�ջ�Ƿ�Ϊ��
inline bool Stack::IsEmpty()
{
	return top == 0;
}

//�ж�ջ�Ƿ���
inline bool Stack::IsFull()
{
	return top == MAX;
}

//���캯��
Stack::Stack()
{ 
	top = 0;
	s = new element_type[MAX];
}

//��������
Stack::~Stack()
{ 
	delete s;
}

//��ջ
bool Stack::Push(element_type data)
{
	//�����ж�ջ�Ƿ���
	if (IsFull())
		return false;
	s[top++] = data; //Ԫ��ֵ����topָ��λ�ã�Ȼ������һ���ռ�
	return true;
}

//��ջ
bool Stack::Pop()
{
	//�����ж�ջ�Ƿ�Ϊ��
	if (IsEmpty())
		return false;
	top--;  //topָ��ָ����һ��Ԫ��
	return true;
}

//��ȡջ��Ԫ��ֵ
element_type Stack::Top()
{
	if (IsEmpty())
		throw "The stack is empty!";
	return s[top - 1];
}

