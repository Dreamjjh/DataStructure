#include <cstdlib>
#include <iostream>
using namespace std;

typedef int ElemType;
struct List
{
    int length;   //元素实际长度
    int maxsize;  //顺序表的最大容量
    ElemType * element;  //存储空间的首地址
};

/*函数功能：顺序表的初始化
 *函数形参：顺序表的最大元素容量，int maxsize
 *函数返回值：初始化成功返回实际地址，否则返回空，List*类型
*/
List* InitList(int maxsize)
{
    List* list = new List;  //申请一个顺序表
    if(list)  //顺序表申请成功
    {
        list->element = new ElemType[maxsize];
        if(list->element)
        {
            list->length = 0;
            list->maxsize = maxsize;
            return list;
        }
        else
        {
            cout << "Initialize the 'element' member failed."<<endl;
            delete list;
            return nullptr;        
        }
    }
    return nullptr;
}


int main()
{
    
}
