#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct Bitnode
{
	int data;
	struct Bitnode *lchild,*rchild;
}Bitnode,*Bitree;
void creat(Bitree &T,int sum,int c)
{
	int flag=0,front=0,rear=0;
	Bitree temp,queue[Maxsize];
	T=(Bitree)malloc(sizeof(Bitnode));
	T->data=c;
	T->lchild=T->rchild=NULL;
	flag+=1;
	rear=(rear+1)%Maxsize;
	queue[rear]=T;
	while(front!=rear)
	{
		front=(front+1)%Maxsize;
		temp=queue[front];
		if(flag!=sum)
		{
			temp->lchild=(Bitree)malloc(sizeof(Bitnode));
			scanf("%d",&temp->lchild->data);
			flag+=1;
			temp->lchild->lchild=temp->lchild->rchild=NULL;
		}
		if(flag==sum)break;
		if(flag!=sum)
		{
			temp->rchild=(Bitree)malloc(sizeof(Bitnode));
			scanf("%d",&temp->rchild->data);
			flag+=1;
			temp->rchild->lchild=temp->rchild->rchild=NULL;
		}
		if(flag==sum)break;
		rear=(rear+1)%Maxsize;
		queue[rear]=temp->lchild;
		rear=(rear+1)%Maxsize;
		queue[rear]=temp->rchild;
		}
}
void preordertraverse(Bitree T)
{
	if(T)
	{
		printf("%d",T->data);
		preordertraverse(T->lchild);
		preordertraverse(T->rchild);
	}
}
int main()
{
	int sum,temp;
	scanf("%d%d",&temp,&sum);
	Bitree T;
	creat(T,sum,temp);
	preordertraverse(T);
}