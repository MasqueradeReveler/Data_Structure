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


//6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
int del_same(SqList* L)
{
	if (L->length == 0)
		return 0;
	int i, j;				//i存储第一个不相同的元素，j为工作指针
	for (i = 0, j = 1; j < L->length; j++)
	{
		if (L->data[i] != L->data[j])
			L->data[++i] = L->data[j];
	}
	L->length = i + 1;
	return 1;
}


/*10.【2010统考真题】设将n（n>1）个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法。将R中保存的序列循环左移p（0<p<n）个位置，即将R中的数据由（X0,X1…，Xn-1变换为（Xp,Xp+1,…，Xn-1,X0,X1,…,Xp-1）.要求：
1）给出算法的基本设计思想
2）根据设计思想，采用C或C艹或JaⅦa语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度*/
//(a^-1b^-1)^-1=ba
void reverse(int R[], int from, int to)
{
	int i, tmp;
	for (i = 0; i < (to - from + 1) / 2; i++)
	{
		tmp = R[from + i];
		R[from + i] = R[to - i];
		R[to - 1] = tmp;
	}
}
void converse(int R[], int n, int p)
{
	reverse(R, 0, p - 1);
	reverse(R, p, n - 1);
	reverse(R, 0, n - 1);
}
//时间复杂度O(n) 空间复杂度O(p)


/*11.【2011统考真题】一个长度为L（L21）的升序序列S，处在第「L2个位置的数称为S的中位数。例如，若序列S1=（1l，13,15,17,19），则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=（2,4,6,8,20），则S1和S2的中位数是11现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求:
1）给出算法的基本设计思想
2）根据设计思想，采用C或++或Java语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度*/
int M_Search(int A[], int B[], int n)
{
	int s1 = 0, e1 = n - 1, m1, s2 = 0, e2 = n - 1, m2;
	//分别表示序列A、B的首位数、末尾数及中位数
	while (s1 != e1 || s2 != e2)     //两个序列中只含一个元素为止
	{
		m1 = (s1 + e1) / 2;
		m2 = (s2 + e2) / 2;
		if (A[m1] == B[m2])
			return A[m1];
		if (A[m1] < B[m2])
		{
			if ((s1 + e1) % 2 == 0)  //若元素个数为奇数
			{
				s1 = m1;			 //舍弃A小的一半，保留中位数
				e2 = m2;			 //舍弃B大的一半，保留中位数
			}
			else                     //若元素个数为偶数
			{
				s1 = m1 + 1;		 //舍弃A小的一半
				e2 = m2;			 //舍弃B大的一半
			}
		}
		else
		{
			if ((s2 + e2) % 2 == 0)
			{
				e1 = m1; 
				s2 = m2;
			}
			else
			{
				e1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return A[s1] < B[s2] ? A[s1] : B[s2];
}
//时间复杂度O(log2n) 空间复杂度O(1)
