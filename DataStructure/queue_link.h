#pragma once

typedef int element_type;

struct Node  //����������
{
	element_type data;  //������
	Node* next; //ָ����
	Node()
	{
		next = nullptr;
	}
};

struct Queue
{
	Node* first;  //����ָ��
	Node* last;   //��βָ��
	Queue()
	{
		first = new Node;  //�½�ͷ���
		last = first;  //���ס���βָ��ָ��ͬһ�����
	}
};

//���
bool EnQueue(Queue* queue, element_type data)
{
	Node* node = new Node;  //�½����
	if (!node)
		return false;  //����ռ�ʧ��
	node->data = data;  //������ֵ
	node->next = nullptr;  //ָ����ֵ

	queue->last->next = node;
	queue->last = node;
	return true;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(Queue* queue)
{
	return queue->first->next == nullptr;
}

//����
bool DeQueue(Queue* queue)
{
	if (IsEmpty(queue))  //����Ϊ��
		return false;
	Node* temp = queue->first->next; //�����ɾ���Ľ��
	queue->first->next = temp->next; //�޸�����ָ���ϵ
	delete temp;
	return true;
}
//��ȡ����Ԫ��
element_type GetFirst(Queue* queue)
{
	if (IsEmpty(queue))  //����Ϊ��
		throw "Queue is empty!";
	return queue->first->next->data;
}
