#include <cstdlib>
#include <iostream>
using namespace std;

#define INIT_SIZE 5
typedef int ElemType;
struct List
{
    int length; //元素实际长度
    int listsize;
    ElemType * elem;  //存储空间的首地址
};

//顺序表的初始化
int InitList(List* list)
{
    list->elem = new ElemType[INIT_SIZE];
    if(list->elem)
    {
        list->listsize = INIT_SIZE;
        list->length = 0;
        return 1;
    }
    return 0;
}


int main()
{
    
}
