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


//7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
int merge(SqList A, SqList B, SqList* C)
//将顺序表A与B合并为一个新的顺序表C
{
	if (A.length + B.length > MaxSize)
		return 0;
	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length)	//循环，两两比较，小的元素进入结果表
	{
		if (A.data[i] <= B.data[j])
			C->data[k++] = A.data[i++];
		else
			C->data[k++] = B.data[j++];
	}
	while (i < A.length)					//剩余的顺序表直接加入最后
		C->data[k++] = A.data[i++];
	while (j < B.length)
		C->data[k++] = B.data[j++];
	C->length = k;
	return 1;
}


//8.已知在一维数组A[m+n]中依次存放两个线性表（a1,a2,a3,…，am）和（b1，b2,b3,…，bn）。试编写一个函数，将数组中两个顺序表的位置互换，即将（b1，b2b3，…，bn）放在（a1，a2a3，…，an的前面。
typedef int Datatype;
void reverse_array(int A[], int left, int right, int arraysize)
{
	if (left >= right || right >= arraysize)
		return;
	int mid = (left + right) / 2;
	for (int i = 0; i <= mid - left; i++)
	{
		Datatype tmp = A[left + i];
		A[left + i] = A[right - i];
		A[right - i] = tmp;
	}
}

void Exchange(Datatype A[], int m, int n, int arraysize)
{
	reverse_array(A, 0, m + n - 1, arraysize);
	reverse_array(A, 0, n - 1, arraysize);
	reverse_array(A, n, m + n - 1, arraysize);
}


//9.线性表(a1a2a，…，an）中的元素递增有序且按顺序存储于计算机内。要求设计一算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素位置相交换，若找不到则将其插入表中并使表中元素仍递增有序
void SearchExchangeInsert(int A[], int x)
{
	int low = 0, high = MaxSize - 1, mid, t, i;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == x)
			break;
		else if (A[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (A[mid] == x && mid != MaxSize - 1)
	{
		t = A[mid];
		A[mid] = A[mid + 1];
		A[mid] = t;
	}
	if (low > high)
	{
		for ( i = MaxSize - 1; i > high; i--)
			A[i + 1] = A[i];
		A[i + 1] = x;
	}
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


/*12.【2013统考真题】上知一个整数序列A=（a0,a1…，an-1），其中0≤ai<n（0≤1<n）若存在ap1=ap2=…=apm=x且m>n/2（0≤pk<n，1≤k≤m）则称x为A的主元素。例如A=（0,5,5,3,5,7,5,5），则5为主元素；又如A=（0,5,5,3,5,1,5,7），则A中没有主元素。假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。若存在主元素，则输出该元素；否则输出-1.要求：
1）给出算法的基本设计思想
2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度。*/
int Majority(int A[],int n)
{
	int i,c,count=1;					//c用来保存候选主元素，count用来计数
	c=A[0];								//设置A[0]为候选主元素
	for(i<1;i<n;i++)					//查找候选主元素
		if(A[i]==c)	
			count++;					//对A中的候选主元素计数
		else
			if(count>0)					//处理不是候选主元素的情况
				count--；
			else{						//更换候选主元素，重新计数
				c=A[i];
				count=1;
			}
	if(count>0)
		for(i=count=0;i<n;i++)			//统计候选主元素的实际出现次数
			if(A[i]==c)
				count++;
	if(count>n/2) return c;				//确认候选元素
	else return-1； 					//不存在主元素
}


/*13.【2018统考真题】给定一个含n（n≥1）个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组{-5,3,2,3}中未出现的最小正整数是1；数组{1,2,3}中未出现的最小正整数是4.要求
1）给出算法的基本设计思想
2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释
3）说明你所设计算法的时间复杂度和空间复杂度。*/
int findMissMin(int A[],int n)
{
	int i,*B;						//标记数组
	B=(int *)malloc(sizeof(int)*n); //分配空间
	memset(B,0,sizeof(int)*n);		//赋初值为0
	for(i=0;i<n;i++)
		if(A[i]>0&&A[i]<=n)			//若A[i]的值介于1~n，则标记数组B
			B[A[i]-1]=1;
	for(i=0;i<n;i++)				//扫描数组B，找到目标值
		if(B[i]==0) break;
	return i+1;						//返回结果
}

/*14.【2020统考真题】定义三元组(a, b, c)(a、b、c均为正数）的距离D = la-b| + |b-c| + |c-a|。给定3个非空整数集合S1、S2和S3，按升序分别存储在3个数组中。请设计一个尽可能高效的算法，计算并输出所有可能的三元组(a, b, c) (a∈S1, b∈S2, c∈S3）中的最小距离。例如S1={-1, 0, 9}，S2 = {-25, -10, 10, 11}，S= {2, 9, 17, 30, 41}，则最小距离为2，相应的三元组为(9, 10, 9)。要求:
1）给出算法的基本设计思想。
2）根据设计思想，采用C语言或C++语言描述算法，关键之处给出注释。
3）说明你所设计算法的时间复杂度和空间复杂度。*/
#define INT MAX Ox7fffffff
int abs(int a) //计算绝对值
{
	if (a < 0)
		return -a;
	else return a;
}
bool xls_min(int a, int b, int c) //a是否是三个数中的最小值
{
	if (a <= b && a <= c)
		return true;
	return false;
}
int findMinofTrip(int A[], int n, int B[], int m, int C[], int p) //D_min用于记录三元组的最小距离，初值赋为INT MAX
{
	int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
	while (i < n && j < m && k < p && D_min>0)
	{
		D = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);//计算D
		if (D < D_min)
			D_min = D;//更新D
		if (xls_min(A[i], B[j], C[k]))
			i++;//更新a
		else if (xls_min(B[j], C[k], A[i]))
			j++;
		else k++;
	}
	return D_min;
}
