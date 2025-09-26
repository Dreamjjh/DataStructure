#pragma once
#ifndef __BINARYSORTTREE_H__
#define __BINARYSORTTREE_H__

#include <iostream>
typedef int DataType;
struct BinTreeNode  //二叉树结点类型
{
	DataType data;  //结点数据域
	BinTreeNode* leftchild, * rightchild;  //左、右孩子指针
	BinTreeNode()  //构造函数，完成成员初始化
	{
		data = 0;
		leftchild = rightchild = nullptr;
	}
};

class BinarySortTree  //二叉排序树类
{
public:
	BinarySortTree();  //构造函数完成二叉排序树数据成员的初始化
	~BinarySortTree(); //析构函数，清空二叉排序中的所有结点

	void CreateBST();  //键盘输入结点值来创建二叉排序树
	void CreateBST(DataType* value, int n); //通过数组直接创建二叉排序树
	BinTreeNode* SearchBST(DataType data);  //查找data是否存在于二叉排序树中（非递归）
	BinTreeNode* SearchBST(BinTreeNode* root, DataType data);  //查找data是否存在于二叉排序树中（递归）
	void InsertBST(BinTreeNode*& root, DataType data); //插入数据到二叉排序树中
	void DeleteBST(DataType data); //删除二叉排序树中的指定结点
	void DestroyBST(BinTreeNode* root);  //销毁二叉排序树
	void InorderBST(const BinTreeNode* root);  //中序遍历二叉排序树
	BinTreeNode* GetRoot();  //获取二叉排序树的根结点

private:
	BinTreeNode* root;  //二叉排序树的根结点
	int node_number;    //二叉排序树结点数量
};

//构造函数完成二叉排序树数据成员的初始化
BinarySortTree::BinarySortTree()
{
	root = nullptr;
	node_number = 0;
}

//析构函数，清空二叉排序中的所有结点
BinarySortTree::~BinarySortTree()
{
	DestroyBST(root);  //调用成员函数，完成删除
}

/*函数功能：键盘输入结点值来创建二叉排序树
* 函数形参：无
* 函数返回值：无，void类型
*/
void BinarySortTree::CreateBST()
{
	DataType data;
	std::cin >> data;
	while (data != -1)  //只要输入结点值不是结束标记，则继续创建
	{
		InsertBST(root, data);
		std::cin >> data;
	}
}

/*函数功能：通过数组来创建二叉排序树
* 函数形参：无
* 函数返回值：无，void类型
*/
void BinarySortTree::CreateBST(DataType* value, int n)
{
	for (int i = 0; i < n; i++)
		InsertBST(root, value[i]);
}

/*函数功能：查找data是否存在于二叉排序树中(非递归)
* 函数形参：待查找的元素值
* 函数返回值：查找成功返回该结点地址,否则返回nullptr，BinTreeNode*类型
*/
BinTreeNode* BinarySortTree::SearchBST(DataType data)
{
	BinTreeNode * node = root;
	while (node)
	{
		if (root->data == data) //查找成功，返回当前结点地址
			return root;
		else if (root->data > data)  //结点值大于查找值，向左搜索
			node = node->leftchild;
		else  //结点值小于查找值，向右搜索
			node = node->rightchild;
	}
	return nullptr;
}

/*函数功能：查找data是否存在于二叉排序树中(递归)
* 函数形参：二叉排序树的根结点地址（BinTreeNode*类型）和待查找的元素值（DataType类型）
* 函数返回值：查找成功返回该结点地址,否则返回nullptr，BinTreeNode*类型
*/
BinTreeNode* BinarySortTree::SearchBST(BinTreeNode* root, DataType data)
{
	if(!root)  //空树，直接返回空
		return nullptr;
	if (root->data < data)  //结点值小于查找值，递归向右搜索等
		return SearchBST(root->rightchild, data);
	else if (root->data > data)//结点值大于查找值，递归向左搜索
		return SearchBST(root->leftchild, data);
	else //根结点数据值与待查找值相
		return root;	
}

/*函数功能：插入数据到二叉排序树中
* 函数形参：二叉排序树的根结点地址的引用（BinTreeNode*&类型）和待插入的结点值（DataType类型）
* 函数返回值：无，void类型
*/
void BinarySortTree::InsertBST(BinTreeNode*& root, DataType data)
{
	if (!root)  //如果根为空，则创建根结点
	{
		root = new BinTreeNode;
		if (!root)  //结点空间申请失败
			throw "Memory allocated failed!";
		root->data = data;  //数据域赋值为待插入的结点值
		root->leftchild = root->rightchild = nullptr;  //左、右孩子指针置为空
	}
	else
	{
		if (root->data > data) //根结点值大于待插入的结点值
			InsertBST(root->leftchild, data);
		else if (root->data < data) //根结点值小于待插入的结点值
			InsertBST(root->rightchild, data);
	}
}

/*函数功能：删除二叉排序树的结点
* 函数形参：结点值（DataType类型）
* 函数返回值：无，void类型
*/
void BinarySortTree::DeleteBST(DataType data)
{
	
}

/*函数功能：销毁二叉排序树（递归方式）
* 函数形参：二叉排序树的根结点地址（BinTreeNode*类型）
* 函数返回值：无，void类型
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

/*函数功能：中序遍历二叉排序树（递归方式）
* 函数形参：二叉排序树的根结点地址（const BinTreeNode*类型）
* 函数返回值：无，void类型
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

/*函数功能：获取二叉排序树的根结点地址
* 函数形参：无
* 函数返回值：返回二叉排序树的根结点地址，BinTreeNode*类型
*/
inline BinTreeNode* BinarySortTree::GetRoot()
{
	return root;
}

#endif // !__BINARYSORTTREE_H__