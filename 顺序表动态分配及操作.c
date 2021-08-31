#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#define InitSize 10

void Menu()
{
	printf("*************\n");
	printf("01.初始化表\n02.求表长\n03.按值查找\n04.按位查找\n05.插入元素\n06.删除元素\n07.打印表\n08.是否为空表\n09.销毁表\n10.增加表容量\n11.目前表容量\n00.退出\n");
	printf("*************\n");
}

typedef struct
{
	int* data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList* L)  //初始化队列
{
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}

void Length(SeqList L)  //求表长
{
	printf("此表的长度为%d\n", L.length);
}

void GetElem(SeqList L)
{
	int i;
	printf("请输入要打印的元素序号:>");
	scanf("%d", &i);
	printf("第%d号元素为%d\n", i, L.data[i - 1]);
}

void IncreaseSize(SeqList* L)  //增加队列长度
{
	int len;  //需要增加的长度
	printf("继续扩充队列数:>");
	scanf("%d", &len);
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;
	free(p);
}

void InsertList(SeqList* L)   //添加元素
{
	int i;  //插入元素位置
	int e;  //插入的元素
	if (L->length >= L->MaxSize)
		printf("队列已存满\n");
	else
	{
		printf("请输入插入的元素:>");
		scanf("%d", &e);
		printf("请输入要插入的位置:>");
		scanf("%d", &i);
		if (i - 1 > L->length)
			printf("输入值非法\n");
		else
		{
			for (int j = L->length; j >= i; j--)
				L->data[j] = L->data[j - 1];
			L->data[i - 1] = e;
			L->length++;
			printf("存储成功\n");
		}
	}
}

void ListDelete(SeqList* L, int* e)  //删除元素
{
	int i;
	printf("请输入删除元素序号:>");
	scanf("%d", &i);
	if (i<1 || i>L->length)
		printf("输入的值非法\n");
	else
	{
		*e = L->data[i - 1];
		for (int j = i; j < L->length; j++)
			L->data[j - 1] = L->data[j];
		L->length--;
		printf("删除成功\n");
	}
}

void LocateElem(SeqList L)  //按值查找
{
	int i, e, a = 1;
	printf("请输入要查找元素的值:>");
	scanf("%d", &e);
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			printf("该元素在列表中的第%d位\n", i + 1);
			a = 0;
		}
	}
	if (a == 1)
	{
		printf("列表中没有该元素\n");
	}
}

PrintList(SeqList L)   //打印列表
{
	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
}

void Empty(SeqList L)
{
	if (L.length == 0)
		printf("此表为空\n");
	else
		printf("此表非空\n");
}

void CurrentSize(SeqList L)
{
	printf("目前表的容量为%d\n", L.MaxSize);
}

void DestroyList(SeqList* L)
{
	free(L->data);
	L->data = NULL;
	L->length = 0;
	L->MaxSize = 0;
	printf("销毁成功\n");
}

int main()
{
	int i, e;
	SeqList L;
	InitList(&L);
	do
	{
		Menu();
		printf("此次需要进行操作:>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			InitList(&L);
			printf("初始化成功！\n");
			break;
		case 2:
			Length(L);
			break;
		case 3:
			LocateElem(L);
			break;
		case 4:
			GetElem(L);
			break;
		case 5:
			InsertList(&L);
			break;
		case 6:
			ListDelete(&L, &e);
			break;
		case 7:
			PrintList(L);
			break;
		case 8:
			Empty(L);
			break;
		case 9:
			DestroyList(&L);
			break;
		case 10:
			IncreaseSize(&L);
			break;
		case 11:
			CurrentSize(L);
			break;
		case 0:
			printf("退出程序\n");
			break;
		}
	} while (i);
	return 0;
}
