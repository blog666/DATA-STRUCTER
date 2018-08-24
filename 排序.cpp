/*
大纲：
排序算法的优良性要从时间复杂度，空间复杂度，和稳定性三方面考虑

1.插入排序
1)简单插入排序
2)希尔排序

2.交换排序
1)冒泡排序
2)快速排序

3.选择排序
1)简单选择排序
2)堆排序

4.归并排序

5.基数排序

6.排序算法知识点小结

*/

/*1.插入排序*/

/*简单插入排序*/

/*算法描述：简单插入排序就像打牌一样，
每次拿新的牌就逐一和前面比较，遇到合适的
位置就插入进去*/

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


/*希尔排序*/

/*希尔排序的原理是在简单插入排序的基础上，
设置一个增量，使得每隔几个位置排次序,这里还是
采用传统的希尔增量
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

/*2.交换排序*/

/*冒泡排序*/

/*
冒泡算法的思想是
相邻两个序列间两两比较从而把大的数浮到最后
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

/*上述算法的缺陷是缺少判断功能，即当一个算法有序时，
程序并不知道从而会继续执行下去，所以应增加判断
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

/*快速排序*/
/*算法思想
快速排序的思想本质是交换，首先找到一个待比较的主元，然后把比他小的
放在它左边，比他大的放在它右边，接着递归处理主元左右两个序列，关于主元的
选取可以选最中间元素和两边元素的中位数
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

/*3.选择排序*/

/*简单选择排序*/

/*简单选择排序的思想是每次选择最小的
与待排无序序列的第一个交换
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

void Percedown(int A[],int root,int size)//从下标0开始存储
{
	int child,parent;
	for(parent=root;(parent*2+1)<=size-1;parent=child)
	{
		child=parent*2+1;
		if(child+1<size&&A[child+1]>A[child])child++;//出错点1
		if(A[root]>A[child])break;//出错点2，过程是下滤X，应拿x比较，如果把A[root]换成A[parent]，见下
		else A[parent]=A[child];
	}
	A[parent]=A[root];
}


void Percedown(int A[],int root,int size)//从下标0开始存储
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

/*归并排序*/
/*算法思想
常见的归并排序是二路归并排序，主要思想是把数组分成若干份，两两
归并
*/

void Merge(int A[],int left,int mid,int right)
{/*算法思想为左右两部分单独保存，然后调用常见的merge函数*/
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


/*基数排序*/

/*算法思想
基数排序可以归纳为多关键字排序和桶排序
比如给定100，156，489,897,002这几个数，
可以先对个位排序，把个位相同的排到一起，
再对十位排序，把十位相同的按顺序排到一起，
再对百位排序，把百位相同的排到一起，
注意从桶中抽出时要满足先进先出的顺序
*/

/*
6.排序算法知识点小结
/*
1）平均时间复杂度：快些以nlog2n速度归队（快：快速排序，些：希尔排序，归：归并排序，队：堆排序）
其他都是n的平方
2）最坏情况下：快排最坏情况下是n的平方，其他情况与平均情况相同
3）空间复杂度：快速排序：需要递归，为O(log2n),归并排序：需要辅助空间，O（n），基数排序O（rd),
其他都是O（1)
4)稳定性总结：希尔排序，快速排序，堆排序，简单选择排序（快些选一堆好友）
/*