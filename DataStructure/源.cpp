#include "queue_link.h"
#include "stack_seq.h"
#include <stack>
#include <iostream>

using namespace std;

//��ʮ����number����ת��Ϊbase����
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
		cout << s.top();  //��ȡջ��Ԫ��
		s.pop();  //��ջ
	}
}



int main()
{
	Stack s;
	//s.Push(1);
	cout << s.Top() << endl;

	return 0;
}