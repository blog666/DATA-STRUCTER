/*
大纲：
1、线性表的定义
1）顺序表的定义
2）单链表的定义
3）双链表的定义

2、线性表的操作
1）顺序表的操作：无
2）单链表的操作：单链表的创建（头尾法），合并，插入和删除节点
3）双链表的操作：尾插法建立双链表，查找节点，插入节点，删除节点
*/


#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

typedef struct
{
	int data[maxsize];
	int length;
}sqlist;//顺序表的定义


typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;//单链表的定义

typedef struct DuLnode
{
	int data;
	struct DuLnode *next,*prior;
}DuLnode,*Dulinklist;//双链表的定义

void creatlistR(Linklist &L,int A[],int n)//尾插法建立单链表，A数组代表原数据，n代表数据总数
{
	Linklist s,r;//s代表临时节点，r用来指向当前链表的最后节点
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	r=L;
	for(int i=0;i<n;++i)
	{
		s=(Linklist)malloc(sizeof(Lnode));
		s->data=A[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

void creatlistH(Linklist &L,int A[],int n)//头插法建立单链表
{
	Linklist s;//s代表临时节点，r用来指向当前链表的最后节点
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	for(int i=0;i<n;++i)
	{
		s=(Linklist)malloc(sizeof(Lnode));
		s->data=A[i];
		s->next=L->next;
		L->next=s;
	}
}

void merge(Linklist &A,Linklist &B,Linklist &C)//把A,B链表合并成单调递增链表
{
	Linklist p,q,r;//p指向A，q指向B，r指向C
    p=A->next;
	q=B->next;
	C=A;
	C->next=NULL;
	r=C;
	free(B);
	while(p!=NULL&&q!=NULL)
	{
		if(p->data>=q->data)
		{
			r->next=q;q=q->next;
			r=r->next;
		}
		else 
		{
			r->next=p;p=p->next;
			r=r->next;
		}
	}
	if(p!=NULL)r->next=p;
	else r->next=q;
}

void merge(Linklist &A,Linklist &B,Linklist &C)//把A,B链表合并成单调递减链表
{
	Linklist p,q,r;//p指向A，q指向B，r指向C
    p=A->next;
	q=B->next;
	C=A;
	C->next=NULL;
	free(B);
	while(p!=NULL&&q!=NULL)
	{
		if(p->data>=q->data)
		{
			r=q;q=q->next;
			r->next=C->next;
			C->next=r;
		}
		else 
		{
			r=p;p=p->next;
			r->next=C->next;
			C->next=r;
		}
	}
	while(p!=NULL)
	{
		r=p;p=p->next;
		r->next=C->next;
		C->next=r;
	}
	while(q!=NULL)
	{
		r=q;q=q->next;
		r->next=C->next;
		C->next=r;
	}
}

//删除节点的操作,定位到要插入节点的前一个结点p
/*
q=p->next;
p->next=p->next->next;
free(q)
*/

//插入节点p的操作,定位到要插入节点的前一个结点q
/*
p->next=q->next;
q->next=p;
*/

void creatlistDulistR(Dulinklist &L,int A[],int sum)//创建双链表
{
	Dulinklist s,r;
	L=(Dulinklist)malloc(sizeof(DuLnode));
	L->next=L->prior=NULL;
	r=L;
	for(int i=0;i<sum;++i)
	{
		s=(Dulinklist)malloc(sizeof(DuLnode));
		s->data=A[i];
		s->prior=r;
		r->next=s;
		r=s;
	}
	r->next=NULL;
}

int findnode(Dulinklist &L,int x)//查找节点的操作
{
	Dulinklist p;
	p=L->next;
	while(p!=NULL)
	{
		if(p->data==x)break;
		p=p->next;
	}
	if(p!=NULL)return 1;
	else return 0;
}

/*删除节点，口诀：先结插入节点引出的线，再接引入的线
假设插入节点为p；前一个节点为q;
p->next=q->next;
p->prior=q;
q->next=p;
p->next->prior=p;
*/


/*删除节点的操作
假设删除的结点前一个结点为p；
q=p->next；
p->next=q->next;
q->next->prior=p;
free(q);
*/


