#pragma once
#ifndef __AMUNDIRGRAPH_H__
#define __AMUNDIRGRAPH_H__

#include <iostream>
#include <queue>
#include "linkqueue.h"
using namespace std;

//用两个数组分别存储顶点表和邻接矩阵
#define MAXINT 32767  //表示极大值，即∞
#define MAXVERNUM 20  //表示最大顶点数量

typedef char VertexType;  //顶点的数据类型为字符型
typedef int ArcType;  //边的权值为整型

bool visited[MAXVERNUM] = { false }; //辅助数组，用于标记顶点是否已被访问
int path[MAXVERNUM];  //记录路径

struct AMUndirGraph
{
	VertexType vertexs[MAXVERNUM];   //顶点集
	ArcType arcs[MAXVERNUM][MAXVERNUM];//邻接矩阵
    int degree[MAXVERNUM];  //记录每个顶点的度
	int vertexnum, arcnum;//图实际的顶点数量和边数
};

//函数声明部分
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

//定位顶点在图中的位置
int LocateVertex(const AMUndirGraph* graph, VertexType vertex)
{
    for (int i = 0; i < graph->vertexnum; i++)
        if (graph->vertexs[i] == vertex)
            return i;  //返回位置
    return -1;  //找不到该顶点的处理
}

//采用邻接矩阵表示法创建无向图
AMUndirGraph* CreateUndirGraph()
{
    AMUndirGraph* graph = new AMUndirGraph;
    cin >> graph->vertexnum >> graph->arcnum;//输入顶点数和边数
    for (int i = 0; i < graph->vertexnum; i++)
        cin >> graph->vertexs[i];  //输入顶点信息
     //初始化邻接矩阵，边的权值均置为极大值
    for (int i = 0; i < graph->vertexnum; i++)
        for (int j = 0; j < graph->vertexnum; j++)
            graph->arcs[i][j] = MAXINT;

    for (int i = 0; i < graph->vertexnum; i++)//初始化顶点度数
        graph->degree[i] = 0;

    for (int i = 0; i < graph->arcnum; i++)
    {
        VertexType v1, v2;  //定义两个顶点
        ArcType weight; //定义边的权值
        cin >> v1 >> v2 >> weight;
        int x = LocateVertex(graph,v1), y = LocateVertex(graph, v2);
        if (x == -1 || y == -1)
            throw "Error: Vertex position is in valid!";
        graph->arcs[x][y] = weight;//边（v1, v2）的权值置为weight
        graph->arcs[y][x] = weight;//边（v2, v1）的权值置为weight
        graph->degree[x]++;
        graph->degree[y]++;  //记录每个顶点的度数
    }
    return graph;
}

//打印输出邻接矩阵
void Display(const AMUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)
    {
        for (int j = 0; j < graph->vertexnum; j++)
        {
            if (graph->arcs[i][j] < MAXINT)
                cout << graph->arcs[i][j] << " ";
            else
                cout << "∞" << " ";
        }
        cout << endl;
    }
}



//获取位置为pos元素的顶点值
VertexType GetVertexInfo(const AMUndirGraph* graph, int pos)
{
    if (pos < 0 || pos >= graph->vertexnum)  //位置不合法
        throw "Vertex position is invalid!";
    return graph->vertexs[pos];
}

//计算顶点vi的第一个邻接点
int FirstAdjVertex(const AMUndirGraph* graph, int vi)
{
    if (vi < 0 || vi >= graph->vertexnum)  //位置不合法
        throw "Vertex position is invalid!";
    for (int i = 0; i < graph->vertexnum; i++) //查找邻接点
        if (graph->arcs[vi][i] != MAXINT)
            return i;
    return -1;  //不存在邻接点
}

//计算顶点vi相对于vj的下一个邻接点
int NextAdjVertex(const AMUndirGraph* graph, int vi, int vj)
{
    if (vi < 0 || vi >= graph->vertexnum || vj < 0 || vj >= graph->vertexnum)  //位置不合法
        throw "Vertex position is invalid!";
    if (vi == vj)
        throw "Vertex vi cannot equl vertex vj!";
    for (int i = vj + 1; i < graph->vertexnum; i++) //查找邻接点
        if (graph->arcs[vi][i] != MAXINT)
            return i;
    return -1;  //不存在邻接点
}

//DFS遍历无向图（非连通图和连通图均可）
void DFSTraverse(const AMUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //顶点全部重置为未访问状态
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            DFS(graph, i);//对未访问顶点调用DFS，若是连通图只执行一次
}

//DFS遍历无向图（连通图）
void DFS(const AMUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex] << " ";  //访问顶点
    visited[vertex] = true; //标记为已访问
    //依次检查顶点vertex的邻接点 
    for (int v = FirstAdjVertex(graph,vertex); v >= 0; v = NextAdjVertex(graph,vertex, v))
        if (!visited[v])
            DFS(graph, v);
}

//BFS遍历无向图（非连通图）
void BFSTraverse(const AMUndirGraph* graph)
{
    for (int i = 0; i < graph->vertexnum; i++)  //顶点全部重置为未访问状态
        visited[i] = false;
    for (int i = 0; i < graph->vertexnum; i++)
        if (!visited[i])
            BFS(graph, i);//对未访问顶点调用BFS，若是连通图只执行一次
}

//BFS遍历无向图（连通图）
void BFS(const AMUndirGraph* graph, int vertex)
{
    cout << graph->vertexs[vertex] << " ";  //访问顶点vertex
    visited[vertex] = true; //顶点vertex标记为已访问
    Queue queue;  //创建队列并初始化队列
    queue.Push(vertex);  //顶点vertex入队
    while (!queue.Empty())
    {
        int vi = queue.Front(); //临时顶点保存队首元素
        queue.Pop();  //出队
        //对顶点vi尚未访问过的邻接顶点进行访问
        for (int vj = FirstAdjVertex(graph,vi); vj >= 0; vj = NextAdjVertex(graph,vi,vj))
            if (!visited[vj]) //邻接点未访问
            {
                cout << graph->vertexs[vj] << " ";  //访问顶点vj
                visited[vj] = true; //标记顶点vj为已被访问
                queue.Push(vj); //邻接点vj入队
            }        
    }
}

//输出路径
void Print(const AMUndirGraph* graph)
{
    for (int i = 1; i <= graph->arcnum; i++)
        cout << path[i] << "→";
    cout << path[graph->arcnum] << endl;
}

//start为起点，step为步数
void DFSEuLer(AMUndirGraph* graph, int start, int step)
{
    path[step] = start;  //记录路径
    if (step == graph->arcnum)  //走完所有边则输出路径
        Print(graph);
    for(int i=0;i<graph->vertexnum;i++) //遍历所有顶点
        if (graph->arcs[start][i])
        {
            graph->arcs[start][i] = graph->arcs[i][start] = 0; //删除该条边，避免重复走
            DFSEuLer(graph, i, step + 1);  //以i为起点，进一步深搜
            graph->arcs[start][i] = graph->arcs[i][start] = 0; //回溯一步，修改该条边
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