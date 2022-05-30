#include <iostream>
using namespace std;

#define MAXINT 32767        //��ʾ����ֵ������
#define MAXVERNUM 20           //��󶥵���
typedef char VerTexType;    //���趥�����������Ϊ�ַ��� 
typedef int ArcType;        //����ߵ�Ȩֵ����Ϊ����

int* D = new int[MAXVERNUM];    //���ڼ�¼���·�ĳ���
bool* S = new bool[MAXVERNUM];  //��Ƕ����Ƿ����S����
int* Path = new int[MAXVERNUM]; //���ڼ�¼���·�����ǰ��

//------------ͼ���ڽӾ���-----------------
struct AMGraph
{
	VerTexType vexs[MAXVERNUM];      //����� 
	ArcType arcs[MAXVERNUM][MAXVERNUM];  //�ڽӾ��� 
	int vexnum, arcnum;          //ͼ�ĵ�ǰ�����ͱ��� 
};

//ȷ����v��G�е�λ��
int LocateVex(AMGraph G, VerTexType v)
{	
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}

//�����ڽӾ����ʾ��������������G
void CreateUDN(AMGraph& G) 
{	 
	cin >> G.vexnum >> G.arcnum;       //�����ܶ��������ܱ���
	for (int i = 0; i < G.vexnum; i++) 		
		cin >> G.vexs[i];              //������������Ϣ 

	for (int i = 0; i < G.vexnum; i++)     //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMAXINT 
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MAXINT;

	for (int k = 0; k < G.arcnum; k++)  //�����ڽӾ���
	{       
		VerTexType v1, v2;
		ArcType w;
		cin >> v1 >> v2 >> w;        //����һ���������Ķ��㼰Ȩֵ
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);  //ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = w;          //��<v1, v2>��Ȩֵ��Ϊw 
		//G.arcs[j][i] = G.arcs[i][j];  //��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}
}

//��Dijkstra�㷨��������G��v0���㵽���ඥ������·��
void ShortestPath_DIJ(AMGraph G, int v0)
{	 
	int v;
	int n = G.vexnum;   //nΪG�ж���ĸ��� 

	for (v = 0; v < n; ++v) //n���������γ�ʼ��
	{                   
		S[v] = false;       //S��ʼΪ�ռ� 
		D[v] = G.arcs[v0][v];  //��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ 
		if (D[v] < MAXINT)//���v0��v֮���л�����v��ǰ����Ϊv0
			Path[v] = v0;    
		else 
			Path[v] = -1;   //���v0��v֮���޻�����v��ǰ����Ϊ-1 
	}
	S[v0] = true;  //��v0����S 
	D[v0] = 0;    //Դ�㵽Դ��ľ���Ϊ0 
	/*��ʼ����������ʼ��ѭ����ÿ�����v0��ĳ������v�����·������v�ӵ�S��*/
	for (int i = 1; i < n; i++) //������n-1�����㣬���ν��м���
	{          
		int min = MAXINT;
		for (int w = 0; w < n; ++w)
			if (!S[w] && D[w] < min) //ѡ��һ����ǰ�����·�����յ�Ϊv
			{       
				v = w;
				min = D[w];
			}
		S[v] = true;     //��v����S 
		for (int w = 0; w < n; ++w)   //���´�v0����������V-S�����ж�������·������ 
			if (!S[w] && (D[v] + G.arcs[v][w] < D[w])) 
			{
				D[w] = D[v] + G.arcs[v][w];  //����D[w] 
				Path[w] = v;     //����w��ǰ��Ϊv 
			}
	}
}

//��ʾ���·
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
					cout << "��" << "\t";
			}
			else 
			{
				if (G.arcs[i][j] != MAXINT)
					cout << G.arcs[i][j] << endl;
				else
					cout << "��" << endl;
			}
		}
	}
	cin >> start >> destination;
	num_start = LocateVex(G, start);
	num_destination = LocateVex(G, destination);
	ShortestPath_DIJ(G, num_start);
	cout << endl << "���·��Ϊ��";
	DisplayPath(G, num_start, num_destination);
	cout << G.vexs[num_destination] << endl;
	//cout << D[destination] << endl;
	return 0;
}

