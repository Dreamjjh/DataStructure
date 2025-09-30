#include "iostream"
using namespace std;

typedef int Elemtype;
//采用动态申请的顺序栈
struct SeqStack
{
    Elemtype* base;  //栈元素的数组首地址
    Elemtype* top;   //栈顶指针，指向栈顶元素的下一个位置
    int stacksize;   //栈的最大空间
};

//初始化一个空栈
int InitStack(SeqStack* stack, int size)
{
    stack->base = new Elemtype[size];  //申请栈元素空间
    if(stack->base) //申请成功
    {
        stack->top = stack->base;
        stack->stacksize = size;
        return true;
    }
    return false;
}

//判断栈空
bool IsEmpty(SeqStack* stack)
{
    return stack->top == stack->base;
}

//判断栈满
bool IsFull(SeqStack* stack)
{
    return stack->top - stack->base == stack->stacksize;
}

//入栈
bool Push(SeqStack* stack, Elemtype data)
{
    if(IsFull(stack))
        return false;
    *stack->top++ = data; 
    return true;
}

//出栈
bool Pop(SeqStack* stack)
{
    if(IsEmpty(stack))
        return false;
    stack->top--;
    return true;
}

//获取栈顶元素
Elemtype Top(SeqStack* stack)
{
    return *(stack->top - 1);
}



int main()
{
    SeqStack* stack = new SeqStack;
    InitStack(stack, 5);

    

    return 0;
}