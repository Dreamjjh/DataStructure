#pragma once

typedef int element_type;

struct Node
{
	element_type data; //������
	Node* next;  //ָ����
};

class Stack
{
public:
	bool Push(element_type data);  //��ջ
	bool Pop(); //��ջ
	element_type Top();  //��ȡջ��Ԫ��
	bool Empty();
	Stack():top(nullptr){}
private:
	Node* top;
};


//��ջ
bool Stack::Push(element_type data)
{
	Node* p = new Node;  //�½����
	if (!p) //����ʧ��
		return false;

	p->data = data; //������ֵ
	p->next = top;  //ָ����ֵ
	top = p; //ջ��ָ��ָ���½��

	return true;
}

//��ջ
bool Stack::Pop()
{
	if (!top) //ջ�յ��ж�
		return false;
	Node* temp = top; //��ʱָ������ɾ�����
	//data = top->data; //�β�Я�����ݷ���
	top = top->next;  //��ջ
	delete temp;      //�ͷŽ��

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
	return top == nullptr;
}
