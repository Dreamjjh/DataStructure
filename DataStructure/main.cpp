#include <iostream>
using namespace std;

typedef int element_type;
struct Node  //结点类型
{
	element_type data; //数据域
	Node* next;  //指针域
	Node() :next(nullptr),data(0) {}  //构造函数，利用参数初始化表完成成员初始化
};
//函数声明部分
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

/*函数功能：判断链表是否为空（带头结点）
* 函数形参：链表的头指针(Node* head)
* 函数返回值：链表为空，返回true；否则返回false，bool类型
*/
bool IsEmpty(Node* head)
{
	return head->next == nullptr;
}

/*函数功能：采用头插法创建链表（不带头结点）
* 函数形参：无
* 函数返回值：返回链表的头指针，Node*类型
*/
Node* CreateLinkList_head()
{
	Node* head = nullptr; //创建头指针，并赋值为空
	element_type x;
	cin >> x;  //输入元素值
	while (x != -1)
	{
		Node* p = new Node;  //申请新结点
		if (!p)
			return nullptr;
		p->data = x;  //数据域赋值
		p->next = head; //指针域赋值
		head = p;  //头指针指向新结点
		cin >> x;  //再次进行输入
	}
	return head;
}

/*函数功能：采用头插法创建链表（带头结点）
* 函数形参：无
* 函数返回值：返回链表的头指针，Node*类型
*/
Node* CreateLinkList_head(bool _ishead)
{
	Node* head = new Node; //创建头结点并初始化
	if (!head)
		return nullptr;
	element_type x;
	cin >> x;  //输入元素值
	while (x != -1)
	{
		Node* p = new Node;  //申请新结点
		if (!p)
			return nullptr;
		p->data = x;  //数据域赋值
		p->next = head->next;//指针域赋值
		head->next = p;  //头指针指向新结点
		cin >> x;  //再次进行输入
	}
	return head;
}

/*函数功能：采用尾插法创建链表（带头结点）
* 函数形参：无
* 函数返回值：返回链表的头指针，Node*类型
*/
Node* CreateLinkList_tail()
{
	Node* head , *last; //创建头结点和尾结点
	head = last = new Node;
	if (!head)
		return nullptr;
	element_type x;
	cin >> x;  //输入元素值
	while (x != -1)
	{
		Node* p = new Node;  //申请新结点
		if (!p)
			return nullptr;
		p->data = x;  //数据域赋值
		p->next = nullptr; //指针域赋值
		last->next = p;  //新结点插入链尾
		last = p;  //last指针指向尾巴
		cin >> x;  //再次进行输入
	}
	return head;
}

/*函数功能：有序创建链表（带头结点的链表）
* 函数形参：无
* 函数返回值：返回有序链表的头指针，Node*类型
*/
//输入 3 1 2，输出 1 2 3
Node* CreateLinkList_sort()
{
	Node* head = new Node; //创建头结点并初始化
	if (!head)
		return nullptr;
	element_type x;
	cin >> x;  //输入元素值
	while (x != -1)
	{
		//查找合适位置进行插入
		Node* p = head->next;  //工作指针
		while (p && p->data < x)  //只要结点数据小于x，则继续向后查找
			p = p->next;
		if(p)
			Insert_back(head, p, x);  //插入指定结点后
		else  //链表为空的情况
		{
			Node* node = new Node;  //申请新结点
			if (!node)
				return nullptr;
			node->data = x;  //数据域赋值
			node->next = head->next;
			head->next = node;
		}
		cin >> x;  //再次进行输入
	}
	return head;
}

/*函数功能：销毁链表
* 函数形参：链表的头指针(Node* head)
* 函数返回值：无，void类型
*/
void Destroy(Node* head)
{
	Node* p = head;  //用作循环变量
	while (p)
	{
		Node* temp = p;
		delete temp;
		p = p->next;  //指向下一个结点
	}
}

/*函数功能：插入到指定结点后
* 函数形参：链表头指针Node* head，指定结点位置Node* pos，新结点数据element_type x
* 函数返回值：插入成功返回true，否则返回false，bool类型
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

/*函数功能：插入到指定结点前（带头结点的链表）：未找到指定节点，则插入链尾；链表为空，则插入头结点后
* 函数形参：链表头指针Node* head，指定结点位置Node* pos，新结点数据element_type x
* 函数返回值：插入成功返回true，否则返回false，bool类型
*/
bool Insert_front(Node* head, Node* pos, element_type x)
{
	Node* p = new Node;  //申请新结点
	if (!p)
		return false;  //内存申请失败的处理
	p->data = x;   //数据域赋值

	if (IsEmpty(head))  //空链表，则插入到头结点后
	{
		p->next = head->next;
		head->next = p;
		return true;
	}
	//查找指定结点的前驱结点,只要结点有效且后继结点不是pos，则向后不断查找pos的前驱结点
	Node* front = head;
	while (front && front->next != pos)  //若pos结点不存在，则front指向尾结点
		front = front->next;		

	if (!front->next)//未找到pos指定结点，则插入到尾结点后
	{
		p->next = front->next;
		front->next = p;
	}
	if (pos)  //找到pos的前驱结点
	{
		p->next = pos;
		front->next = p;
	}

	return true;
}

/*函数功能：删除指定结点（带头结点链表）
* 函数形参：链表的头指针(Node* head)，待删除的结点地址（Node* pos）
* 函数返回值：删除成功返回true，否则返回false，bool类型
*/
bool Delete_pos(Node* head, Node* pos)
{
	if (!head->next || !pos)  //空链表或者位置为空的操作
		return false;
	Node* p = head; //工作指针，指向头结点
	while (p && p->next != pos)  //只要结点有效且后继结点不是pos，向后不断查找pos的前驱结点
		p = p->next;
	if (p) //找到前驱结点
	{
		p->next = pos->next;  //修改链的指向关系
		delete pos;  //释放结点
		return true;
	}
	return false;
}

/*函数功能：删除指定元素值的结点
* 函数形参：链表的头指针(Node* head)，待删除的结点值（element_type x）
* 函数返回值：返回删除结点的数量，int类型
*/
int Delete_value(Node* head, element_type x)
{
	int count = 0;
	Node* node = head;  //临时结点，用于遍历链表结点	
	while (node)  //只要链表不结束，则不断判断是否删除
	{
		Node* temp = Search_x(head, x); //临时结点，用于判断是否删除该结点
		if (temp && temp->data == x) //找到待删除的结点
			Delete_pos(head, temp), count++;  //调用函数，删除指定结点本身
		else
			node = node->next;  //重要，只有当未删除结点，指针才指向下一个结点
	}
	return count;
}

/*函数功能：查找指定元素值第一次出现的位置
* 函数形参：链表的头指针(Node* head)，待查找的元素值x
* 函数返回值：返回元素值x的地址，Node*类型
*/
Node* Search_x(Node* head, element_type x)
{
	Node* p = head;  //用作循环变量
	while (p)
	{
		if (p->data == x)
			return p;
		p = p->next;  //指向下一个结点
	}
	return nullptr;
}

/*函数功能：查找指定结点的前驱结点
* 函数形参：链表的头指针(Node* head)，指定位置Node* pos
* 函数返回值：返回前驱结点的地址，Node*类型
*/
Node* Search_front(Node* head, Node* pos)
{
	Node* p = head;
	while (p && p->next != pos)  //只要下一个结点地址不是pos，则向后继续查找
		p = p->next;
	return p;
}

/*函数功能：遍历输出单链表（带头结点）
* 函数形参：链表的头指针(Node* head)
* 函数返回值：无，void类型
*/
void DisplayLinkList(Node* head)
{
	if (head->next) //只要链表不为空
	{
		Node* p = head->next;  //用作循环变量
		while (p) //链表结点未结束
		{
			cout << p->data << " "; //输出语句根据实际数据域类型需进行调整
			p = p->next;  //指向下一个结点
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