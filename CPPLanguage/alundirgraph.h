#pragma once
#ifndef __ALUNDIRGRAPH_H__
#define __ALUNDIRGRAPH_H__

#include "linkqueue.h"
#include <iostream>
using namespace std;

#define MAXVERNUM 20  //��󶥵���
typedef char VertexType;
typedef int ArcType;
bool visited[MAXVERNUM];  //������飬���ڱ�Ƕ����Ƿ��ѱ�����
struct ArcNode   //�߽��
{
    int adjvex;  //�ñ���ָ��Ķ����λ��
    ArcType info;  //�ͱ���ص���Ϣ����Ȩֵ
    ArcNode* nextarc; //ָ����һ���ߵ�ָ�� 

};
struct VertexNode //��ͷ���
{
    VertexType data;   //������Ϣ 
    ArcNode* firstarc;//ָ���һ�������ö���ıߵ�ָ�� 
};
struct ALUndirGraph
{
    VertexNode vertexs[MAXVERNUM];  //�ڽӱ� 
    int vertexnum, arcnum;	//ͼ�ĵ�ǰ�������ͱ��� 
};

//������������
int LocateVertex(const ALUndirGraph* graph, VertexType vertex);
ALUndirGraph* CreateUndirGraph();
void DFSTraverse(const ALUndirGraph* graph);
void DFS(const ALUndirGraph* graph, int vertex);
void BFSTraverse(const ALUndirGraph* graph);
void BFS(const ALUndirGraph* graph, int vertex);

//��λ������ͼ�е�λ��
int LocateVertex(const ALUndirGraph* graph, VertexType vertex)
{
    for (int i = 0; i < graph->vertexnum; i++)
        if (graph->vertexs[i].data == vertex)
            return i;  //����λ��
    return -1;  //�Ҳ����ö���Ĵ���
}
//�����ڽӱ��ʾ����������ͼ
ALUndirGraph* CreateUndirGraph()
{
    ALUndirGraph* graph = new ALUndirGraph;
    cin >> graph->vertexnum >> graph->arcnum; //���붥�����ͱ���
    for (int i = 0; i < graph->vertexnum; i++)
    {
        cin >> graph->vertexs[i].data;  //���붥��ֵ
        graph->vertexs[i].firstarc = nullptr;  //��ʼ����ͷ���
    }
    for (int i = 0; i < graph->arcnum; i++)
    {
        VertexType v1, v2;
        ArcType weight;
        cin >> v1 >> v2 >> weight;  //���붥��ͱ�Ȩ
        int x = LocateVertex(graph, v1); //����v1��λ��
        int y = LocateVertex(graph, v2); //����v2��λ��
        //����һ���µı߽��
        ArcNode* arcnode = new ArcNode;
        arcnode->adjvex = y;
        arcnode->info = weight;
        arcnode->nextarc = graph->vertexs[x].firstarc;
        graph->vertexs[x].firstarc = arcnode;
    }
    return graph;
}

//����DFS��������ͼ������ͨͼ����ͨͼ���ɣ�
void DFSTraverse(const ALUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //����ȫ������Ϊδ����״̬
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            DFS(graph, i);//��δ���ʶ������DFS��������ͨͼִֻ��һ��
}

//����DFS��������ͼ����ͨͼ��
void DFS(const ALUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex].data << " ";//���ʶ���vertex����Ϣ
    visited[vertex] = true; //���Ϊ�ѷ���
    ArcNode* arcnode = graph->vertexs[vertex].firstarc;
    while (arcnode) //�߽��ǿ� 
    {   
        if (!visited[arcnode->adjvex])//������ڽ��δ���ʣ���ݹ����DFS
            DFS(graph, arcnode->adjvex);
        arcnode = arcnode->nextarc;//ָ����һ���߽�� 
    }
}

//����BFS��������ͼ������ͨͼ����ͨͼ���ɣ�
void BFSTraverse(const ALUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //����ȫ������Ϊδ����״̬
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            BFS(graph, i);//��δ���ʶ������DFS��������ͨͼִֻ��һ��
}

//����BFS��������ͼ����ͨͼ��
void BFS(const ALUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex].data << " ";//���ʶ���vertex����Ϣ
    visited[vertex] = true; //���Ϊ�ѷ���
    Queue queue;  //����һ���ն���
    queue.Push(vertex);  //����vertex���
    while (!queue.Empty())
    {
        int vi = queue.Front(); //��ȡ����Ԫ��
        queue.Pop();  //����Ԫ�س���
        for (ArcNode* vj = graph->vertexs[vi].firstarc; vj; vj = vj->nextarc)
            if (!visited[vj->adjvex])
            {
                cout << graph->vertexs[vj->adjvex].data << " ";//�����ڽӵ����Ϣ
                visited[vj->adjvex] = true; //���Ϊ�ѷ���
                queue.Push(vj->adjvex);
            }        
    } 
}


#endif // !__ALUNDIRGRAPH_H__