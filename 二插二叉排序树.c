#include<stdio.h>

typedef struct BiTNode  //二叉树排序结点
{
	int data;   //数据
	int key;    //关键字
	struct BiTNode* lchild, * rchild;
}BSTNode, * BiTree;

BSTNode* BST_Search1(BiTree T, int k)    //二叉排序树非递归查找
{
	while (T != NULL && k != T->key)
	{
		if (k < T->key)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}

BSTNode* BST_Search2(BiTree T, int k)         //二叉排序树递归查找
{
	if (k > T->key)
	{
		T = T->rchild;
		BSTNode* BST_Search2(BiTree T, int k);
	}
	else if (k < T->key)
	{
		T = T->lchild;
		BSTNode* BST_Search2(BiTree T, int k);
	}
	else
		return T;
}

int BST_Insert(BiTree T, int k)
{
	if (T == NULL)               //原树为空，新插入的记录作为根结点
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;                //返回1，插入成功
	}
	else if (k == T->key)        //树中存在相同的结点，插入失败
		return 0;
	else if (k < T->key)         //插入到T的左子树 
		return BST_Insert(T->lchild, k);
	else                         //插入到T的右子树 
		return BST_Insert(T->rchild, k);
}

void Creat_BST(BiTree T, int str[], int n)
{
	T = NULL;                     //初始时树为空树
	int i = 0;
	while (i < n)                 //依次将每个关键字插入到二叉排序树中
	{
		BST_Insert(T, str[i]);
		i++;
	}
}
