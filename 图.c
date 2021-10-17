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



int visited[MaxVertexNum];              //访问标记数组
void BFSTraverse(MGraph G)              //对图G进行广度优先遍历
{
	
	for (int i = 0; i < G.vexnum; ++i)
	{
		visited[i] = 0;					//访问标记数组初始化
		InitQueue(Q);					//初始化队列Q
		for (i = 0; i < G.vexnum; ++i)  //从0号顶点开始遍历
			if (!visited[i])            //对每个连通分量调用一次BFS
				BFS(G, i);				//v(i)未访问过，从v(i)开始BFS
	}
}
	
void BFS(MGraph G, int v)				//从顶点v出发，广度优先遍历图G
{
	visit(v);							//访问初始节点v
	visited[v] = 1;						//对v做已访问标记
	EnQueue(Q, v);						//顶点v入队列Q
	while (IsEmpty(Q)!=0)
	{
		DeQueue(Q, v);					//顶点v出队列
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
										//检测v的所有邻接点
			if (!visited[w])			//w为v尚未访问的邻接点
			{
				visit(w);				//访问顶点w
				visited[w] = 1;         //对w做已访问标记
				EnQueue(Q, w);			//顶点w入队列
			}
	}
}

void BFS_MIN_Distance(MGraph G, int u)  //广度优先求解最短路径
{
	int d[MaxVertexNum];                //d[i]表示从u到i的最短路径
	for (int i = 0; i < G.vexnum; i++)
		d[i]=-1;						//初始化路径长度
	visited[u] = 1;
	d[u] = 0;
	EnQueue(Q, u);
	while (IsEmpty(Q) != 0)				//BSF算法主过程
	{
		DeQueue(Q, u);					//元素u出队
		for(int w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))
			if (!visited[w])			//w为u的尚未访问的邻接顶点
			{
				visited[w] = 1;			//设已访问标记
				d[w] = d[u] + 1;		//路径长度加1
				EnQueue(Q, w);			//顶点w入队
			}
	}
}
