/*
��٣�
1�����Ա�Ķ���
1��˳���Ķ���
2��������Ķ���
3��˫����Ķ���

2�����Ա�Ĳ���
1��˳���Ĳ�������
2��������Ĳ�����������Ĵ�����ͷβ�������ϲ��������ɾ���ڵ�
3��˫����Ĳ�����β�巨����˫�������ҽڵ㣬����ڵ㣬ɾ���ڵ�
*/


#include<stdio.h>
#include<stdlib.h>
#define maxsize 100

typedef struct
{
	int data[maxsize];
	int length;
}sqlist;//˳���Ķ���


typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;//������Ķ���

typedef struct DuLnode
{
	int data;
	struct DuLnode *next,*prior;
}DuLnode,*Dulinklist;//˫����Ķ���

void creatlistR(Linklist &L,int A[],int n)//β�巨����������A�������ԭ���ݣ�n������������
{
	Linklist s,r;//s������ʱ�ڵ㣬r����ָ��ǰ��������ڵ�
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

void creatlistH(Linklist &L,int A[],int n)//ͷ�巨����������
{
	Linklist s;//s������ʱ�ڵ㣬r����ָ��ǰ��������ڵ�
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

void merge(Linklist &A,Linklist &B,Linklist &C)//��A,B����ϲ��ɵ�����������
{
	Linklist p,q,r;//pָ��A��qָ��B��rָ��C
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
			r=q;
		}
		else 
		{
			r->next=p;p=p->next;
			r=p;
		}
	}
	if(p!=NULL)r->next=p;
	else r->next=q;
}

void merge(Linklist &A,Linklist &B,Linklist &C)//��A,B����ϲ��ɵ����ݼ�����
{
	Linklist p,q,r;//pָ��A��qָ��B��rָ��C
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

//ɾ���ڵ�Ĳ���,��λ��Ҫ����ڵ��ǰһ�����p
/*
q=p->next;
p->next=p->next->next;
free(q)
*/

//����ڵ�p�Ĳ���,��λ��Ҫ����ڵ��ǰһ�����q
/*
p->next=q->next;
q->next=p;
*/

void creatlistDulistR(Dulinklist &L,int A[],int sum)//����˫����
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

int findnode(Dulinklist &L,int x)//���ҽڵ�Ĳ���
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

/*ɾ���ڵ㣬�ھ����Ƚ����ڵ��������ߣ��ٽ��������
�������ڵ�Ϊp��ǰһ���ڵ�Ϊq;
p->next=q->next;
p->prior=q;
q->next=p;
p->next->prior=p;
*/


/*ɾ���ڵ�Ĳ���
����ɾ���Ľ��ǰһ�����Ϊp��
q=p->next��
p->next=q->next;
q->next->prior=p;
free(q);
*/


