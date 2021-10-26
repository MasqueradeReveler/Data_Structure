//最小生成树

GENERIC_MST(G)    //通用算法
{
  T=NULL;
  while T未形成一棵生成树
    do 找到一条最小代价边(u,v)并且加入T后不会产生回路；
      T=T∪(u,v);
}

void Prim(G,T)    //Prim算法
{
  T=∅；      //初始化空树
  U={w};     //添加任意定点w
  while((V-U)!=∅)  //若树中不含全部顶点
  {
    设(u,v)是使u∈U与v∈(V-U),且权值最小的边；
    T=T∪{(u,v)};  //边归入树
    U=U∪{v};      //顶点归入树
  }
}

void Kruskal(V,T)   //Kruskal算法
{
  T=V;                    //初始化树T，仅含定点
  numS=n;                 //连通分量数
  while(numS>1)           //若连通分量大于1
  {
     从E中取出权值最小的边；
    if(v和u属于T中不同的连通分量)
    {
      T=T∪{(v,u)};        //将此边加入生成树中
      numS--;              //连通分量数减1
    }
  }
}
