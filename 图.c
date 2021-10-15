//邻接矩阵存储
#define MaxVertexNum 100     //顶点数目的最大值
typedef char VertexType;     //顶点的数据类型
typedef int EdgeType;        //带权图中边上权值的数据类型
typedef struct
{
	VertexType Vex[MaxVertexNum];   //顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];   //邻接矩阵
	int vexnum, arcnum;             //当前定点数和弧数
}MGraph;

//邻接表存储
#define MaxVertexNum 100     //图中顶点数最大值
typedef char VertexType;     //顶点的数据类型
typedef int EdgeType;        //带权图中边上权值的数据类型
typedef struct ArcNode       //边表结点
{
	int adjvex;              //该弧所指向的顶点的位置
	struct ArcNode* next;    //指向的下一条指针
	//Edgetype info;         //网的边权值
}ArcNode;

typedef struct VNode          //顶点表结点
{
	VertexType data;          //顶点表信息
	ArcNode* first;           //指向第一条依附该顶点的指针
}VNode,AdjList[MaxVertexNum];

typedef struct
{
	AdjList vertices;         //邻接表
	int vexnum, arcnum;       //图的顶点数和弧数
}ALGraph;                     //ALGraph是邻接表存储的图类型
