#include "stack_seq.h "
#include <iostream>
using namespace std;

int main()
{
	element_type x;
	Stack s;
	s.Push(100);
	s.Push(200);
	s.Pop(x);
	cout << x << endl;
	return 0;
}