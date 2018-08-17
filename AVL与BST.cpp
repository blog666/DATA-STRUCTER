/*二叉平衡树
二叉平衡树的基础是二叉搜索树，但要满足每个结点的平衡因子的绝对值小于或等于1；
平衡二叉树最重要的操作是插入操作，即以插入后引起的不平衡情况来旋转调整二叉树；
分为左单旋、右单旋、左右双旋和右左双旋，其中双旋操作可以分解为两个单旋操作；
例如左右双旋可以分解为B结点的右单旋和A结点的左单旋。
*/
/*
像平衡二叉树这样的插入操作比较复杂的，编程时就要采用模块化编程思想，将插入操作模块化，
从而使得编程容易
*/


#include<stdio.h>

#include<stdlib.h>

typedef struct AVLnode{
	int data;
	struct AVLnode *left,*right;
	int height;
}AVLnode,*AVLTree;

AVLTree Insert(AVLTree T,int x)
{
	if(!T)
	{
		T=(AVLTree)malloc(sizeof(AVLnode));
		T->data=x;
		T->left=T->right=NULL;
		T->height=1;
	} 
	else if(x>T->data)
	{
		T->right=Insert(T->right,x);
		if(T->left->height-T->right->height==-2)
		{
			if(x>T->right->data)
				T=singleright(T);
			else 
				T=doublerightleft(T);
		}
	}
	else if(x<T->data)
	{
		T->left=Insert(T->left,x);
		if(T->left->height-T->right->height==2)
		{
			if(x<T->left->data)
				T=singleleft(T);
			else
				T=doubleleftright(T);
		}
	}
	T->height=MAX(T->left->height,T->right->height)+1;
	return T;
}

AVLTree  singleright(AVLTree A)
{
	AVLTree B=A->right;
	A->right=B->left;
	B->left=A;
	A->height=MAX(A->left->height,A->right->height)+1;
	B->height=MAX(B->left->height,B->right->height)+1;
	return B;
}

AVLTree  singleleft(AVLTree A)
{
	AVLTree B=A->left;
	A->left=B->right;
	B->right=A;
	A->height=MAX(A->left->height,A->right->height)+1;
	B->height=MAX(B->left->height,B->right->height)+1;
	return B;
}

AVLTree doublerightleft(AVLTree T)
{
	T->right=singleleft(T->right);
	T=singleright(T);
	return T;
}

AVLTree doubleleftright(AVLTree T)
{
	T->left=singleright(T->left);
	T=singleleft (T);
	return T;
}

int MAX(int a,int b)
{
	return a>b?a:b;
}

/*
二叉搜索树，又称二叉排序树，是指任意一个节点的左孩子小于它，右孩子大于它，

二叉搜索树分为插入操作和删除操作

*/
BinTree Insert(BinTree BST,int x)
{
	if(!BST)
	{
		BST=(BinTree)malloc(sizeof(BTnode));
		BST->data=x;
		BST->leftchild=BST->rightchild=NULL;
	}
	else
	{
		if(x<BST->data)Insert(BST->leftchild,x);
		else if(x>BST->data)Insert(BST->rightchild,x);
	}
	return BST;
}
/*当左右子树非空时，删除操作的策略为先找到左子树中的最大结点或右子树中的最小节点
用这个节点代替根节点，再删除这个结点
*/
BinTree Delete(BinTree BST,int x)
{
	BinTree TMP;
	if(!BST)
	{
		printf("要删除的元素未找到");
	}
	else 
	{
		if(x<BST->data)Delete(BST->left,x);
		else if(x>BST->data)Delete(BST->right,x);
		else
		{
			if(!BST->left&&!BST->right)free(BST);
			else if(BST->left&&BST->right)
			{
				TMP=FindMin(BST->right);
				BST->data=TMP->data;
				BST->right=Delete(BST->right,BST->data);
			}
			else
			{
				if(BST->right)BST=BST->right;
				else BST=BST->left;
			}
		}
	}
}

BinTree FindMin(BinTree T)
{
	if(T)
	{
		while(T->left)T=T->left;
	}
	return T;
} 