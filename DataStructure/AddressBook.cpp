// 这是一个简单的通讯录程序
#include <iostream>
using namespace std;

//定义联系人结构体
struct Contact
{
	char name[100];  //姓名
	char phonenumber[12];  //电话
	struct Birthday//生日
	{
		int year;
		int month;
		int day;
	} birthday;
	char sex; //性别
	int age; //年龄
};

//定义链表的结构体
struct Node
{
	Contact data;  //数据域
	Node * next;  //指针域
};

/*函数功能：初始化一个空的通讯录
* 函数形参：无
* 函数返回值：返回一个空的通讯录链表头指针,Node*类型
*/
Node* InitAddressBook()
{
	Node* head = new Node;  //申请一个头结点
	if(head == NULL)
		cout << "内存分配失败！" << endl;
	else
		head->next = NULL;  //将头结点的指针域置为空
	return head;
}
/*函数功能：输入联系人的信息
* 函数形参：无
* 函数返回值：返回联系人信息,Contact类型
*/
Contact InputContact()
{
	Contact contact;  //定义一个联系人结构体变量
	cin >> contact.name;  //输入姓名
	cin >> contact.phonenumber;  //输入电话
	cin >> contact.birthday.year >> contact.birthday.month >> contact.birthday.day;  //输入生日
	cin >> contact.sex;  //输入性别
	//根据当前日期计算年龄
	contact.age = 2026 - contact.birthday.year;  //简单计算

	return contact;
}


/*函数功能：建立通讯录（头插法）
* 函数形参：通讯录的头指针Node* head,联系人信息Contact data
* 函数返回值：插入成功返回1，否则返回0, int类型
*/
int CreateAddressBookHead(Node* head, Contact data)
{
	Node* node = new Node;  //申请一个新结点
	if (node == NULL)
	{
		cout << "内存分配失败！" << endl;
		return 0;
	}
	node->data = data;  //将联系人信息赋值给新结点的数据域
	node->next = head->next;  //将新结点的指针域指向原来的第一个结点
	head->next = node;  //将头结点的指针域指向新结点

	return 1;
}

/*函数功能：建立通讯录（尾插法）
* 函数形参：通讯录的头指针Node* head,联系人信息Contact data
* 函数返回值：插入成功返回1，否则返回0, int类型
*/
int CreateAddressBookTail(Node* head, Contact data)
{
	static Node* tail = head;  //定义一个静态尾指针，初始指向头结点
	Node* node = new Node;  //申请一个新结点
	if (node == NULL)
	{
		cout << "内存分配失败！" << endl;
		return 0;
	}
	node->data = data;  //将联系人信息赋值给新结点的数据域
	node->next = NULL;  //将新结点的指针域置为空
	tail->next = node;  //将尾结点的指针域指向新结点
	tail = node;  //将尾指针指向新结点

	return 1;
}

/*函数功能：输出单个联系人的信息
* 函数形参：联系人信息Contact data
* 函数返回值：无, void类型
*/
void OutputContact(Contact data)
{
	cout << "姓名：" << data.name << endl;
	cout << "电话：" << data.phonenumber << endl;
	cout << "生日：" << data.birthday.year << "年" << data.birthday.month << "月" << data.birthday.day << "日" << endl;
	cout << "性别：" << data.sex << endl;
	cout << "年龄：" << data.age << endl;
}
/*函数功能：输出整个通讯录联系人的信息
* 函数形参：通讯录的头指针Node* head
* 函数返回值：无, void类型
*/
void OutputAddressBook(Node* head)
{
	Node* p = head->next;  //定义一个指针p，指向第一个结点
	int count = 0;  //定义一个计数器，统计联系人数量
	while (p != NULL)  //遍历整个链表
	{
		OutputContact(p->data);  //输出当前结点的联系人信息
		p = p->next;  //指针p指向下一个结点
		count++;  //计数器加1
	}		
	cout << "联系人数量：" << count << endl;
}

/*函数功能：查找联系人的信息
* 函数形参：通讯录的头指针Node* head
* 函数返回值：查找成功，返回联系人地址，否则返回空, Node*类型
*/
Node* SearchContact(Node* head)
{
	int choice;  //定义一个整型变量，用于存储用户的选择
	cout << "请输入查找方式（1表示按姓名查找，2表示按电话查找）：";
	cin >> choice;  //输入用户的选择,1表示按姓名查找，2表示按电话查找
	if (choice == 1)
	{
		char name[100];  //定义一个字符数组，用于存储要查找的姓名
		cin >> name;  //输入要查找的姓名
		for (Node* node = head->next; node;node=node->next)
			if(strcmp(node->data.name,name) == 0)
				return node;  //查找成功，返回联系人地址
	}
	else if (choice == 2)
	{
		char phonenumber[12];  //定义一个字符数组，用于存储要查找的电话
		cin >> phonenumber;  //输入要查找的电话
		for (Node* node = head->next; node; node = node->next)
			if (strcmp(node->data.phonenumber, phonenumber) == 0)
				return node;  //查找成功，返回联系人地址
	}
	else
		cout << "输入错误！" << endl;
	return NULL;  //返回空
}

/*函数功能：打印用户选择菜单
* 函数形参：无
* 函数返回值：返回用户选择, int类型
*/
int PrintMenu()
{
	cout << "------------------通讯录管理系统-----------------" << endl;
	cout << "1.添加联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.查找联系人" << endl;
	cout << "4.修改联系人" << endl;
	cout << "5.输出通讯录" << endl;
	cout << "6.退出程序" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "请输入您的选择（1-6）：";
	int choice;
	cin >> choice;  //输入用户的选择
	return choice;
}


int main() 
{
	Node* head = InitAddressBook();  //初始化通讯录

	for (int i = 0; i < 2; i++)
	{
		Contact contact = InputContact();  //输入联系人信息
		CreateAddressBookHead(head, contact);
	}
	OutputAddressBook(head);  //输出整个通讯录
	
	//cout << head->next->data.age << endl;


	return 0;
}