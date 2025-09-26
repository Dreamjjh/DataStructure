#pragma once
#ifndef __AMUNDIRGRAPH_H__
#define __AMUNDIRGRAPH_H__

#include <iostream>
#include <queue>
#include "linkqueue.h"
using namespace std;

//����������ֱ�洢�������ڽӾ���
#define MAXINT 32767  //��ʾ����ֵ������
#define MAXVERNUM 20  //��ʾ��󶥵�����

typedef char VertexType;  //�������������Ϊ�ַ���
typedef int ArcType;  //�ߵ�ȨֵΪ����

bool visited[MAXVERNUM] = { false }; //�������飬���ڱ�Ƕ����Ƿ��ѱ�����
int path[MAXVERNUM];  //��¼·��

struct AMUndirGraph
{
	VertexType vertexs[MAXVERNUM];   //���㼯
	ArcType arcs[MAXVERNUM][MAXVERNUM];//�ڽӾ���
    int degree[MAXVERNUM];  //��¼ÿ������Ķ�
	int vertexnum, arcnum;//ͼʵ�ʵĶ��������ͱ���
};

//������������
int LocateVertex(const AMUndirGraph* graph, VertexType vertex);
AMUndirGraph* CreateUndirGraph();
void Display(const AMUndirGraph* graph);
VertexType GetVertexInfo(const AMUndirGraph* graph, int pos);
int FirstAdjVertex(const AMUndirGraph* graph, int vi);
int NextAdjVertex(const AMUndirGraph* graph, int vi, int vj);
void DFSTraverse(const AMUndirGraph* graph);
void DFS(const AMUndirGraph* graph, int vertex);
void BFSTraverse(const AMUndirGraph* graph);
void BFS(const AMUndirGraph* graph, int vertex);
void DFSEuLer(const AMUndirGraph* graph, int start, int step);

//��λ������ͼ�е�λ��
int LocateVertex(const AMUndirGraph* graph, VertexType vertex)
{
    for (int i = 0; i < graph->vertexnum; i++)
        if (graph->vertexs[i] == vertex)
            return i;  //����λ��
    return -1;  //�Ҳ����ö���Ĵ���
}

//�����ڽӾ����ʾ����������ͼ
AMUndirGraph* CreateUndirGraph()
{
    AMUndirGraph* graph = new AMUndirGraph;
    cin >> graph->vertexnum >> graph->arcnum;//���붥�����ͱ���
    for (int i = 0; i < graph->vertexnum; i++)
        cin >> graph->vertexs[i];  //���붥����Ϣ
     //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵ
    for (int i = 0; i < graph->vertexnum; i++)
        for (int j = 0; j < graph->vertexnum; j++)
            graph->arcs[i][j] = MAXINT;

    for (int i = 0; i < graph->vertexnum; i++)//��ʼ���������
        graph->degree[i] = 0;

    for (int i = 0; i < graph->arcnum; i++)
    {
        VertexType v1, v2;  //������������
        ArcType weight; //����ߵ�Ȩֵ
        cin >> v1 >> v2 >> weight;
        int x = LocateVertex(graph,v1), y = LocateVertex(graph, v2);
        if (x == -1 || y == -1)
            throw "Error: Vertex position is in valid!";
        graph->arcs[x][y] = weight;//�ߣ�v1, v2����Ȩֵ��Ϊweight
        graph->arcs[y][x] = weight;//�ߣ�v2, v1����Ȩֵ��Ϊweight
        graph->degree[x]++;
        graph->degree[y]++;  //��¼ÿ������Ķ���
    }
    return graph;
}

//��ӡ����ڽӾ���
void Display(const AMUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)
    {
        for (int j = 0; j < graph->vertexnum; j++)
        {
            if (graph->arcs[i][j] < MAXINT)
                cout << graph->arcs[i][j] << " ";
            else
                cout << "��" << " ";
        }
        cout << endl;
    }
}



//��ȡλ��ΪposԪ�صĶ���ֵ
VertexType GetVertexInfo(const AMUndirGraph* graph, int pos)
{
    if (pos < 0 || pos >= graph->vertexnum)  //λ�ò��Ϸ�
        throw "Vertex position is invalid!";
    return graph->vertexs[pos];
}

//���㶥��vi�ĵ�һ���ڽӵ�
int FirstAdjVertex(const AMUndirGraph* graph, int vi)
{
    if (vi < 0 || vi >= graph->vertexnum)  //λ�ò��Ϸ�
        throw "Vertex position is invalid!";
    for (int i = 0; i < graph->vertexnum; i++) //�����ڽӵ�
        if (graph->arcs[vi][i] != MAXINT)
            return i;
    return -1;  //�������ڽӵ�
}

//���㶥��vi�����vj����һ���ڽӵ�
int NextAdjVertex(const AMUndirGraph* graph, int vi, int vj)
{
    if (vi < 0 || vi >= graph->vertexnum || vj < 0 || vj >= graph->vertexnum)  //λ�ò��Ϸ�
        throw "Vertex position is invalid!";
    if (vi == vj)
        throw "Vertex vi cannot equl vertex vj!";
    for (int i = vj + 1; i < graph->vertexnum; i++) //�����ڽӵ�
        if (graph->arcs[vi][i] != MAXINT)
            return i;
    return -1;  //�������ڽӵ�
}

//DFS��������ͼ������ͨͼ����ͨͼ���ɣ�
void DFSTraverse(const AMUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //����ȫ������Ϊδ����״̬
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            DFS(graph, i);//��δ���ʶ������DFS��������ͨͼִֻ��һ��
}

//DFS��������ͼ����ͨͼ��
void DFS(const AMUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex] << " ";  //���ʶ���
    visited[vertex] = true; //���Ϊ�ѷ���
    //���μ�鶥��vertex���ڽӵ� 
    for (int v = FirstAdjVertex(graph,vertex); v >= 0; v = NextAdjVertex(graph,vertex, v))
        if (!visited[v])
            DFS(graph, v);
}

//BFS��������ͼ������ͨͼ��
void BFSTraverse(const AMUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //����ȫ������Ϊδ����״̬
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            BFS(graph, i);//��δ���ʶ������BFS��������ͨͼִֻ��һ��
}

//BFS��������ͼ����ͨͼ��
void BFS(const AMUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex] << " ";  //���ʶ���vertex
    visited[vertex] = true; //����vertex���Ϊ�ѷ���
    Queue queue;  //�������в���ʼ������
    queue.Push(vertex);  //����vertex���
    while (!queue.Empty())
    {
        int vi = queue.Front(); //��ʱ���㱣�����Ԫ��
        queue.Pop();  //����
        //�Զ���vi��δ���ʹ����ڽӶ�����з���
        for (int vj = FirstAdjVertex(graph,vi); vj >= 0; vj = NextAdjVertex(graph,vi,vj))
            if (!visited[vj]) //�ڽӵ�δ����
            {
                cout << graph->vertexs[vj] << " ";  //���ʶ���vj
                visited[vj] = true; //��Ƕ���vjΪ�ѱ�����
                queue.Push(vj); //�ڽӵ�vj���
            }        
    }
}

//���·��
void Print(const AMUndirGraph* graph)
{
    for (int i = 1; i <= graph->arcnum; i++)
        cout << path[i] << "��";
    cout << path[graph->arcnum] << endl;
}

//startΪ��㣬stepΪ����
void DFSEuLer(AMUndirGraph* graph, int start, int step)
{
    path[step] = start;  //��¼·��
    if (step == graph->arcnum)  //�������б������·��
        Print(graph);
    for(int i=0;i<graph->vertexnum;i++) //�������ж���
        if (graph->arcs[start][i])
        {
            graph->arcs[start][i] = graph->arcs[i][start] = 0; //ɾ�������ߣ������ظ���
            DFSEuLer(graph, i, step + 1);  //��iΪ��㣬��һ������
            graph->arcs[start][i] = graph->arcs[i][start] = 0; //����һ�����޸ĸ�����
        }
}

void EuLerPath()
{
    int start = 0;
    AMUndirGraph* graph = CreateUndirGraph();
    for (int i = 0; i < graph->vertexnum && !start; i++)
        if (graph->degree[i] % 2)
            start = i;
    cout << start << endl;
    DFSEuLer(graph, start, 1);
}


#endif // !__AMUNDIRGRAPH_H__