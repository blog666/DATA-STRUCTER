#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define Keylength 15
#define Maxlength 80
typedef char ElementType[Keylength+1];
typedef struct Lnode
{
	int count;
	ElementType data;
	struct Lnode *Next;
}Lnode,*PtrToLnode;

typedef PtrToLnode List;
typedef PtrToLnode Position;

typedef struct Hashnode
{
	int TableSize;
	List list;
}Hashnode,*HashTable;


int NextPrime(int N)
{
	int i,p;
	p=(N%2)?N+2:N+1;
	while(p)
	{
		for( i=(int)sqrt(double(p));i>2;--i)
		{
			if(p%i==0)break;
		}
		if(i==2)break;
		else p+=2;
	}
	return p;
}

HashTable CreatTable(int Tablesize)
{
	HashTable H;
	H=(HashTable)malloc(sizeof(Hashnode));
	H->TableSize=NextPrime(Tablesize);
	H->list=(List)malloc(H->TableSize*sizeof(Lnode));
	for(int i=0;i<H->TableSize;++i)
	{
		H->list[i].count=0;
		H->list[i].data[0]='\0';
		H->list[i].Next=NULL;
	}
	return H;
}

int Isword(char ch)
{
	if((ch>='a'&&ch<='z')||ch>='0'&&ch<='9'||ch=='_')return 1;
	else return 0;
}

int Getword(char *&p,ElementType word)
{
	char temp,tempword[Maxlength],len=0;
	temp=*p;
	while(*p!='#')
	{
		if(Isword(temp))tempword[len++]=*p;
		++p;
		temp=*p;
		if(len&&!Isword(temp))break;
	}
	tempword[len]='\0';
	if(len>Keylength)
	{
		tempword[Keylength]='\0';
		len=Keylength;
	}
	strcpy(word,tempword);
	return len;
}

int Hash(ElementType Key,int TableSize)
{
	unsigned int h=0;
	while(*Key!='\0')
	{
		h=(h<<5)+*Key++;
	}
	return h%TableSize;
}


Position Find(HashTable H,ElementType Key)
{
	Position P;
	int pos;
	pos=Hash(Key,H->TableSize);
	P=H->list[pos].Next;
	while(P&&strcmp(P->data,Key))P=P->Next;
	return P;
}
void InsertAndCount(HashTable H,ElementType Key)
{
	Position P,NewCell;
	int pos;
	P=Find(H,Key);
	if(!P)
	{
		NewCell=(Position)malloc(sizeof(Lnode));
		NewCell->count=1;
		strcpy(NewCell->data,Key);
		NewCell->Next=NULL;
		pos=Hash(Key,H->TableSize);
		NewCell->Next=H->list[pos].Next;
		H->list[pos].Next=NewCell;
		H->list[pos].count++;
	}
	else P->count++;
}

void show(HashTable H,double p)
{
	Position temp,L,Ptr[100];
	int transit=0,count_end,k,flag=0,j,diffwordsum=0,count=0,*diffwords,i,Maxcount=0,lowercount;//lowercount代表输出单词的个数,count做统计用
	for(i=0;i<H->TableSize;++i)
	{

		L=H->list[i].Next;
		diffwordsum+=H->list[i].count;
		while(L)
		{
			if(L->count>Maxcount)Maxcount=L->count;
			L=L->Next;
		}
	}
	diffwords=(int *)malloc((Maxcount+1)*sizeof(int));
	for(i=0;i<=Maxcount;++i)diffwords[i]=0;
	for(i=0;i<H->TableSize;++i)
	{
		L=H->list[i].Next;
		while(L)
		{
			diffwords[L->count]++;
			L=L->Next;
		}
	}
	lowercount=int(p*diffwordsum);
	for(i=Maxcount;i>=1;--i)
	{
		count+=diffwords[i];
		if(count>=lowercount)break;
	}
	count_end=i;
	for(j=Maxcount;j>=count_end;--j)
	{
		for(k=0;k<H->TableSize;++k)
		{
			L=H->list[k].Next;
			while(L)
			{
				if(L->count==j)Ptr[flag++]=L;
				L=L->Next;
			}
		}
	}
	for(i=0;i<flag;++i)
	{
		k=i;
		for(j=i+1;j<flag;++j)
		{
			if(Ptr[k]->count<Ptr[j]->count)k=j;
		}
		temp=Ptr[i];
		Ptr[i]=Ptr[k];
		Ptr[k]=temp;
	}
	for(k=Maxcount;k>=count_end;--k)
	{
		for(i=transit;;++i)
		{
			if(Ptr[i]->count==k)
			{
				j=i;
				while(j>0)
				{
					if(strcmp(Ptr[j]->data,Ptr[j-1]->data)<0)
					{
					temp=Ptr[j];
					Ptr[j]=Ptr[j-1];
					Ptr[j-1]=temp;
					}
					--j;
				}
			}
			else break;
		}
		transit=i;
	}
	for(i=0;i<lowercount;++i)printf("%-15s:%d\n",Ptr[i]->data,Ptr[i]->count);
}
int main()
{
	HashTable H;
	ElementType Word;
	int tablesize=100;
	int i=0,length,wordcount=0;
	char *p,ch,txt[10000]={'\O'};
	H=CreatTable(tablesize);
	while((ch=getchar())!='#')
	{
		if(ch>='A'&&ch<='Z')ch=ch+32;
		if(ch!='\n')txt[i++]=ch;
	}
	p=txt;
	while(*p)
	{
		length=Getword(p,Word);
		InsertAndCount(H,Word);
	}
	show(H,10.0/100);
	return 0;
}