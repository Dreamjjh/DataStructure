#include "queue_link.h"
#include "stack_seq.h"
#include <stack>
#include <iostream>

using namespace std;

//将十进制number进制转换为base进制
void Converse(int number, int base)
{
	stack<int> s;
	
	while (number != 0)
	{
		s.push(number % base);
		number /= base;
	}
	while (!s.empty())
	{
		cout << s.top();  //获取栈顶元素
		s.pop();  //出栈
	}
}



int main()
{
	Stack s;
	//s.Push(1);
	cout << s.Top() << endl;

	return 0;
}