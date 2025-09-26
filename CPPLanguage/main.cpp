#include <iostream>
using namespace std;

typedef int element_type;
struct Node  //�������
{
	element_type data; //������
	Node* next;  //ָ����
	Node() :next(nullptr),data(0) {}  //���캯�������ò�����ʼ������ɳ�Ա��ʼ��
};
//������������
bool IsEmpty(Node* head);
Node* CreateLinkList_head();
Node* CreateLinkList_head(bool);
Node* CreateLinkList_tail();
Node* CreateLinkList_sort();
void Destroy(Node* head);
bool Insert_back(Node* head, Node* pos, element_type x);
bool Insert_front(Node* head, Node* pos, element_type x);
bool Delete_pos(Node* head, Node* pos);
Node* Search_x(Node* head, element_type x);
void DisplayLinkList(Node* head);
int Delete_value(Node* head, element_type x);

/*�������ܣ��ж������Ƿ�Ϊ�գ���ͷ��㣩
* �����βΣ������ͷָ��(Node* head)
* ��������ֵ������Ϊ�գ�����true�����򷵻�false��bool����
*/
bool IsEmpty(Node* head)
{
	return head->next == nullptr;
}

/*�������ܣ�����ͷ�巨������������ͷ��㣩
* �����βΣ���
* ��������ֵ�����������ͷָ�룬Node*����
*/
Node* CreateLinkList_head()
{
	Node* head = nullptr; //����ͷָ�룬����ֵΪ��
	element_type x;
	cin >> x;  //����Ԫ��ֵ
	while (x != -1)
	{
		Node* p = new Node;  //�����½��
		if (!p)
			return nullptr;
		p->data = x;  //������ֵ
		p->next = head; //ָ����ֵ
		head = p;  //ͷָ��ָ���½��
		cin >> x;  //�ٴν�������
	}
	return head;
}

/*�������ܣ�����ͷ�巨����������ͷ��㣩
* �����βΣ���
* ��������ֵ�����������ͷָ�룬Node*����
*/
Node* CreateLinkList_head(bool _ishead)
{
	Node* head = new Node; //����ͷ��㲢��ʼ��
	if (!head)
		return nullptr;
	element_type x;
	cin >> x;  //����Ԫ��ֵ
	while (x != -1)
	{
		Node* p = new Node;  //�����½��
		if (!p)
			return nullptr;
		p->data = x;  //������ֵ
		p->next = head->next;//ָ����ֵ
		head->next = p;  //ͷָ��ָ���½��
		cin >> x;  //�ٴν�������
	}
	return head;
}

/*�������ܣ�����β�巨����������ͷ��㣩
* �����βΣ���
* ��������ֵ�����������ͷָ�룬Node*����
*/
Node* CreateLinkList_tail()
{
	Node* head , *last; //����ͷ����β���
	head = last = new Node;
	if (!head)
		return nullptr;
	element_type x;
	cin >> x;  //����Ԫ��ֵ
	while (x != -1)
	{
		Node* p = new Node;  //�����½��
		if (!p)
			return nullptr;
		p->data = x;  //������ֵ
		p->next = nullptr; //ָ����ֵ
		last->next = p;  //�½�������β
		last = p;  //lastָ��ָ��β��
		cin >> x;  //�ٴν�������
	}
	return head;
}

/*�������ܣ����򴴽�������ͷ��������
* �����βΣ���
* ��������ֵ���������������ͷָ�룬Node*����
*/
//���� 3 1 2����� 1 2 3
Node* CreateLinkList_sort()
{
	Node* head = new Node; //����ͷ��㲢��ʼ��
	if (!head)
		return nullptr;
	element_type x;
	cin >> x;  //����Ԫ��ֵ
	while (x != -1)
	{
		//���Һ���λ�ý��в���
		Node* p = head->next;  //����ָ��
		while (p && p->data < x)  //ֻҪ�������С��x�������������
			p = p->next;
		if(p)
			Insert_back(head, p, x);  //����ָ������
		else  //����Ϊ�յ����
		{
			Node* node = new Node;  //�����½��
			if (!node)
				return nullptr;
			node->data = x;  //������ֵ
			node->next = head->next;
			head->next = node;
		}
		cin >> x;  //�ٴν�������
	}
	return head;
}

/*�������ܣ���������
* �����βΣ������ͷָ��(Node* head)
* ��������ֵ���ޣ�void����
*/
void Destroy(Node* head)
{
	Node* p = head;  //����ѭ������
	while (p)
	{
		Node* temp = p;
		delete temp;
		p = p->next;  //ָ����һ�����
	}
}

/*�������ܣ����뵽ָ������
* �����βΣ�����ͷָ��Node* head��ָ�����λ��Node* pos���½������element_type x
* ��������ֵ������ɹ�����true�����򷵻�false��bool����
*/
bool Insert_back(Node* head, Node* pos, element_type x)
{
	Node* p = new Node;
	if (!p)
		return false;
	p->data = x;
	p->next = pos->next;
	pos->next = p;
	return true;
}

/*�������ܣ����뵽ָ�����ǰ����ͷ����������δ�ҵ�ָ���ڵ㣬�������β������Ϊ�գ������ͷ����
* �����βΣ�����ͷָ��Node* head��ָ�����λ��Node* pos���½������element_type x
* ��������ֵ������ɹ�����true�����򷵻�false��bool����
*/
bool Insert_front(Node* head, Node* pos, element_type x)
{
	Node* p = new Node;  //�����½��
	if (!p)
		return false;  //�ڴ�����ʧ�ܵĴ���
	p->data = x;   //������ֵ

	if (IsEmpty(head))  //����������뵽ͷ����
	{
		p->next = head->next;
		head->next = p;
		return true;
	}
	//����ָ������ǰ�����,ֻҪ�����Ч�Һ�̽�㲻��pos������󲻶ϲ���pos��ǰ�����
	Node* front = head;
	while (front && front->next != pos)  //��pos��㲻���ڣ���frontָ��β���
		front = front->next;		

	if (!front->next)//δ�ҵ�posָ����㣬����뵽β����
	{
		p->next = front->next;
		front->next = p;
	}
	if (pos)  //�ҵ�pos��ǰ�����
	{
		p->next = pos;
		front->next = p;
	}

	return true;
}

/*�������ܣ�ɾ��ָ����㣨��ͷ�������
* �����βΣ������ͷָ��(Node* head)����ɾ���Ľ���ַ��Node* pos��
* ��������ֵ��ɾ���ɹ�����true�����򷵻�false��bool����
*/
bool Delete_pos(Node* head, Node* pos)
{
	if (!head->next || !pos)  //���������λ��Ϊ�յĲ���
		return false;
	Node* p = head; //����ָ�룬ָ��ͷ���
	while (p && p->next != pos)  //ֻҪ�����Ч�Һ�̽�㲻��pos����󲻶ϲ���pos��ǰ�����
		p = p->next;
	if (p) //�ҵ�ǰ�����
	{
		p->next = pos->next;  //�޸�����ָ���ϵ
		delete pos;  //�ͷŽ��
		return true;
	}
	return false;
}

/*�������ܣ�ɾ��ָ��Ԫ��ֵ�Ľ��
* �����βΣ������ͷָ��(Node* head)����ɾ���Ľ��ֵ��element_type x��
* ��������ֵ������ɾ������������int����
*/
int Delete_value(Node* head, element_type x)
{
	int count = 0;
	Node* node = head;  //��ʱ��㣬���ڱ���������	
	while (node)  //ֻҪ�����������򲻶��ж��Ƿ�ɾ��
	{
		Node* temp = Search_x(head, x); //��ʱ��㣬�����ж��Ƿ�ɾ���ý��
		if (temp && temp->data == x) //�ҵ���ɾ���Ľ��
			Delete_pos(head, temp), count++;  //���ú�����ɾ��ָ����㱾��
		else
			node = node->next;  //��Ҫ��ֻ�е�δɾ����㣬ָ���ָ����һ�����
	}
	return count;
}

/*�������ܣ�����ָ��Ԫ��ֵ��һ�γ��ֵ�λ��
* �����βΣ������ͷָ��(Node* head)�������ҵ�Ԫ��ֵx
* ��������ֵ������Ԫ��ֵx�ĵ�ַ��Node*����
*/
Node* Search_x(Node* head, element_type x)
{
	Node* p = head;  //����ѭ������
	while (p)
	{
		if (p->data == x)
			return p;
		p = p->next;  //ָ����һ�����
	}
	return nullptr;
}

/*�������ܣ�����ָ������ǰ�����
* �����βΣ������ͷָ��(Node* head)��ָ��λ��Node* pos
* ��������ֵ������ǰ�����ĵ�ַ��Node*����
*/
Node* Search_front(Node* head, Node* pos)
{
	Node* p = head;
	while (p && p->next != pos)  //ֻҪ��һ������ַ����pos��������������
		p = p->next;
	return p;
}

/*�������ܣ����������������ͷ��㣩
* �����βΣ������ͷָ��(Node* head)
* ��������ֵ���ޣ�void����
*/
void DisplayLinkList(Node* head)
{
	if (head->next) //ֻҪ����Ϊ��
	{
		Node* p = head->next;  //����ѭ������
		while (p) //������δ����
		{
			cout << p->data << " "; //���������ʵ����������������е���
			p = p->next;  //ָ����һ�����
		}
		cout << endl;
	}
	else
		cout << "Link list is empty!" << endl;
}

int main()
{
	Node* head = CreateLinkList_tail();
	DisplayLinkList(head);

	//cout << Delete_value(head, 1) << endl;
	//Insert_front(head, Search_x(head, 1), 10);
	//DisplayLinkList(head);

	return 0;
}