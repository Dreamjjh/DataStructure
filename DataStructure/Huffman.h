#pragma once

//typedef int element_type;
//struct HuffNode
//{
//	element_type data;  //数据域
//	HuffNode* leftchild, * rightchild, * next;  //左孩子、右孩子、指向下一个结点
//};
#define MAX 10000
struct HuffNode	//定义哈夫曼树结点
{
	int weight; //权值
	int parent, leftchild, rightchild;  //父结点与左、右孩子
};
struct HuffTree   //定义哈夫曼树
{
	int n;	//哈夫曼树叶子结点个数
	int root;     //哈夫曼树树根
	HuffNode* ht; //指向哈夫曼树的指针
};

//构造哈夫曼树
HuffTree* CreateHuffTree(int* w, int n)
{
	int i, j, x1, x2, min1, min2;
	HuffTree* pht = new HuffTree;
	if (!pht)
		return pht;

	//为哈夫曼树申请2*N-1个空间
	pht->ht = new HuffNode[2 * n - 1];
	if (!pht->ht)
		return pht;
	//初始化哈夫曼树
	for (i = 0; i < 2 * n - 1; i++)
	{
		pht->ht[i].leftchild = -1;	//初始化叶结点左孩子
		pht->ht[i].rightchild = -1;	//初始化叶结点右孩子
		pht->ht[i].parent = -1;	    //初始化叶结点的父亲
		if (i < n)
			pht->ht[i].weight = w[i];
		else
			pht->ht[i].weight = -1;
	}

	for (i = 0; i < n - 1; i++)
	{
		min1 = MAX;	//min1代表最小值
		min2 = MAX;	//min2代表次小值
		x1 = x2 = -1;//最小值下标和次小值下标
		//找到最小值下标x1并把最小权值赋值给min1
		for (j = 0; j < n + i; j++)
		{
			if (pht->ht[j].weight < min1 && pht->ht[j].parent == -1)
			{
				min2 = min1;
				x2 = x1;
				min1 = pht->ht[j].weight;
				x1 = j;
			}
			//找到次小值下标x2并把次小值赋值给min2
			else if (pht->ht[j].weight < min2 && pht->ht[j].parent == -1)
			{
				min2 = pht->ht[j].weight;
				x2 = j;
			}
		}			
		//构建x1，x2的父结点
		pht->ht[n + i].weight = min1 + min2;//父结点的权值为最小值加次小值
		pht->ht[n + i].leftchild = x1;	//父结点的左孩子为x1
		pht->ht[n + i].rightchild = x2;	//父结点的右孩子的x2
		pht->ht[x1].parent = n + i;	//x1父结点下标
		pht->ht[x2].parent = n + i;	//x2父结点下标
	}
	pht->root = 2 * n - 2;//哈夫曼树根结点位置
	pht->n = n;
	return pht;
}
