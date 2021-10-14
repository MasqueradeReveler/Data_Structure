//邻接矩阵储存
#define MaxVertexNum 100     //顶点数目的最大值
typedef char VertexType;     //顶点的数据类型
typedef int EdgeType;        //带权图中边上权值的数据类型
typedef struct
{
	VertexType Vex[MaxVertexNum];   //顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];   //邻接矩阵
	int vexnum, arcnum;             //当前定点数和弧数
}MGraph;
