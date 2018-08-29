 /*
 ���
 1���������Ļ����ṹ
 2���������Ĺ���
 3���������ı���
 1��������ȱ���
 2��������ȱ���
 4�����·������
 */


/*�������Ļ����ṹ*/

/*�ڽӾ���*/

#define Maxsize 100
typedef struct Vnode
{
	int no;
	char info;
}Vnode;

typedef struct Gnode
{
	int vn,en;//vn�����������en����ߵĸ���
	int edges[Maxsize][Maxsize];
	Vnode vertex[Maxsize];
}Gnode,*Mgraph;

/*�ڽӱ�*/

typedef struct Arcnode
{
	struct Arcnode *Next;
	int adjvex;
	int info;
}Arcnode;

typedef struct 
{
	char data;  //������Ϣ
	Arcnode *firstarc;
}Vnode;

typedef struct
{
	int en,vn;
	Vnode adjlist[Maxsize];
}AGraph;


/*�������ı���*/

/*���������������(Depth First Sort (DFS))*/

/*�㷨˼�룺��������������ҵ�һ�����ͼ�����������ȥ������ͷ*/

bool visit[Maxsize];

//�ڽӱ�����

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


/*���������������(Breadth First Sort (DFS))*/

/*�㷨˼�룺��������Ȳ�ͬ���ǣ�����������Ȱ�����ڵ�
��Χ���нڵ㶼���ʽ�ȥ��Ȼ���ٷ�����һ���ڵ�*/

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

//�ڽӾ�������
void DFS(Mgraph G,int v)
{
	int i;
	visit[v]=true;
	Visit[v];//����V
	for(i=0;i<G->vn;++i)
	{
		if(G->edges[v][i]==1&&visit[i]=false)
			DFS(G,i);
	}
}




/***���·���㷨**�ڽӾ���洢*/

/*ĳһ�̶��㵽���������·��*/

/***dijkstra**�Ͻ�˹�����㷨*/


void dijkstra(Mgraph G,int v)
{
	int min,i,j,u,set[Maxsize],dist[Maxsize],path[Maxsize];
	for(i=0;i<G->vn;++i)
	{
		set[i]=0;
		dist[i]=G->edges[v][i];
		if(G->edges[v][i]<INF)path[i]=v;
		else path[i]=-1;
	}//��ʼ������
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


/***���������㷨***/

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

/**���·�������**/

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


/***�ѵ㣺����������***/


/***��С������***/

/**����ķ�㷨**prim*/

/**����ķ�㷨�ĺ���˼����adjkstra�㷨�޴������

��Ҫ����·����һ˵��**/

void prim(Mgraph G,int v0,int &sum)//sum ����������������Ȩֵ
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


/***prim�㷨ʱ�临�Ӷ�ΪO��n��ƽ�����������ڳ���ͼ***/


/***��³˹�����㷨***kruskal***/

/**kruskal�㷨��˼��Ϊ��ÿ�δ�ͼ��ѡ����С�߲����������У�
��Ҳע�ⲻ�ܹ��ɻ�·������õ����鼯���㷨**/

typedef struct {
int a,b;//һ���ߵ���������
int weight;
}Road;

Road road[Maxsize];//�ߵļ���
int v[Maxsize];//���鼯����

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
   sort(Road,E);//��Road �����еı߰�Ȩֵ��С��������
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