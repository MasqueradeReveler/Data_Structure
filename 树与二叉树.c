#include<stdio.h>

typedef struct BiTNode  //二叉树链式存储
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

void PreOrder(BiTree T)  //先序遍历
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)  //中序遍历
{
	if (T != NULL)
	{
		PreOrder(T->lchild);
		visit(T);
		PreOrder(T->rchild);
	}
}

void PostOrder(BiTree T)  //后序遍历
{
	if (T != NULL)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		visit(T);
	}
}

void InOrder2(BiTree)  //中序遍历非递归
{
	InitiStack(S);
	BiTree p = T;
	while (p || IsEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			Pop(S, p);
			visit(p);
			p = p->rchild;
		}
	}
}
