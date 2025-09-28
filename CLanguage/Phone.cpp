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








int main()
{

    return 0;
}





