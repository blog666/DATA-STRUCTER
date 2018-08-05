/*PTA-双端队列
双端队列（deque，即double-ended queue
的缩写）是一种具有队列和栈性质的数据结
构，即可以（也只能）在线性表的两端进行
插入和删除
关于双端队列，首先要明确双端队列既能在
队尾插入删除，又能在队头插入删除，所以
队头指针既要拿队头指针使用，又要拿队尾
指针使用，具有双重作用。
其次需要注意的是队满条件的判断，队满一种
做法是搞个计数的变量，对队里面的元素进行
统计，还有一种是通过(rear-front+maxsize)
%maxsize==maxsize（元素个数）来判断；
*/

/*
理解双端队列比较关键的一句话：
这里我们使用最常用的顺序结构来存储双端队列，
为了节省空间，把它首尾相连，构成循环队列。
并且规定left指向左端的第一个元素，right
指向右端末尾元素的下一个位置。那么队空的判断则
是left==right，队满是(left-1+MAX)%MAX==right
或者(right-left+MAX)%MAX==MAX。
*/

bool Push( ElementType X, Deque D )
{
	if((D->rear-D->front+D->MaxSize)%D->MaxSize/*队列中元素个数的求法*/!=D->Maxsize/*队列元素个数的最大值*/)
	{
		D->front=(D->front-1+D->MaxSize)%D->MaxSize;
		D->data[D->front]=X;
	}
	else return false;
	return true;
}

ElementType Pop( Deque D )
{
    if(D->Rear != D->Front)
    {
        ElementType a = D->Data[D->Front];
        D->Front = (D->Front + 1)%D->MaxSize;
        return a;
    }
    else return ERROR;
}

bool Inject( ElementType X, Deque D )
{
    if((D->Rear - D->Front + D->MaxSize)%D->MaxSize != D->MaxSize - 1)
    {
        D->Data[D->Rear] = X;
        D->Rear = (D->Rear + 1)%D->MaxSize;
    }
    else return false;
    return true;
}
ElementType Eject( Deque D )
{
    if(D->Rear != D->Front)
    {
        D->Rear = (D->Rear - 1 + D->MaxSize)%D->MaxSize;
        ElementType a = D->Data[D->Rear];
        return a;
    }
    else return ERROR;
}


/*PTA-输出全排列
这道题如果不需要字典序的话,可以按照高分笔记上
的递归方法来做，也比较难以理解
*/
void permute(int str[],int low,int high)
{
	if(low==high)输出str数组;
	else 
	{
		for(int i=low;i<=high;++i)
		{
			swap(str,i,low);//swap交换函数
			permute(str,low+1,high);//从当前位置深层次递归、
			swap(str,i,low);//再次交换返回初始状态
		}
	}
}

/*PTA-输出全序列
此题如果用c++中自带的next_permutation,问题就非常容易了
这是algorithm中的next_permutation定义// TEMPLATE FUNCTION next_permutation
template<class _BidIt> inline
	bool _Next_permutation(_BidIt _First, _BidIt _Last)
	{	// permute and test for pure ascending, using operator<
	_BidIt _Next = _Last;
	if (_First == _Last || _First == --_Next)
		return (false);

	for (; ; )
		{	// find rightmost element smaller than successor
		_BidIt _Next1 = _Next;
		if (_DEBUG_LT(*--_Next, *_Next1))
			{	// swap with rightmost element that's smaller, flip suffix
			_BidIt _Mid = _Last;
			for (; !_DEBUG_LT(*_Next, *--_Mid); )
				;
			_STD iter_swap(_Next, _Mid);
			_STD reverse(_Next1, _Last);
			return (true);
			}

		if (_Next == _First)
			{	// pure descending, flip all
			_STD reverse(_First, _Last);
			return (false);
			}
		}
	}*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[20];
	scanf("%d",&n);
	for(int i=0;i<n;++i)a[i]=i+1;
	do
	{
		for(int i=0;i<n;++i)printf("%d",a[i]);
		printf("\n");
	}while(next_permutation(a,a+n));
	return 0;
}

/*	PTA-另类堆栈
题意的理解：
栈顶的上一个位置指的是栈在空间位置上的上一个位置，
也就是栈顶元素的下一个位置
*/

/*一元多项式的乘法和加法运算*/
/* 这种题需要用模块化思想解题，
首先构造ReadPoly()函数将一元多项式的系数coef和
多项式的系数expon插入到链表内，因此链表的结构定义为
typedef struct PolyNode
{
  int coef;
  int expon;
  struct PolyNode *link;
 }PolyNode,*PolyLink;
 而函数PolyRead()内部的模块化结构为
 { 
    构造头结点；
	scanf("%d", &N);
    ……
    while ( N-- ) 
	{
    scanf("%d %d", &c, &e);
    Attach(c, e, &Rear);
    }
    …
    return P;
 }
 而Attach函数主要是构造新的结点接在已有节点的后面
 其次构造Mult函数和Add函数
 Add函数的构造算法与多项式的归并类似，逐一扫描两个多项式结点，大的
 接在新结点后面，相等的话就再次相加计算。
 Polynomial Add( Polynomial P1, Polynomial P2 )
{ ……
t1 = P1; t2 = P2;
P = (Polynomial)malloc(sizeof(struct PolyNode)); P->link = NULL;
Rear = P;
while (t1 && t2) {
if (t1->expon == t2->expon) {
…..
}
else if (t1->expon > t2->expon) {
……
}
else {
……
}
}
while (t1) {
……
}
while (t2) {
…..
}
……..
return P;
}

    难点是如何将两个多项式相乘，常用的思路是将其中一个多项
式的每一项与另外一个多项式的每一项相乘，两个for循环解决，但
直接这样操作带来的问题是无法将多项式的系数按照次序排列好，因此采
用的解决办法是先用其中一个多项式的第一项与另外多项式的每一项，这样
及构造好了初始化的多项式，又保证了多项式的次数有序性。紧接者采用两个
for循环，寻找到合适的插入位置，构造相乘后的链表。
  Polynomial Mult( Polynomial P1, Polynomial P2 )
{ …….
t1 = P1; t2 = P2;
…….
while (t2) { 
……..
}
t1 = t1->link;
while (t1) {
t2 = P2; Rear = P;
while (t2) {
e = t1->expon + t2->expon;
c = t1->coef * t2->coef;
………..
t2 = t2->link;
}
t1 = t1->link;
}
…….
}
*/

/*PAT-堆栈操作合法性
此题难点是输入问题，强调输入的合法性
此题的输入样例为
4 10
SSSXXSXXSX
SSSXXSXXS
SSSSSSSSSSXSSXXXXXXXXXXX
SSSXXSXXX
如何保证10后输入回车符时回车符不被字符接纳是问题的关键
有种做法是利用getchar()函数
还有一种做法是scanf("%d%d "),注意此题空格的做法有点巧妙
在%d后面输入空格，scanf会一直忽略所有空字符串包括回车键
知道输入字符，这样就巧妙的避开了回车键的影响。
*/
