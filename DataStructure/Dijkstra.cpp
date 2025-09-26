#include <iostream>
using namespace std;

#define MAXINT 32767        //表示极大值，即∞
#define MAXVERNUM 20           //最大顶点数
typedef char VerTexType;    //假设顶点的数据类型为字符型 
typedef int ArcType;        //假设边的权值类型为整型

int* D = new int[MAXVERNUM];    //用于记录最短路的长度
bool* S = new bool[MAXVERNUM];  //标记顶点是否进入S集合
int* Path = new int[MAXVERNUM]; //用于记录最短路顶点的前驱

//------------图的邻接矩阵-----------------
struct AMGraph
{
	VerTexType vexs[MAXVERNUM];      //顶点表 
	ArcType arcs[MAXVERNUM][MAXVERNUM];  //邻接矩阵 
	int vexnum, arcnum;          //图的当前点数和边数 
};

//确定点v在G中的位置
int LocateVex(AMGraph G, VerTexType v)
{	
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}

//采用邻接矩阵表示法，创建无向网G
void CreateUDN(AMGraph& G) 
{	 
	cin >> G.vexnum >> G.arcnum;       //输入总顶点数，总边数
	for (int i = 0; i < G.vexnum; i++) 		
		cin >> G.vexs[i];              //依次输入点的信息 

	for (int i = 0; i < G.vexnum; i++)     //初始化邻接矩阵，边的权值均置为极大值MAXINT 
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MAXINT;

	for (int k = 0; k < G.arcnum; k++)  //构造邻接矩阵
	{       
		VerTexType v1, v2;
		ArcType w;
		cin >> v1 >> v2 >> w;        //输入一条边依附的顶点及权值
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);  //确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[i][j] = w;          //边<v1, v2>的权值置为w 
		//G.arcs[j][i] = G.arcs[i][j];  //置<v1, v2>的对称边<v2, v1>的权值为w 
	}
}

//用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径
void ShortestPath_DIJ(AMGraph G, int v0)
{	 
	int v;
	int n = G.vexnum;   //n为G中顶点的个数 

	for (v = 0; v < n; ++v) //n个顶点依次初始化
	{                   
		S[v] = false;       //S初始为空集 
		D[v] = G.arcs[v0][v];  //将v0到各个终点的最短路径长度初始化为弧上的权值 
		if (D[v] < MAXINT)//如果v0和v之间有弧，则将v的前驱置为v0
			Path[v] = v0;    
		else 
			Path[v] = -1;   //如果v0和v之间无弧，则将v的前驱置为-1 
	}
	S[v0] = true;  //将v0加入S 
	D[v0] = 0;    //源点到源点的距离为0 
	/*初始化结束，开始主循环，每次求得v0到某个顶点v的最短路径，将v加到S集*/
	for (int i = 1; i < n; i++) //对其余n-1个顶点，依次进行计算
	{          
		int min = MAXINT;
		for (int w = 0; w < n; ++w)
			if (!S[w] && D[w] < min) //选择一条当前的最短路径，终点为v
			{       
				v = w;
				min = D[w];
			}
		S[v] = true;     //将v加入S 
		for (int w = 0; w < n; ++w)   //更新从v0出发到集合V-S上所有顶点的最短路径长度 
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) 
			{
				D[w] = D[v] + G.arcs[v][w];  //更新D[w] 
				Path[w] = v;     //更改w的前驱为v 
			}
	}
}

//显示最短路
void DisplayPath(AMGraph G, int begin, int temp) 
{	
	if (Path[temp] != -1) 
	{
		DisplayPath(G, begin, Path[temp]);
		cout << G.vexs[Path[temp]] << "-->";
	}
}

int main()
{
	AMGraph G;
	CreateUDN(G);
	int num_start, num_destination;
	VerTexType start, destination;	

	for (int i = 0; i < G.vexnum; ++i) 
	{
		for (int j = 0; j < G.vexnum; ++j) 
		{
			if (j != G.vexnum - 1) 
			{
				if (G.arcs[i][j] != MAXINT)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "∞" << "\t";
			}
			else 
			{
				if (G.arcs[i][j] != MAXINT)
					cout << G.arcs[i][j] << endl;
				else
					cout << "∞" << endl;
			}
		}
	}
	cin >> start >> destination;
	num_start = LocateVex(G, start);
	num_destination = LocateVex(G, destination);
	ShortestPath_DIJ(G, num_start);
	cout << endl << "最短路径为：";
	DisplayPath(G, num_start, num_destination);
	cout << G.vexs[num_destination] << endl;
	//cout << D[destination] << endl;
	return 0;
}

