#include<stdio.h>
#define SIZE 100
int UFsets[SIZE];    //最大元素个数

void Initial(int S[])    //初始化并查集
{
	for (int i = 0; i < SIZE; i++)  //每个元素自成集合
		S[i] = -1;
}

int Find(int S[], int x)    //在并查集S中查找并返回包含元素x的树的根节点
{
	while (S[x] > 0)
		x = S[x];
	return x;
}

void Union(int S[], int Root1, int Root2)   //要求Root1和Root2互斥
{
	S[Root2] = Root1;    //将Root2连接到Root1下面
}
