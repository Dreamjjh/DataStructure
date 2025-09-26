#pragma once
#ifndef __BINARYSORTTREE_H__
#define __BINARYSORTTREE_H__

#include <iostream>
typedef int DataType;
struct BinTreeNode  //�������������
{
	DataType data;  //���������
	BinTreeNode* leftchild, * rightchild;  //���Һ���ָ��
	BinTreeNode()  //���캯������ɳ�Ա��ʼ��
	{
		data = 0;
		leftchild = rightchild = nullptr;
	}
};

class BinarySortTree  //������������
{
public:
	BinarySortTree();  //���캯����ɶ������������ݳ�Ա�ĳ�ʼ��
	~BinarySortTree(); //������������ն��������е����н��

	void CreateBST();  //����������ֵ����������������
	void CreateBST(DataType* value, int n); //ͨ������ֱ�Ӵ�������������
	BinTreeNode* SearchBST(DataType data);  //����data�Ƿ�����ڶ����������У��ǵݹ飩
	BinTreeNode* SearchBST(BinTreeNode* root, DataType data);  //����data�Ƿ�����ڶ����������У��ݹ飩
	void InsertBST(BinTreeNode*& root, DataType data); //�������ݵ�������������
	void DeleteBST(DataType data); //ɾ�������������е�ָ�����
	void DestroyBST(BinTreeNode* root);  //���ٶ���������
	void InorderBST(const BinTreeNode* root);  //�����������������
	BinTreeNode* GetRoot();  //��ȡ�����������ĸ����

private:
	BinTreeNode* root;  //�����������ĸ����
	int node_number;    //�����������������
};

//���캯����ɶ������������ݳ�Ա�ĳ�ʼ��
BinarySortTree::BinarySortTree()
{
	root = nullptr;
	node_number = 0;
}

//������������ն��������е����н��
BinarySortTree::~BinarySortTree()
{
	DestroyBST(root);  //���ó�Ա���������ɾ��
}

/*�������ܣ�����������ֵ����������������
* �����βΣ���
* ��������ֵ���ޣ�void����
*/
void BinarySortTree::CreateBST()
{
	DataType data;
	std::cin >> data;
	while (data != -1)  //ֻҪ������ֵ���ǽ�����ǣ����������
	{
		InsertBST(root, data);
		std::cin >> data;
	}
}

/*�������ܣ�ͨ����������������������
* �����βΣ���
* ��������ֵ���ޣ�void����
*/
void BinarySortTree::CreateBST(DataType* value, int n)
{
	for (int i = 0; i < n; i++)
		InsertBST(root, value[i]);
}

/*�������ܣ�����data�Ƿ�����ڶ�����������(�ǵݹ�)
* �����βΣ������ҵ�Ԫ��ֵ
* ��������ֵ�����ҳɹ����ظý���ַ,���򷵻�nullptr��BinTreeNode*����
*/
BinTreeNode* BinarySortTree::SearchBST(DataType data)
{
	BinTreeNode * node = root;
	while (node)
	{
		if (root->data == data) //���ҳɹ������ص�ǰ����ַ
			return root;
		else if (root->data > data)  //���ֵ���ڲ���ֵ����������
			node = node->leftchild;
		else  //���ֵС�ڲ���ֵ����������
			node = node->rightchild;
	}
	return nullptr;
}

/*�������ܣ�����data�Ƿ�����ڶ�����������(�ݹ�)
* �����βΣ������������ĸ�����ַ��BinTreeNode*���ͣ��ʹ����ҵ�Ԫ��ֵ��DataType���ͣ�
* ��������ֵ�����ҳɹ����ظý���ַ,���򷵻�nullptr��BinTreeNode*����
*/
BinTreeNode* BinarySortTree::SearchBST(BinTreeNode* root, DataType data)
{
	if(!root)  //������ֱ�ӷ��ؿ�
		return nullptr;
	if (root->data < data)  //���ֵС�ڲ���ֵ���ݹ�����������
		return SearchBST(root->rightchild, data);
	else if (root->data > data)//���ֵ���ڲ���ֵ���ݹ���������
		return SearchBST(root->leftchild, data);
	else //���������ֵ�������ֵ��
		return root;	
}

/*�������ܣ��������ݵ�������������
* �����βΣ������������ĸ�����ַ�����ã�BinTreeNode*&���ͣ��ʹ�����Ľ��ֵ��DataType���ͣ�
* ��������ֵ���ޣ�void����
*/
void BinarySortTree::InsertBST(BinTreeNode*& root, DataType data)
{
	if (!root)  //�����Ϊ�գ��򴴽������
	{
		root = new BinTreeNode;
		if (!root)  //���ռ�����ʧ��
			throw "Memory allocated failed!";
		root->data = data;  //������ֵΪ������Ľ��ֵ
		root->leftchild = root->rightchild = nullptr;  //���Һ���ָ����Ϊ��
	}
	else
	{
		if (root->data > data) //�����ֵ���ڴ�����Ľ��ֵ
			InsertBST(root->leftchild, data);
		else if (root->data < data) //�����ֵС�ڴ�����Ľ��ֵ
			InsertBST(root->rightchild, data);
	}
}

/*�������ܣ�ɾ�������������Ľ��
* �����βΣ����ֵ��DataType���ͣ�
* ��������ֵ���ޣ�void����
*/
void BinarySortTree::DeleteBST(DataType data)
{
	
}

/*�������ܣ����ٶ������������ݹ鷽ʽ��
* �����βΣ������������ĸ�����ַ��BinTreeNode*���ͣ�
* ��������ֵ���ޣ�void����
*/
void BinarySortTree::DestroyBST(BinTreeNode* root)
{
	if (root->leftchild)
		DestroyBST(root->leftchild);
	else if (root->rightchild)
		DestroyBST(root->rightchild);
	else
		delete root;
}

/*�������ܣ���������������������ݹ鷽ʽ��
* �����βΣ������������ĸ�����ַ��const BinTreeNode*���ͣ�
* ��������ֵ���ޣ�void����
*/
void BinarySortTree::InorderBST(const BinTreeNode* root)
{
	if (root)
	{
		if (root->leftchild)
			InorderBST(root->leftchild);
		std::cout << root->data << " ";
		if (root->rightchild)
			InorderBST(root->rightchild);
	}
}

/*�������ܣ���ȡ�����������ĸ�����ַ
* �����βΣ���
* ��������ֵ�����ض����������ĸ�����ַ��BinTreeNode*����
*/
inline BinTreeNode* BinarySortTree::GetRoot()
{
	return root;
}

#endif // !__BINARYSORTTREE_H__