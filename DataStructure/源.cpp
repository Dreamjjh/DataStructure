#include <iostream>
#include "Huffman.h"
using namespace std;



int main()
{
	int weight[] = { 2,3,5 };
	HuffTree* root = CreateHuffTree(weight, 3);
	for (size_t i = 0; i < 2 * (root->n) - 1; i++)
	{
		cout << i << " ";
		cout << ((root->ht) + i)->weight << " ";
		cout << ((root->ht) + i)->parent << " ";
		cout << ((root->ht) + i)->leftchild << " ";
		cout << ((root->ht) + i)->rightchild << endl;
	}

	return 0;
}