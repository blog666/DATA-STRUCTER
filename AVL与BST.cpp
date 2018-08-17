/*����ƽ����
����ƽ�����Ļ����Ƕ�������������Ҫ����ÿ������ƽ�����ӵľ���ֵС�ڻ����1��
ƽ�����������Ҫ�Ĳ����ǲ�����������Բ��������Ĳ�ƽ���������ת������������
��Ϊ�������ҵ���������˫��������˫��������˫���������Էֽ�Ϊ��������������
��������˫�����Էֽ�ΪB�����ҵ�����A����������
*/
/*
��ƽ������������Ĳ�������Ƚϸ��ӵģ����ʱ��Ҫ����ģ�黯���˼�룬���������ģ�黯��
�Ӷ�ʹ�ñ������
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
�������������ֳƶ�������������ָ����һ���ڵ������С�������Һ��Ӵ�������

������������Ϊ���������ɾ������

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
/*�����������ǿ�ʱ��ɾ�������Ĳ���Ϊ���ҵ��������е��������������е���С�ڵ�
������ڵ������ڵ㣬��ɾ��������
*/
BinTree Delete(BinTree BST,int x)
{
	BinTree TMP;
	if(!BST)
	{
		printf("Ҫɾ����Ԫ��δ�ҵ�");
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