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


void PreOder2(BiTree T)             //非递归算法先序遍历
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

void InOrder2(BiTree T)        //非递归算法中序遍历
{
	InitStack(S);
	BiTree p = T;
	while (p || !IsEmpty(S))
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

void PostOrder2(BiTree T)        //非递归算法后序遍历
{
	InitStack(S);
	BiTree p = T;
	BiTree r = NULL;
	while (p || !IsEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			GetTop(S, p);               //读取栈顶元素（非出栈）
			if (p->rchild && p->rchild != r)  //右子树存在且未被访问过
				p = p->rchild;
			else
			{
				Pop(S, p);
				visit(p);
				r = p;           //记录最近访问过的节点
				p = NULL;        //节点访问完后，重置p指针
			}
		}
	}
}

void LevelOrder(BiTree T)
{
	InitQueue(Q);             //初始化辅助队列
	BiTree p;
	EnQueue(Q, T);            //根节点入队
	while (!IsEmpty(Q))       //队列非空则循环
	{
		DeQueue(Q, p);        //队头结点出队
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);  //左子树非空则左子树根节点入队
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);  //右子树非空则右子树根节点入队
	}
}
