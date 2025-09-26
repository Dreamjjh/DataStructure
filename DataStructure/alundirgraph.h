#pragma once
#ifndef __ALUNDIRGRAPH_H__
#define __ALUNDIRGRAPH_H__

#include "linkqueue.h"
#include <iostream>
using namespace std;

#define MAXVERNUM 20  //最大顶点数
typedef char VertexType;
typedef int ArcType;
bool visited[MAXVERNUM];  //标记数组，用于标记顶点是否已被访问
struct ArcNode   //边结点
{
    int adjvex;  //该边所指向的顶点的位置
    ArcType info;  //和边相关的信息，如权值
    ArcNode* nextarc; //指向下一条边的指针 

};
struct VertexNode //表头结点
{
    VertexType data;   //顶点信息 
    ArcNode* firstarc;//指向第一条依附该顶点的边的指针 
};
struct ALUndirGraph
{
    VertexNode vertexs[MAXVERNUM];  //邻接表 
    int vertexnum, arcnum;	//图的当前顶点数和边数 
};

//函数声明部分
int LocateVertex(const ALUndirGraph* graph, VertexType vertex);
ALUndirGraph* CreateUndirGraph();
void DFSTraverse(const ALUndirGraph* graph);
void DFS(const ALUndirGraph* graph, int vertex);
void BFSTraverse(const ALUndirGraph* graph);
void BFS(const ALUndirGraph* graph, int vertex);

//定位顶点在图中的位置
int LocateVertex(const ALUndirGraph* graph, VertexType vertex)
{
    for (int i = 0; i < graph->vertexnum; i++)
        if (graph->vertexs[i].data == vertex)
            return i;  //返回位置
    return -1;  //找不到该顶点的处理
}
//采用邻接表表示法创建无向图
ALUndirGraph* CreateUndirGraph()
{
    ALUndirGraph* graph = new ALUndirGraph;
    cin >> graph->vertexnum >> graph->arcnum; //输入顶点数和边数
    for (int i = 0; i < graph->vertexnum; i++)
    {
        cin >> graph->vertexs[i].data;  //输入顶点值
        graph->vertexs[i].firstarc = nullptr;  //初始化表头结点
    }
    for (int i = 0; i < graph->arcnum; i++)
    {
        VertexType v1, v2;
        ArcType weight;
        cin >> v1 >> v2 >> weight;  //输入顶点和边权
        int x = LocateVertex(graph, v1); //查找v1的位置
        int y = LocateVertex(graph, v2); //查找v2的位置
        //生成一个新的边结点
        ArcNode* arcnode = new ArcNode;
        arcnode->adjvex = y;
        arcnode->info = weight;
        arcnode->nextarc = graph->vertexs[x].firstarc;
        graph->vertexs[x].firstarc = arcnode;
    }
    return graph;
}

//采用DFS遍历无向图（非连通图和连通图均可）
void DFSTraverse(const ALUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //顶点全部重置为未访问状态
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            DFS(graph, i);//对未访问顶点调用DFS，若是连通图只执行一次
}

//采用DFS遍历无向图（连通图）
void DFS(const ALUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex].data << " ";//访问顶点vertex的信息
    visited[vertex] = true; //标记为已访问
    ArcNode* arcnode = graph->vertexs[vertex].firstarc;
    while (arcnode) //边结点非空 
    {   
        if (!visited[arcnode->adjvex])//如果相邻结点未访问，则递归调用DFS
            DFS(graph, arcnode->adjvex);
        arcnode = arcnode->nextarc;//指向下一个边结点 
    }
}

//采用BFS遍历无向图（非连通图和连通图均可）
void BFSTraverse(const ALUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //顶点全部重置为未访问状态
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            BFS(graph, i);//对未访问顶点调用DFS，若是连通图只执行一次
}

//采用BFS遍历无向图（连通图）
void BFS(const ALUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex].data << " ";//访问顶点vertex的信息
    visited[vertex] = true; //标记为已访问
    Queue queue;  //创建一个空队列
    queue.Push(vertex);  //顶点vertex入队
    while (!queue.Empty())
    {
        int vi = queue.Front(); //获取队首元素
        queue.Pop();  //队首元素出队
        for (ArcNode* vj = graph->vertexs[vi].firstarc; vj; vj = vj->nextarc)
            if (!visited[vj->adjvex])
            {
                cout << graph->vertexs[vj->adjvex].data << " ";//访问邻接点的信息
                visited[vj->adjvex] = true; //标记为已访问
                queue.Push(vj->adjvex);
            }        
    } 
}


#endif // !__ALUNDIRGRAPH_H__