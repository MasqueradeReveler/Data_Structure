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


void PreOder2(BiTree T)
{
	InitStack(S);               //初始化栈S
	BiTree p = T;               //p为遍历指针
	while (p || !IsEmpty(S))    //栈不空或指针不空时循环
	{
		if (p)                  //指针一路向左
		{
			visit(p);
			Push(S, p);
			p = p->lchild;      //左孩子不空继续左走
		}
		else
		{
			Pop(S, p);          //栈顶元素出栈
			p = p->rchild;      //向右子树走，p赋值为当前节点右孩子
		}
	}
}
