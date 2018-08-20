/*ɢ�в���
һ��ɢ�к����Ĺ��췽��
1��ֱ�Ӷ�ַ��
2������������
3�����ַ�����
4��ASCII����ӷ�
5��ǰ�����ַ���λ��
6����λ��
���������ͻ�ķ���
1�����Ŷ�ַ��
1)����̽�ⷨ
2)ƽ��̽�ⷨ
3)˫ɢ��̽�ⷨ
2���������ӷ�
*/

/*���ŵ�ַ������������*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAXTABLESIZE 10000 //���ɢ�б�������
typedef int ElementType;
typedef int Index; 
typedef Index Position;
typedef enum {Legitimate,Empty,Deleted}EntryType;
typedef struct Cell
{
	ElementType data;
	EntryType Info;
}Cell;
typedef struct Hashnode
{
	int TableSize;
	Cell *Cells;
}Hashnode,*HashTable;

/*���Ŷ�ַ���ĳ�ʼ������*/
HashTable CreatTable(int Tablesize)
{
	HashTable H;
	H=(HashTable)malloc(sizeof(Hashnode));
	H->TableSize=NextPrime(Tablesize);
	H->Cells=(Cell *)malloc(H->TableSize*sizeof(Cell));
	for(int i=0;i<H->TableSize;++i)
	{
		H->Cells[i].Info=Empty;
	}
	return H;
}

int NextPrime(int N)//�˺�����������Ѱ�Ҵ���N����С����
{
	int i,p=(N%2)?N+2:N+1;
	while(p<=MAXTABLESIZE)
	{
		for(i=(int)sqrt(double(p));i>2;--i)
		{
			if(p%i==0)break;
		}
		if(i==2)break;
		else p+=2;
	}
	return p;
}

/*ƽ��̽�ⷨ�Ĳ��Һ���*/
Position Find(HashTable H,ElementType Key)
{
	Position Newpos,Currentpos;
	int flag=0,N_add=1,N_sub=1;
	Newpos=Currentpos=Hash(H->TableSize,Key);
	while(H->Cells[Newpos].data!=Key&&H->Cells[Newpos].Info!=Empty)
	{
		if(flag==0)
		{
			++flag;
			Newpos=Currentpos+N_add*N_add;
			if(Newpos>=H->TableSize)Newpos=Newpos%H->TableSize;
			N_add++;
		}
		else
		{
			--flag;
			Newpos=Currentpos-N_sub*N_sub;
			while(Newpos<0)Newpos=Newpos+H->TableSize;
			N_sub++;
		}
	}
	return Newpos;
}


bool Insert(HashTable H,ElementType Key)
{
	Position p=Find(H,Key);
	if(H->Cells[p].Info!=Legitimate)
	{
		H->Cells[p].Info=Legitimate;
		H->Cells[p].data=Key;
		return true;
	}
	else 
	{
		printf("��ֵ�Ѵ���");
		return false;
	}
}

/*�������ӷ�*/
#define Keylength 15
typedef char Elementtype[Keylength+1];
typedef int Index;

typedef struct Lnode
{
	Elementtype data;
	struct Lnode *Next;
}Lnode,*PtrToLnode;

typedef PtrToLnode List;
typedef PtrToLnode Position;

typedef struct Tblnode
{
	int TableSize;
	List theList;
}Tblnode,*HashTable;

Position Find(HashTable H,Elementtype Key)
{
	Index  p;
	Position newpos,oldpos;
	p=Hash(H->TableSize,Key);
	newpos=oldpos=H->theList[p].Next;
	while(newpos&&strcmp(newpos->data,Key))newpos=newpos->Next;//�˴�����ע�⣬�ַ�ֻ����strcmp�Ƚ�
	return newpos;
}

bool Insert(HashTable H,Elementtype Key)
{
	Index pos;
	Position p,NewCell;
	p=Find(H,Key);
	pos=Hash(H->TableSize,Key);
	if(p==NULL)
	{
		NewCell=(Position)malloc(sizeof(Lnode));
		strcpy(NewCell->data,Key);
		NewCell->Next=NULL;
		NewCell->Next=H->theList[pos].Next;
		H->theList[pos].Next=NewCell;
		return true;
	}
	else
	{
		printf("�Ѵ���");
		return false;
	}
}
