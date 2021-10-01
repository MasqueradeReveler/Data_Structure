#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

void InitList(LinkList L)  //不带头结点初始化
{
	L = NULL;
}

int InitListHead(LinkList L)  //带头结点初始化
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return 0;  //内存空间不足
	L->next = NULL;
	return 1;
}

int Empty(LinkList L)
{
	if (L == NULL)
		return 1;
	else
		return 0;
}

LinkList List_HeadNodeInsert(LinkList L)  //带头结点头插法
{
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
}

LinkList List_HeadInsert(LinkList L)  //不带头结点头插法
{
	LNode* s; int x;
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		L = s;
	}
}

LNode* Getelem(LinkList L, int i)
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

int main()
{
	LinkList L;
	List_HeadNodeInsert(&L);
	return 0;
}
