#pragma once

//typedef int element_type;
//struct HuffNode
//{
//	element_type data;  //������
//	HuffNode* leftchild, * rightchild, * next;  //���ӡ��Һ��ӡ�ָ����һ�����
//};
#define MAX 10000
struct HuffNode	//��������������
{
	int weight; //Ȩֵ
	int parent, leftchild, rightchild;  //����������Һ���
};
struct HuffTree   //�����������
{
	int n;	//��������Ҷ�ӽ�����
	int root;     //������������
	HuffNode* ht; //ָ�����������ָ��
};

//�����������
HuffTree* CreateHuffTree(int* w, int n)
{
	int i, j, x1, x2, min1, min2;
	HuffTree* pht = new HuffTree;
	if (!pht)
		return pht;

	//Ϊ������������2*N-1���ռ�
	pht->ht = new HuffNode[2 * n - 1];
	if (!pht->ht)
		return pht;
	//��ʼ����������
	for (i = 0; i < 2 * n - 1; i++)
	{
		pht->ht[i].leftchild = -1;	//��ʼ��Ҷ�������
		pht->ht[i].rightchild = -1;	//��ʼ��Ҷ����Һ���
		pht->ht[i].parent = -1;	    //��ʼ��Ҷ���ĸ���
		if (i < n)
			pht->ht[i].weight = w[i];
		else
			pht->ht[i].weight = -1;
	}

	for (i = 0; i < n - 1; i++)
	{
		min1 = MAX;	//min1������Сֵ
		min2 = MAX;	//min2�����Сֵ
		x1 = x2 = -1;//��Сֵ�±�ʹ�Сֵ�±�
		//�ҵ���Сֵ�±�x1������СȨֵ��ֵ��min1
		for (j = 0; j < n + i; j++)
		{
			if (pht->ht[j].weight < min1 && pht->ht[j].parent == -1)
			{
				min2 = min1;
				x2 = x1;
				min1 = pht->ht[j].weight;
				x1 = j;
			}
			//�ҵ���Сֵ�±�x2���Ѵ�Сֵ��ֵ��min2
			else if (pht->ht[j].weight < min2 && pht->ht[j].parent == -1)
			{
				min2 = pht->ht[j].weight;
				x2 = j;
			}
		}			
		//����x1��x2�ĸ����
		pht->ht[n + i].weight = min1 + min2;//������ȨֵΪ��Сֵ�Ӵ�Сֵ
		pht->ht[n + i].leftchild = x1;	//����������Ϊx1
		pht->ht[n + i].rightchild = x2;	//�������Һ��ӵ�x2
		pht->ht[x1].parent = n + i;	//x1������±�
		pht->ht[x2].parent = n + i;	//x2������±�
	}
	pht->root = 2 * n - 2;//�������������λ��
	pht->n = n;
	return pht;
}
