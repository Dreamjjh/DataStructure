#pragma once

typedef int element_type;

struct Node  //����������
{
	element_type data;  //������
	Node* next; //ָ����
	Node() :next(nullptr), data(-1) {}  //���캯��������ݳ�Ա�ĳ�ʼ��
};

class Queue  //�����У���ͷ���
{
public:
	Queue()//���캯������ɳ�ʼ��
	{
		last = first = new Node;
		if (!first)
			throw "Initializing failed!";
	}  
	bool Push(element_type data);  //���
	bool Pop();  //����
	bool Empty();  //�ж��Ƿ�Ϊ��
	int Size();  //���д�С
	element_type Front();  //��ȡ����Ԫ��

private:
	Node* first;  //����ָ��
	Node* last;   //��βָ��
};

//���
bool Queue::Push(element_type data)
{
	Node* node = new Node;  //�½����
	if (!node)
		return false;   //����ռ�ʧ��
	node->data = data;  //������ֵ
	node->next = nullptr;  //ָ����ֵ

	last->next = node;  //�½�������ڶ�β
	last = node;        //��βָ��ָ��β���
	return true;
}

//�ж϶����Ƿ�Ϊ��
inline bool Queue::Empty()
{
	return first->next == nullptr;
}

//������д�С
int Queue::Size()
{
	int size = 0;
	Node* node = first->next;
	for (Node* node = first->next; node; node = node->next)
		size++;
	return size;
}

//����
bool Queue::Pop()
{
	if (Empty())  //����Ϊ��
		return false;
	Node* temp = first->next; //�����ɾ���Ľ��
	first->next = temp->next; //�޸�����ָ���ϵ
	delete temp;
	return true;
}
//��ȡ����Ԫ��
inline element_type Queue::Front()
{
	if (Empty())  //����Ϊ��
		throw "Queue is empty!";
	return first->next->data;
}
