/*
��٣�
1��ջ�Ͷ��еĽṹ�嶨��
1��˳��ջ�Ķ���
2����ջ��㶨��
3��˳����еĶ���
4�����ӵĶ���
2������������
1����ջ
2��ѭ�����еĲ���
3�����ӵĲ���
*/


#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

typedef struct 
{
	int data[maxsize];
	int top;
}sqstack;//˳��ջ�Ķ���

typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*LinkList;//��ջ�Ķ����뵥����Ķ�����ͬ

typedef struct
{
	int data[maxsize];
	int front,rear;
}SqQueue;//˳����еĶ���


/*���ӵĶ���*/
typedef struct Qnode
{
	int data;
	struct Qnode *next;
}Qnode;/*���ӽڵ�Ķ���*/

typedef struct 
{
	Qnode *front;
	Qnode *rear;
	int Maxsize;
}LiQueue;/*��ͷ��βָ��*/

//��ջ�Ļ�������

//��ջ�Ĳ���

void push(LinkList &L,int x)
{
	LinkList p;
	p=(LinkList)malloc(sizeof(Lnode));
	p->data=x;
	p->next=NULL;//ÿ�������½ڵ�ʱ��ָ������ΪNULL�Ǻ�ϰ��
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

//˳����еĲ���
/*
����һ��ָ���Ǵ�ͷ�ڵ�Ķ���
*/

//��ӳ��Ӳ�������β��ӣ���ͷ����

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

//���ӵĲ���
/*���ӷ�Ϊָ��ռ�Ͷ��пռ䣬��˳����в�ͬ�����Ӳ���Ҫ���һ������ռ䣬*/
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
	//�ڽ�ջ֮ǰ�ȳ�ʼ�������Ǳ����
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