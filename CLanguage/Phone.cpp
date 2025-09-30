/*作者：
 *时间：
 *项目描述：该项目是一个通讯录管理系统，具有通讯录建立、查找、删除、增加等功能。
*/
#include <iostream>
using namespace std;

//通讯录包括：姓名、电话、公司、地址等
struct Tel
{
    char name[50]; //存储姓名
    char phonenum[12];  //存储电话
    char company[100];  //存储公司
    char address[200];  //存储地址
};

//采用链表实现
struct Node
{
    Tel data;  //数据域
    Node* next; //指针域
};

/*函数功能：初始化一个空的通讯录（带头结点的单链表）
 *函数形参：无
 *函数返回值：返回通讯录的头指针，Node*类型
*/
Node* InitTel()
{
    Node* head = new Node;  //申请头结点
    if(head) //判断是否申请成功
    {
        head->next = nullptr;
        return head;
    }
    return nullptr;
}

/*函数功能：选择菜单
 *函数形参：无
 *函数返回值：返回用户的选择，int类型
*/
int SelectMenu()
{
    cout << "*****通讯录管理系统*****" << endl;
    cout << "1. 通讯录链表的建立" << endl;
    cout << "2. 通讯录插入" << endl;
    cout << "3. 通讯录删除" << endl;
    cout << "4. 通讯录查找" << endl;
    cout << "5. 通讯录输出" << endl;
    cout << "0. 退出通讯录" << endl;
    
    int choice;  //定义变量，保存用户的选择
    do
    {        
        cin >> choice;    
    }while (choice < 0 || choice > 5); 
    return choice;
}

/*函数功能：单链表通讯录的建立（尾插法）
 *函数形参：单链表的头指针Node* head
 *函数返回值：返回是否建立功能，bool类型
*/
bool CreateList_tail(Node* head)
{
    Node* node = new Node;   //申请一个结点
    if(!node)
        return false;  //申请失败的处理
    //数据域赋值
    cin >> node->data.name;  //输入姓名
    cin >> node->data.phonenum;  //输入电话
    cin >> node->data.company;  //输入公司
    cin >> node->data.address;  //输入地址
    //指针域赋值
    node->next = nullptr;

    static Node* tail = head;  //尾指针
    tail->next = node;
    tail = node;
    return true;
}
/*函数功能：输出通讯录的内容
 *函数形参：单链表的头指针Node* head
 *函数返回值：无，void类型
*/
void Output(Node* head)
{
    for(Node* p = head->next; p; p = p->next)
        cout << p->data.name << " " << p->data.phonenum << endl;
}


int main()
{
    //cout << SelectMenu();
    Node* head = InitTel();  //初始化
    CreateList_tail(head);
    CreateList_tail(head);
    Output(head);  //张三 1111111 CQRK chongqing

    return 0;
}











