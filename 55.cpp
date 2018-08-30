#include<stdio.h>
#include<stdlib.h>
#define Maxsize 11000
#define six 6
int visited[Maxsize];
typedef struct Arcnode
{
	int adj;
	struct Arcnode *next;
}Arcnode;

typedef struct
{
	Arcnode *firstarc;
}Vnode;

typedef struct Gnode
{
	int vn;//边数
	int en;//顶点树
	Vnode adjlist[Maxsize];
}Gnode,*AGraph;
void Initialize(AGraph G)
{
	int i;
	for(i=1;i<=G->vn;++i)G->adjlist[i].firstarc=NULL;
}
void Insert(AGraph G,int v1,int v2)
{
	Arcnode *p,*temp;
	p=G->adjlist[v1].firstarc;
	if(p==NULL)
	{
		p=(Arcnode *)malloc(sizeof(Arcnode));
		p->adj=v2;
		p->next=NULL;
		G->adjlist[v1].firstarc=p;
	}
	else
	{
		temp=(Arcnode *)malloc(sizeof(Arcnode));
		temp->adj=v2;
		temp->next=p;
		G->adjlist[v1].firstarc=temp;
	}
}

void Initial_visit(int nv)
{
	int i;
	for(i=1;i<=nv;++i)visited[i]=0;
}

int sds_bfs(AGraph G,int v)
{
	Arcnode *p;
	int tail,last=v,Level=0,count=1,temp,front=0,rear=0,queue[Maxsize];
	rear=(rear+1)%Maxsize;
	queue[rear]=v;
	visited[v]=1;
	while(front!=rear)
	{
		front=(front+1)%Maxsize;
		temp=queue[front];//temp为弹出顶点
		p=G->adjlist[temp].firstarc;
		while(p!=NULL)
		{
			if(visited[p->adj]==0)
			{
				++count;
				visited[p->adj]=1;
				rear=(rear+1)%Maxsize;
				queue[rear]=p->adj;
				tail=p->adj;
			}
			p=p->next;
		}
		if(temp==last)
		{
			Level++;
			last=tail;
		}
		if(Level==six)break;
	}
	return count;
}//六度空间基于BFS算法，重点是记录层次

void Six_Degree_of_Separation(AGraph G)
{
	int i,count;
	for(i=1;i<=G->vn;++i)
	{
		Initial_visit(G->vn);
		count=sds_bfs(G,i);
		printf("%d: %.2f%%\n",i,100.0*(double)count/(double)G->vn);
	}

}//对每个结点采用六度空间算法


int main()
{
	int v1,v2,i;
	AGraph G;
	G=(AGraph)malloc(sizeof(Gnode));
	scanf("%d%d",&G->vn,&G->en);
	Initialize(G);
	for(i=0;i<G->en;++i)
	{
		scanf("%d%d",&v1,&v2);
		Insert(G,v1,v2);
		Insert(G,v2,v1);
	}
	Six_Degree_of_Separation(G);
	return 0;
}


/*这道题关于层数的统计方法为记录出队的元素是否与每一层最后一个结点相同
还有一种方法为在每个节点中加入层数这个对象，但比较复杂
emmmmmmmmmmmmmmm
*/
