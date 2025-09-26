#include<stdio.h>

/*计算最小值和次小值并输出*/
void DoubleMinNumber(int number[], int n)
{
	int firstmin = number[0], secondmin = number[1];
	for (int i = 0; i < n; i++)  //计算最小值,存储在number[0]中
		if (number[i] < firstmin)
		{
			int temp = number[i];
			number[i] = firstmin;
			firstmin = temp;
		}		
	for (int i = 1; i < n; i++)  //计算最小值,存储在number[1]中
		if (number[i] < secondmin)
		{
			int temp = number[i];
			number[i] = secondmin;
			secondmin = temp;
		}
	printf("%d, %d\n", number[0], number[1]);
}

int main()
{
	int number[] = { 10,1,3,4,5 };
	DoubleMinNumber(number, 5);

	return 0;
}