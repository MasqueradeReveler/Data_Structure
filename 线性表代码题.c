#include<stdio.h>

#define MaxSize 10 //定义最大长度
typedef struct {
	int data[MaxSize]; //用静态的“数组”存放数据元素
	int length; //顺序表的当前长度
}SqList; //顺序表的类型定义（静态分配方式）

//1.从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
int Del_Min(SqList* L, int* value)
{
	//删除顺序表中最小的节点，并通过引用型参数value返回其值
	//若删除成功，则返回1，否则返回0
	if (L->length == 0)
		return 0;						//表空删除失败
	value = L->data[0];
	int pos = 0;						//记录最小值的位置
	for (int i = 1; i < L->length; i++) //循环找出最小值
		if (L->data[pos] < L->data[i])
		{
			value = L->data[i];			//用value记录最小值
			pos = i;
		}
	L->data[pos] = L->data[L->length - 1];
	L->length--;
	return 1;

}


//2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）。
void Reverse(SqList* L)
{
	int tmp;			//辅助变量
	for (int i = 0; i < L->length / 2; i++)
	{
		tmp = L->data[i];
		L->data[i] = L->data[L->length - i - 1];
		L->data[L->length - i - 1] = tmp;
	}
}


//3.对长度为n的顺序表L，编写一个时间复杂度为O(m）、空间复杂度为O（1）的算法，该算法删除线性表中所有值为x的数据元素。
void del_x_l(SqList* L, int x)
{
	int k;					//记录L中不等于x的元素
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];  //将当前元素前移k个位置
			k++;					  //不等于x的元素加1
		}
		L->length = k;
	}
}


//4.从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行。
int del_s_t_sql(SqList* L, int s, int t)
{
	int i, j;
	if (s >= t || L->length == 0)
		return 0;
	for (i = 0; L->data[i] < s && i < L->length; i++); //寻找值大于等于s的第一个元素
	if (i >= L->length)
		return 0;									   //所有元素均小于s
	for (j = i; L->data[j] <= t && j < L->length; j++);//寻找值大于t的第一个元素
	for (; j < L->length; j++, i++)
		L->data[i] = L->data[j];					   //前移，填补被删元素的位置
	L->length = i;
	return 1;
}


//5.从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出运行
int del_s_t(SqList* L, int s, int t)
{
	int k;
	if (s >= t || L->length == 0)
		return 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i]>=s && L->data[i]<=t)
			k++;
		else
			L->data[i-k] = L->data[i];
	}
	L->length -= k;
	return 1;
}
