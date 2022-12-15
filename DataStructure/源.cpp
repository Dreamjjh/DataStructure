#include <iostream>
#include "amundirgraph.h"
using namespace std;

int main()
{
	AMUndirGraph* graph = CreateUndirGraph();
	Display(graph);
	BFS(graph, 1);



	return 0;
}