/*
��٣�
1���������Ĵ洢�ṹ
1)˳��洢�ṹ
2)��ʽ�洢�ṹ
2���������ı����㷨
1)�ݹ�����㷨
2)�ǵݹ������
3)��α������㷨
3������������
4���������ɶ��������㷨
5���Ѽ������
6����������
7�����ϼ�������
*/

/*��������˳��洢�ṹ*/
/*
��������˳��洢�ṹ������ʵ��
BTree[i]������ΪBTree[2*i],�Һ���ΪBTree[2*i+1],�����±�
��1��ʼ��
*/

#include<stdio.h>
#define MAXSIZE 100
#include<stdlib.h>

/*��ʽ�洢�ṹ*/
typedef struct BTnode
{
	int data;
	struct BTnode *left,*right;
}BTnode,*Bitree;


/*�������ı����㷨(�ݹ����)*/
void preorder(Bitree T)
{
	if(T)
	{
		visit(T);
		preorder(T->left);
		preorder(T->right);
	}
}


/*�������ı����㷨(�ǵݹ����)*/
void preorder(Bitree T)
{
	if(T!=NULL)
	{
		Bitree temp,stack[MAXSIZE];
		int top=-1;
		stack[++top]=T;
		while(top!=-1)
		{
			temp=stack[top--];
			visit(temp);
			if(T->right)stack[++top]=T->right;
			if(T->left)stack[++top]=T->left;//NOTICE:��ջǰҪ�жϽ���Ƿ�Ϊ�պ��ڽ�ջ
		}
	}
}//�������
//�������
/*����������㷨�ǣ�
����һ����㣬��ջ�������������������ջ�꣬Ȼ��
��ջ�����ŷ��������㣬��������ڵ���ҽ����ջ��
�ظ��������衣
*/
void postorder(Bitree T)
{
	Stack s=creatstack();
	Bitree temp,P=T;
	while(P||!Isempty(s))
	{
		while(P)
		{
			push(s,T);
			P=P->left;
		}
		P=pop(s);
		printf("%d",P->data);
		P=P->right;
	}
}

//��α���
void Levelorder(Bitree T)
{
	Queue Q=creatQueue();
	Bitree p=T;
	if(T)
	{
		Add(T,Q);
		while(!Isempty(Q))
		{
			T=Delte(Q);
			printf("%d",T->data);
			if(T->left)Add(T->left,Q);
			if(T->right)Add(T->right,Q);
		}
	}
}

//�������ɶ��������㷨
void creat_T_level(Bitree T)
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


/*����������*/
/*
������������ͨ���Ѷ������������Ӷ�ȥ��ջ�ڶ������е�����
������ʵ�ַ���Ϊ���������Ľ�㲻�������Һ��ӽڵ�ʱ�������ǵ�
ָ��ָ��ǰ�����ͺ�̽��
*/
typedef struct TBTnode
{
	char data;
	int ltag,rtag;
	struct TBTnode *lchild,*rchild;
}TBTnode,*TBTlink;

void InThread(TBTlink p,TBTlink pre)//��������������
{
	if(p)
	{
		InThread(p->lchild,pre);
		if(p->lchild==NULL)
		{
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre->rchild==NULL&&pre!=NULL)
		{
			pre->rchild=p;
			pre->rtag=1;
		}
		pre=p;
		InThread(p->rchild,pre);
	}
}

void craetInThread(TBTnode *T)
{
	TBTnode *pre=NULL;
	InThread(T,pre); 
	pre->rchild=NULL;
	pre->rtag=1;
}

/*�Ѽ������*/
/*�ѣ�����˼�壬��Ϊ���Ѻ���С�ѣ�
1���������ʾ��ȫ�������Ƕѵĵ�һ������
*/
typedef struct HNode
{
	int *data;
	int size;
	int maxsize;
}HNode,*Heap;

void creatheap(Heap H)
{
	H=(Heap)malloc(sizeof(HNode));
	H->data=(int *)malloc((MAXSIZE+1)*sizeof(int));
	H->size=0;
	H->maxsize=MAXSIZE;
	H->data[0]=MAXDATA;//0���±�洢�ڱ�(������Ԫ�ش��ֵ��
}

bool Insertheap(Heap H,int x)
{
	int i;
	if(H->maxsize==H->size)return false;
	i=++H->size;
	for(;x>H->data[i/2];i=i/2)H->data[i]=H->data[i/2];
	H->data[i]=x;
	return true;
}

/*�ѵ�ɾ��
�ѵ�ɾ����������Ϊɾ�����ڵ㣬���ø������һ������滻
���ڵ㣬�����ε��������
*/
int  DeleteMax(Heap H)
{
	int x,root,parent,child;
	root=H->data[1];
	parent=1;
	x=H->data[H->size--];
	for(parent=1;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if(child+1<=H->size&&H->data[child+1]>H->data[child])
			child++;
		if(x>=H->data[child])break;
		else H->data[parent]=H->data[child];
		
	}
	H->data[parent]=x;
	return root;
}

/*���ڶѵĽ��������ַ���
��һ���ǰѴ洢��Ԫ�����β��뵽���У�
�ڶ����ǵ�Ԫ���ڶ��д洢��ʱ����Ҫ��������ѣ�
����ʵ�ֵڶ��ַ���
*/
void percdown(Heap H,int i)
{
	int x,parent,child;
	parent=i;
	x=H->data[parent];
	for(parent=i;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if(child+1<=H->size&&H->data[child+1]>H->data[child])
			child++;
		if(x>=H->data[child])break;
		else H->data[parent]=H->data[child];
	}
	H->data[parent]=x;
}

	
void Buildheap(Heap H)
{
	int i;
	for(i=H->size/2;i>0;--i)
	{
		percdown(H,i);
	}
}

 

/*Huffman���Ľ���*/
/*huffman ��������С�ѵĽ��������Ե�˼·������*/

typedef struct Huffmannode
{
	int weight;
	struct Huffmannode *left;
	struct Huffmannode *right;
}Huffmannode,*HuffmanTree;


/*
����ͨ����Ȩֵ���ڶ��У�������С�ѵķ�ʽ��
ͨ���ڶ���ȡ��С��Ԫ�����������������ķ�ʽ
*/
/*
��������Ƚ���HuffmanTree[2*N-1],Ȼ�����Ȩֵ������С�ѣ����ȡ������СԪ��
�ҳ���Ӧ�����ڵ㣬Ȼ�����µĽ�㲢�Ѵ˽ڵ㲢��HuffmanTree[2*N-1]�У���Ȩֵ����
��С����,�ظ�ѭ��
*/
HuffmanTree Buildhuffman(Heap H)
{
	HuffmanTree T;
	Buildheap(H);//������С�ѣ�
	int i,N;
	N=H->size;
	for(i=1;i<N;++i)//N��Ԫ����N-1�κϲ�
	{

	}
}

/*���ϼ�������*/
/*���ϲ��ò��鼯*/
#define MAXN 1000                  /* �������Ԫ�ظ��� */
typedef int ElementType;           /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
typedef int SetName;               /* Ĭ���ø������±���Ϊ�������� */
typedef ElementType SetType[MAXN]; /* ���輯��Ԫ���±��0��ʼ */

void Union( SetType S, SetName Root1, SetName Root2 )
{ /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
    /* ��֤С���ϲ���󼯺� */
    if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
        S[Root2] += S[Root1];     /* ����1���뼯��2  */
        S[Root1] = Root2;
    }
    else {                         /* �������1�Ƚϴ� */
        S[Root1] += S[Root2];     /* ����2���뼯��1  */
        S[Root2] = Root1;
    }
}
 
SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
    if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
}
