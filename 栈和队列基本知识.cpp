/*
大纲：
1、栈和队列的结构体定义
1）顺序栈的定义
2）链栈结点定义
3）顺序队列的定义
4）链队的定义
2、基本造作：
1）链栈
2）循环队列的操作
3）链队的操作
*/


#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

typedef struct 
{
	int data[maxsize];
	int top;
}sqstack;//顺序栈的定义

typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*LinkList;//链栈的定义与单链表的定义相同

typedef struct
{
	int data[maxsize];
	int front,rear;
}SqQueue;//顺序队列的定义


/*链队的定义*/
typedef struct Qnode
{
	int data;
	struct Qnode *next;
}Qnode;/*链队节点的定义*/

typedef struct 
{
	Qnode *front;
	Qnode *rear;
	int Maxsize;
}LiQueue;/*队头队尾指针*/

//链栈的基本操作

//进栈的操作

void push(LinkList &L,int x)
{
	LinkList p;
	p=(LinkList)malloc(sizeof(Lnode));
	p->data=x;
	p->next=NULL;//每当申请新节点时，指针域设为NULL是好习惯
	p->next=L->next;
	L->next=p;
}

//
void pop(LinkList &L,int &x)
{
	LinkList temp;
	temp=L->next;
	x=L->next->data;
	L->next=temp->next;
	free(temp);
}

//顺序队列的操作
/*
队列一般指的是带头节点的队列
*/

//入队出队操作，队尾入队，队头出队

/* SqQueue qu;
qu. rear=(qu.rear+1)%maxsize;
qu.data[qu.rear]=x;

qu.front=(qu.front+1)%maxsize;
x=qu.data[qu.front];
*/

int isQueueEmpty(SqQueue qu)
{
	if(qu.rear==qu.front)
		return 1;
	else 
		return 0;
}

int enQueue(SqQueue &qu,int x)
{
	if((qu.rear+1)%maxsize==qu.front)return Error;
	qu.rear=(qu.rear+1)%maxsize;
	qu.data[qu.rear]=x;
	return 1;
}

void deQueue(SqQueue &qu,int &x)
{
	if(qu.rear==qu.front)return;
	qu.front=(qu.front+1)%maxsize;
	x=qu.data[qu.front];
}

//链队的操作
/*链队分为指针空间和队列空间，和顺序队列不同，链队不需要多出一个空余空间，*/
void initQueue(LiQueue *&lqu)
{
	lqu=(LiQueue *)malloc(sizeof(LiQueue));
	lqu->front=lqu->rear=NULL;
}

int isemptyQueue(LiQueue *&lqu)
{
	if(lqu->front==NULL||lqu->rear==NULL)return 1;
	else return 0;
}

void enQueue(LiQueue *&lqu,int x)
{
	//在进栈之前先初始化队列是必须的
	Qnode *p;
	p=(Qnode *)malloc(sizeof(Qnode));
	p->data=x;
	p->next=NULL;//notice
	if(lqu->front==NULL)lqu->front=lqu->rear=p;
	else
	{
		lqu->rear->next=p;
		lqu->rear=p;
	}
}

void deQueue(LiQueue *&lqu,int &x)
{
	if(lqu->front==NULL)return;
	else if(lqu->front==lqu->rear)
	{
		lqu->front=lqu->rear=NULL;
	}
	else
	{
		Qnode *p;
		p=lqu->front;
		lqu->front=lqu->front->next;
		x=p->data;
		free(p);
	}
}