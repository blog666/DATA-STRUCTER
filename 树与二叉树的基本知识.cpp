/*
大纲：
1、二叉树的存储结构
1)顺序存储结构
2)链式存储结构
2、二叉树的遍历算法
1)递归遍历算法
2)非递归遍历算
3)层次遍历的算法
3、线索二叉树
4、层序生成二叉树的算法
5、堆及其操作
6、哈夫曼树
7、集合及其运算
*/

/*二叉树的顺序存储结构*/
/*
二叉树的顺序存储结构用数组实现
BTree[i]的左孩子为BTree[2*i],右孩子为BTree[2*i+1],数组下标
从1开始。
*/

#include<stdio.h>
#define MAXSIZE 100
#include<stdlib.h>

/*链式存储结构*/
typedef struct BTnode
{
	int data;
	struct BTnode *left,*right;
}BTnode,*Bitree;


/*二叉树的遍历算法(递归遍历)*/
void preorder(Bitree T)
{
	if(T)
	{
		visit(T);
		preorder(T->left);
		preorder(T->right);
	}
}


/*二叉树的遍历算法(非递归遍历)*/
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
			if(T->left)stack[++top]=T->left;//NOTICE:进栈前要判断结点是否为空后在进栈
		}
	}
}//先序遍历
//中序遍历
/*中序遍历的算法是：
遇到一个结点，入栈，并把他的左结点持续入栈完，然后
退栈，接着访问这个结点，并把这个节点的右结点入栈，
重复上述步骤。
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

//层次遍历
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

//层序生成二叉树的算法
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


/*线索二叉树*/
/*
线索二叉树是通过把二叉树线索化从而去掉栈在二叉树中的作用
，具体实现方法为当二叉树的结点不存在左右孩子节点时，把它们的
指针指向前驱结点和后继结点
*/
typedef struct TBTnode
{
	char data;
	int ltag,rtag;
	struct TBTnode *lchild,*rchild;
}TBTnode,*TBTlink;

void InThread(TBTlink p,TBTlink pre)//中序线索二叉树
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

/*堆及其操作*/
/*堆，顾名思义，分为最大堆和最小堆，
1、用数组表示完全二叉树是堆的第一个特性
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
	H->data[0]=MAXDATA;//0号下标存储哨兵(比所有元素大的值）
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

/*堆的删除
堆的删除基本操作为删除根节点，并用根的最后一个结点替换
根节点，在依次调整这个堆
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

/*关于堆的建立有两种方法
第一种是把存储的元素依次插入到堆中，
第二种是当元素在堆中存储好时仅需要调整这个堆，
这里实现第二种方法
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

 

/*Huffman树的建立*/
/*huffman 树采用最小堆的建立方法显得思路很清晰*/

typedef struct Huffmannode
{
	int weight;
	struct Huffmannode *left;
	struct Huffmannode *right;
}Huffmannode,*HuffmanTree;


/*
这里通过把权值存在堆中，建立最小堆的方式，
通过在堆中取最小的元素来建立哈夫曼树的方式
*/
/*
这道题首先建立HuffmanTree[2*N-1],然后根据权值建立最小堆，针对取出的最小元素
找出相应的树节点，然后建立新的结点并把此节点并入HuffmanTree[2*N-1]中，把权值插入
最小堆中,重复循环
*/
HuffmanTree Buildhuffman(Heap H)
{
	HuffmanTree T;
	Buildheap(H);//建立最小堆；
	int i,N;
	N=H->size;
	for(i=1;i<N;++i)//N个元素做N-1次合并
	{

	}
}

/*集合及其运算*/
/*集合采用并查集*/
#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */

void Union( SetType S, SetName Root1, SetName Root2 )
{ /* 这里默认Root1和Root2是不同集合的根结点 */
    /* 保证小集合并入大集合 */
    if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
        S[Root2] += S[Root1];     /* 集合1并入集合2  */
        S[Root1] = Root2;
    }
    else {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
    }
}
 
SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
    if ( S[X] < 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* 路径压缩 */
}
