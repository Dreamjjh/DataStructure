#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;    
};

//初始化一个带头结点的空链表
//返回初始化之后的头指针
Node* InitLinkList()
{
    Node* head = new Node; //申请头结点
    if(head)
    {
        head->next = nullptr;
        return head;
    }
    return nullptr;
}

int main()
{
    //至少都需要头指针
    
}