#include<stdio.h>
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int length;
}SeqList;

void InitList(SeqList* L)
{
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;
	L->length = 0;
}

PrintList(SeqList L)
{
	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
}

int main()
{
	SeqList L = { {1,2,3,4,5},3 };
	PrintList(L);
	InitList(&L);
	PrintList(L);
	return 0;
}
