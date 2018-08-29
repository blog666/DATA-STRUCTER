 /*
 大纲
 1、二叉树的基本结构
 2、二叉树的构造
 3、二叉树的遍历
 1）深度优先遍历
 2）广度优先遍历
 4、最短路径问题
 */


/*二叉树的基本结构*/

/*邻接矩阵*/

#define Maxsize 100
typedef struct Vnode
{
	int no;
	char info;
}Vnode;

typedef struct Gnode
{
	int vn,en;//vn代表顶点个数，en代表边的个数
	int edges[Maxsize][Maxsize];
	Vnode vertex[Maxsize];
}Gnode,*Mgraph;

/*邻接表*/

typedef struct Arcnode
{
	struct Arcnode *Next;
	int adjvex;
	int info;
}Arcnode;

typedef struct 
{
	char data;  //顶点信息
	Arcnode *firstarc;
}Vnode;

typedef struct
{
	int en,vn;
	Vnode adjlist[Maxsize];
}AGraph;


/*二叉树的遍历*/

/*深度优先搜索遍历(Depth First Sort (DFS))*/

/*算法思想：深度搜索，就是找到一个结点就继续往下找下去，不回头*/

bool visit[Maxsize];

//邻接表类型

void DFS(AGraph *G,int v)
{
	Arcnode *p;
	visit[v]=true;
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visit[p->adjvex]==0)DFS(G,p->adjvex);
		p=p->Next;
	}
}


/*广度优先搜索遍历(Breadth First Sort (DFS))*/

/*算法思想：与深度优先不同的是，广度优先首先把这个节点
周围所有节点都访问进去，然后再访问下一个节点*/

void BFS(AGraph *G,int v)
{
	Arcnode *p;
	int j,front=0,rear=0,queue[Maxsize];
	visit[v]=true;
	rear=(rear+1)%Maxsize;
	queue[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%Maxsize;
		j=queue[front];
		p=G->adjlist[j].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==false)
			{
				visit[p->adjvex]=true;
				rear=(rear+1)%Maxsize;
				queue[rear]=p->adjvex;
			}
			p=p->Next;
		}
	}
}

//邻接矩阵类型
void DFS(Mgraph G,int v)
{
	int i;
	visit[v]=true;
	Visit[v];//访问V
	for(i=0;i<G->vn;++i)
	{
		if(G->edges[v][i]==1&&visit[i]=false)
			DFS(G,i);
	}
}




/***最短路径算法**邻接矩阵存储*/

/*某一固定点到其余点的最短路径*/

/***dijkstra**迪杰斯特拉算法*/


void dijkstra(Mgraph G,int v)
{
	int min,i,j,u,set[Maxsize],dist[Maxsize],path[Maxsize];
	for(i=0;i<G->vn;++i)
	{
		set[i]=0;
		dist[i]=G->edges[v][i];
		if(G->edges[v][i]<INF)path[i]=v;
		else path[i]=-1;
	}//初始化操作
	set[v]=1;
	for(i=0;i<G->vn-1;++i)
	{
		min=INF;
		for(j=0;j<G->vn;++j)
		{
			if(set[j]==0&&dist[j]<min)
			{
				u=j;
				min=dist[j];
			}
		}
		set[u]=1;
		for(j=0;j<G->vn;++j)
		{
			if(set[j]==0&&dist[u]+G->edges[u][j]<dist[j])
			{
				dist[j]=dist[u]+G->edges[u][j];
				path[j]=u;
			}
		}
	}
}


/***弗洛伊德算法***/

void Floyd(Mgraph G,int path[][Maxsize])
{
	int i,j,k;
	int dist[Maxsize][Maxsize],path[Maxsize][Maxsize];
	for(i=0;i<G->vn;++i)
		for(j=0;j<G->vn;++j)
		{
			dist[i][j]=G->edges[i][j];
			path[i][j]=-1;
		}
		for(i=0;i<G->vn;++i)
		{
			for(j=0;j<G->vn;++j)
			{
				for(k=0;k<G->vn;++k)
				{
					if(dist[i][k]+dist[k][j]<dist[i][j])
					{
						dist[i][j]=dist[i][k]+dist[k][j];
						path[i][j]=k;
					}
				}
			}
		}
}

/**最短路径的输出**/

void printpath(int u,int v,int path[][Maxsize])
{
	if(path[u][v]==-1)printf("%d ",path[u][v]);
	else
	{
		int mid=path[u][v];
		printpath(u,mid,path);
		printpath(mid,v,path);
	}
}


/***难点：生成树问题***/


/***最小生成树***/

/**普里姆算法**prim*/

/**普里姆算法的核心思想与adjkstra算法无大的区别

主要是无路径这一说法**/

void prim(Mgraph G,int v0,int &sum)//sum 用来更新生成树的权值
{
  int i,j,v,u,min,set[Maxsize],int dist[Maxsize];
  for(i=0;i<G->vn;++i)
  {
  set[i]=0;
  dist[i]=G->edges[v0][i];
  }
  set[v0]=1;
  for(i=0;i<G->vn-1;++i)
  {
    min=INF;
    for(j=0;j<G->vn;++j)
    {
      if(set[j]==0&&dist[j]<min)
      {
       min=dist[j]];
       u=j;
      }
    }
    set[u]=1;
    v=j;
    sum+=min;
    for(j=0;j<G->vn;++j)
    {
       if(set[j]==0&&dist[j]>G->edges[v][j])
       {
         dist[j]=G->edges[v][j];
       }
    }
}


/***prim算法时间复杂度为O（n的平方），适用于稠密图***/


/***克鲁斯卡尔算法***kruskal***/

/**kruskal算法的思想为：每次从图中选择最小边并入生成树中，
但也注意不能构成回路，因此用到并查集的算法**/

typedef struct {
int a,b;//一条边的两个顶点
int weight;
}Road;

Road road[Maxsize];//边的集合
int v[Maxsize];//并查集数组

int GETROOT(int a)
{
   while(V[a]!=a)a=V[a];
  return a;
}

void Kruskal(Mgraph G,Road road[])
{
   int i;
   int N,e,a,b;
   N=G->vn;
   E=G->en;
   for(i=0;i<G->N;++i)v[i]=i;
   sort(Road,E);//对Road 数组中的边按权值从小到大排序
   for(i=0;i<E;++i)
   {
      a=GETROOT(road[i].a);
      b=GETROOT(road[i].b);
      if(a!=b)
      {
         v[a]=b;
      }
   }
}