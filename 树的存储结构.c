#include<stdio.h>
#define MAX_TREE_SIZE 100   //树中最多节点数

typedef struct   //树的节点定义
{
	int data;
	int parent;   //双亲位置域
}PTNode;

typedef struct   //树的类型定义
{
	PTNode nodes[MAX_TREE_SIZE];   //双亲表示
	int n;          //节点数
}PTree;

typedef struct CSNode
{
	int data;     //数据域
	struct CSNode* firstchild, * nextsibling;   //第一个孩子和右兄弟指针
}CSNode,*CSTree;
