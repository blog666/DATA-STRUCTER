/*
��٣�
�����㷨��������Ҫ��ʱ�临�Ӷȣ��ռ临�Ӷȣ����ȶ��������濼��

1.��������
1)�򵥲�������
2)ϣ������

2.��������
1)ð������
2)��������

3.ѡ������
1)��ѡ������
2)������

4.�鲢����

5.��������

6.�����㷨֪ʶ��С��

*/

/*1.��������*/

/*�򵥲�������*/

/*�㷨�������򵥲�������������һ����
ÿ�����µ��ƾ���һ��ǰ��Ƚϣ��������ʵ�
λ�þͲ����ȥ*/

void Insertion(int A[],int N)
{
	int temp,i,j;
	for(i=1;i<N;++i)
	{
		temp=i;
		for(j=temp;j>0&&A[j-1]>A[temp];j--)
			A[j]=A[j-1];
		A[j]=A[temp];
	}
}


/*ϣ������*/

/*ϣ�������ԭ�����ڼ򵥲�������Ļ����ϣ�
����һ��������ʹ��ÿ������λ���Ŵ���,���ﻹ��
���ô�ͳ��ϣ������
*/

void Shellsort(int A[],int N)
{
	int temp,i,P,gap;
	for(gap=N/2;gap>0;gap=gap/2)
	{

		for(P=gap;P<N;++P)
		{
			temp=P;
			for(i=temp;i>=gap&&A[i-gap]>A[temp];i=i-gap)
			{
				A[i]=A[i-gap];
			}
			A[i]=A[temp];
		}
	}
}

/*2.��������*/

/*ð������*/

/*
ð���㷨��˼����
�����������м������ȽϴӶ��Ѵ�����������
*/

void bubblesort(int A[],int N)
{
	int i,j;
	for(i=N-1;i>0;--i)
	{
		for(j=0;j<i;++j)
		{
			if(A[j]>A[j+1])swap(&A[j],&A[j+1]);
		}
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/*�����㷨��ȱ����ȱ���жϹ��ܣ�����һ���㷨����ʱ��
���򲢲�֪���Ӷ������ִ����ȥ������Ӧ�����ж�
*/
void bubblesort(int A[],int N)
{
	int i,j;
	bool flag=false;
	for(i=N-1;i>0;--i)
	{
		for(j=0;j<i;++j)
		{
			if(A[j]>A[j+1])swap(&A[j],&A[j+1]);
			flag=true;
		}
		if(flag==false)break;
	}
}

/*��������*/
/*�㷨˼��
���������˼�뱾���ǽ����������ҵ�һ�����Ƚϵ���Ԫ��Ȼ��ѱ���С��
��������ߣ�������ķ������ұߣ����ŵݹ鴦����Ԫ�����������У�������Ԫ��
ѡȡ����ѡ���м�Ԫ�غ�����Ԫ�ص���λ��
*/

int Median3(int A[],int left,int right)
{
	int mid=(left+right)/2;
	if(A[right]>=A[left])
	{
		if(A[left]>=A[mid])return A[left];
		else{
			if(A[right]>=A[mid])return A[mid];
			else return A[right];
		}
	}
	else
	{
		if(A[right]>=A[mid])return A[right];
		else{
			if(A[left]>=A[mid])return A[mid];
			else return A[left];
		}
	}
}


void Qsort(int A[],int left,int right)
{
	int low,high,pivot;
	pivot=Median3(A,left,right);
	swap(&A[right],&pivot);
	low=left,high=right-1;
	while(low<high)
	{
		while(A[low]<pivot)low++;
		while(A[high]>pivot)high--;
		if(low<high)swap(&A[low],&A[high]);
	}
	swap(&A[low],&A[right]);
	Qsort(A,left,low-1);
	Qsort(A,low+1,high);
}


void quicksort(int A[],int N )
{
	Qsort(A,0,N-1);
}

/*3.ѡ������*/

/*��ѡ������*/

/*��ѡ�������˼����ÿ��ѡ����С��
������������еĵ�һ������
*/

void selectsort(int A[],int N)
{
	int min,i,j;
	for(i=0;i<N-1;++i)
	{
		min=i;
		for(j=i+1;j<N;++j)
		{
			if(A[j]<A[min])min=j;
		}
		swap(&A[i],&A[min]);
	}
}

void Heapsort(int A[],int N)
{
	int i,j;
	for(i=N/2-1;i>=0;--i)
	{
		Percedown(A,i,N);
	}
	for(i=N-1;i>0;--i)
	{
		swap(&A[i],&A[0]);
		Percedown(A,0,i);
	}
}

void Percedown(int A[],int root,int size)//���±�0��ʼ�洢
{
	int child,parent;
	for(parent=root;(parent*2+1)<=size-1;parent=child)
	{
		child=parent*2+1;
		if(child+1<size&&A[child+1]>A[child])child++;//�����1
		if(A[root]>A[child])break;//�����2������������X��Ӧ��x�Ƚϣ������A[root]����A[parent]������
		else A[parent]=A[child];
	}
	A[parent]=A[root];
}


void Percedown(int A[],int root,int size)//���±�0��ʼ�洢
{
	int child,parent,temp;
	for(parent=root;(parent*2+1)<=size-1;parent=child)
	{
		child=parent*2+1;
		if(child+1<size&&A[child+1]>A[child])child++;
		if(A[parent]>A[child])break;
		else {
			temp=A[child];
			A[child]=A[parent];
			A[parent]=temp;
		}
	}
}

/*�鲢����*/
/*�㷨˼��
�����Ĺ鲢�����Ƕ�·�鲢������Ҫ˼���ǰ�����ֳ����ɷݣ�����
�鲢
*/

void Merge(int A[],int left,int mid,int right)
{/*�㷨˼��Ϊ���������ֵ������棬Ȼ����ó�����merge����*/
	int i=0,j=0,k=0,n1,n2,*L1,*L2;
	n1=mid-left+1;
	n2=right-mid;
	L1=(int *)malloc(n1*sizeof(int));
	L2=(int *)malloc(n2*sizeof(int));
	for(int i=0;i<n1;++i)L1[i]=A[left+i];
	for(int i=0;i<n2;++i)L2[i]=A[mid+1+i];
	while(i<n1&&j<n2)
	{
		if(L1[i]>L2[j])
		{
			A[k]=L1[j];
			++k;
			++j;
		}
		else if(L1[i]<=L2[j])
		{
			A[k]=L2[i];
			++k;
			++i;
		}
	}
	while(i<n1)A[k++]=L1[i++];
	while(j<n2)A[k++]=L2[j++];
	
}

void Msort(int A[],int left,int right)
{
	int mid=(left+right)/2;
	if(left<right)
	{
		Msort(A,left,mid);
		Msort(A,mid+1,right);
		Merge(A,left,mid,right);
	}
}

void Mergesort(int A[],int N)
{
	Msort(A,0,N-1);
}


/*��������*/

/*�㷨˼��
����������Թ���Ϊ��ؼ��������Ͱ����
�������100��156��489,897,002�⼸������
�����ȶԸ�λ���򣬰Ѹ�λ��ͬ���ŵ�һ��
�ٶ�ʮλ���򣬰�ʮλ��ͬ�İ�˳���ŵ�һ��
�ٶ԰�λ���򣬰Ѱ�λ��ͬ���ŵ�һ��
ע���Ͱ�г��ʱҪ�����Ƚ��ȳ���˳��
*/

/*
6.�����㷨֪ʶ��С��
/*
1��ƽ��ʱ�临�Ӷȣ���Щ��nlog2n�ٶȹ�ӣ��죺��������Щ��ϣ�����򣬹飺�鲢���򣬶ӣ�������
��������n��ƽ��
2�������£�������������n��ƽ�������������ƽ�������ͬ
3���ռ临�Ӷȣ�����������Ҫ�ݹ飬ΪO(log2n),�鲢������Ҫ�����ռ䣬O��n������������O��rd),
��������O��1)
4)�ȶ����ܽ᣺ϣ�����򣬿������򣬶����򣬼�ѡ�����򣨿�Щѡһ�Ѻ��ѣ�
/*