/*PTA-˫�˶���
˫�˶��У�deque����double-ended queue
����д����һ�־��ж��к�ջ���ʵ����ݽ�
���������ԣ�Ҳֻ�ܣ������Ա�����˽���
�����ɾ��
����˫�˶��У�����Ҫ��ȷ˫�˶��м�����
��β����ɾ���������ڶ�ͷ����ɾ��������
��ͷָ���Ҫ�ö�ͷָ��ʹ�ã���Ҫ�ö�β
ָ��ʹ�ã�����˫�����á�
�����Ҫע����Ƕ����������жϣ�����һ��
�����Ǹ�������ı������Զ������Ԫ�ؽ���
ͳ�ƣ�����һ����ͨ��(rear-front+maxsize)
%maxsize==maxsize��Ԫ�ظ��������жϣ�
*/

/*
���˫�˶��бȽϹؼ���һ�仰��
��������ʹ����õ�˳��ṹ���洢˫�˶��У�
Ϊ�˽�ʡ�ռ䣬������β����������ѭ�����С�
���ҹ涨leftָ����˵ĵ�һ��Ԫ�أ�right
ָ���Ҷ�ĩβԪ�ص���һ��λ�á���ô�ӿյ��ж���
��left==right��������(left-1+MAX)%MAX==right
����(right-left+MAX)%MAX==MAX��
*/

bool Push( ElementType X, Deque D )
{
	if((D->rear-D->front+D->MaxSize)%D->MaxSize/*������Ԫ�ظ�������*/!=D->Maxsize/*����Ԫ�ظ��������ֵ*/)
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


/*PTA-���ȫ����
������������Ҫ�ֵ���Ļ�,���԰��ո߷ֱʼ���
�ĵݹ鷽��������Ҳ�Ƚ��������
*/
void permute(int str[],int low,int high)
{
	if(low==high)���str����;
	else 
	{
		for(int i=low;i<=high;++i)
		{
			swap(str,i,low);//swap��������
			permute(str,low+1,high);//�ӵ�ǰλ�����εݹ顢
			swap(str,i,low);//�ٴν������س�ʼ״̬
		}
	}
}

/*PTA-���ȫ����
���������c++���Դ���next_permutation,����ͷǳ�������
����algorithm�е�next_permutation����// TEMPLATE FUNCTION next_permutation
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

/*	PTA-�����ջ
�������⣺
ջ������һ��λ��ָ����ջ�ڿռ�λ���ϵ���һ��λ�ã�
Ҳ����ջ��Ԫ�ص���һ��λ��
*/

/*һԪ����ʽ�ĳ˷��ͼӷ�����*/
/* ��������Ҫ��ģ�黯˼����⣬
���ȹ���ReadPoly()������һԪ����ʽ��ϵ��coef��
����ʽ��ϵ��expon���뵽�����ڣ��������Ľṹ����Ϊ
typedef struct PolyNode
{
  int coef;
  int expon;
  struct PolyNode *link;
 }PolyNode,*PolyLink;
 ������PolyRead()�ڲ���ģ�黯�ṹΪ
 { 
    ����ͷ��㣻
	scanf("%d", &N);
    ����
    while ( N-- ) 
	{
    scanf("%d %d", &c, &e);
    Attach(c, e, &Rear);
    }
    ��
    return P;
 }
 ��Attach������Ҫ�ǹ����µĽ��������нڵ�ĺ���
 ��ι���Mult������Add����
 Add�����Ĺ����㷨�����ʽ�Ĺ鲢���ƣ���һɨ����������ʽ��㣬���
 �����½����棬��ȵĻ����ٴ���Ӽ��㡣
 Polynomial Add( Polynomial P1, Polynomial P2 )
{ ����
t1 = P1; t2 = P2;
P = (Polynomial)malloc(sizeof(struct PolyNode)); P->link = NULL;
Rear = P;
while (t1 && t2) {
if (t1->expon == t2->expon) {
��..
}
else if (t1->expon > t2->expon) {
����
}
else {
����
}
}
while (t1) {
����
}
while (t2) {
��..
}
����..
return P;
}

    �ѵ�����ν���������ʽ��ˣ����õ�˼·�ǽ�����һ������
ʽ��ÿһ��������һ������ʽ��ÿһ����ˣ�����forѭ���������
ֱ�����������������������޷�������ʽ��ϵ�����մ������кã���˲�
�õĽ���취����������һ������ʽ�ĵ�һ�����������ʽ��ÿһ�����
��������˳�ʼ���Ķ���ʽ���ֱ�֤�˶���ʽ�Ĵ��������ԡ������߲�������
forѭ����Ѱ�ҵ����ʵĲ���λ�ã�������˺������
  Polynomial Mult( Polynomial P1, Polynomial P2 )
{ ����.
t1 = P1; t2 = P2;
����.
while (t2) { 
����..
}
t1 = t1->link;
while (t1) {
t2 = P2; Rear = P;
while (t2) {
e = t1->expon + t2->expon;
c = t1->coef * t2->coef;
������..
t2 = t2->link;
}
t1 = t1->link;
}
����.
}
*/

/*PAT-��ջ�����Ϸ���
�����ѵ����������⣬ǿ������ĺϷ���
�������������Ϊ
4 10
SSSXXSXXSX
SSSXXSXXS
SSSSSSSSSSXSSXXXXXXXXXXX
SSSXXSXXX
��α�֤10������س���ʱ�س��������ַ�����������Ĺؼ�
��������������getchar()����
����һ��������scanf("%d%d "),ע�����ո�������е�����
��%d��������ո�scanf��һֱ�������п��ַ��������س���
֪�������ַ�������������ıܿ��˻س�����Ӱ�졣
*/
