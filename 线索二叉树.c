#include<stdio.h>

typedef struct ThreadNode
{
	int data;    //数据元素
	struct ThreadNode* lchild, * rchild;  //左右孩子指针
	int ltag, rtag;  //左右线索标志
}ThreadNode, * ThreadTree;

void InThread(ThreadNode* p, ThreadNode** pre)  //中序线索二叉树构建
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);  //递归，线索化左子树
		if (p->lchild == NULL)     //左子树为空，建立前驱线索
		{
			p->lchild = *pre;
			p->ltag = 1;
		}
		if ((*pre) != NULL && (*pre)->rchild == NULL)
		{
			(*pre)->rchild = p;           //建立前驱结点的后继线索
			(*pre)->rtag = 1;
		}
		(*pre) = p;                       //标记当前节点成为刚刚访问过的节点
		InThread(p->rchild, pre);      //递归，线索化右子树
	}
}

void InitThreadNode(ThreadNode* p)    //初始化树节点
{
	p->data = 0;
	p->lchild = NULL;
	p->rchild = NULL;
	p->ltag = 0;
	p->rtag = 0;
}


void CreateInThread(ThreadTree T)    //建立中序线索二叉树
{
	ThreadNode *pre = NULL;
	if (T != NULL)
	{
		InThread(T, &pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

ThreadNode* Firstnode(ThreadNode* p)    //找出中序遍历的第一个节点
{
	while (p->ltag == 0)
		p = p->lchild;   //最左下节点（不一定是叶节点）
	return p;
}

ThreadNode* Nextnode(ThreadNode* p)    //中序遍历的下一个节点
{
	if (p->rtag == 0)
		return Firstnode(p->rchild);
	else
		return p->rchild;   //rtag==1直接返回后继续线索
}

void Inorder(ThreadNode* T)   //中序二叉树的遍历
{
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
		visit(p);
}

int main()
{
	ThreadTree s;
	ThreadTree r;
	ThreadNode A, B, C, D, E;
	InitThreadNode(&A);
	InitThreadNode(&B);
	InitThreadNode(&C);
	InitThreadNode(&D);
	InitThreadNode(&E);
	A.lchild = &B;
	B.rchild = &D;
	A.rchild = &C;
	C.lchild = &E;
	CreateInThread(&A);
	/*printf("%d\n", A.rtag);
	printf("%d\n", A.ltag);
	printf("%d\n", B.rtag);
	printf("%d\n", B.ltag);
	printf("%d\n", C.rtag);
	printf("%d\n", C.ltag);
	printf("%d\n", D.rtag);
	printf("%d\n", D.ltag);
	printf("%d\n", E.rtag);
	printf("%d\n", E.ltag);*/
	return 0;
}
