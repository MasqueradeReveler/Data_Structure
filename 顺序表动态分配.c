#include<stdio.h>
#define InitSize 10

typedef struct
{
	int* data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList* L)
{
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->length = 0;
	L->MaxSize = 0;
}

void IncreaseSize(SeqList* L,int len)
{
	int* p = L->data;
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize = L->MaxSize + len;
	free(p); //释放p指针指向的一整片空间
}

int main()
{
	SeqList L;
	InitList(&L);
	IncreaseSize(&L, 5);
	return 0;
}
