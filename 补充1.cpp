/*PTA-���������ת
�ӽṹ�ĽǶȿ����㷨������
��������next��ͷ�ı䷽��
ͬʱ����ǰ���׽��ǰ���NULL���
*/

List Reverse( List L )
{
	List p,q,front;//frontָ��pǰ�Ľ�㣬qָ��p��Ľ��
	p=L;
	front=NULL;
	while(p)
	{
		q=p->Next;
		p->Next=front;
		front=p;
		p=q;
	}
	L=front;//frontָ�����Ľ�㣬����ת���ͷ���
	return L;
}


/*PTA-˳���Ĳ���
bool Insert( List L, ElementType X, Position P )��
��X������λ��P������true��
���ռ����������ӡ��FULL��������false��
�������Pָ��Ƿ�λ�ã����ӡ��ILLEGAL POSITION��������false��

���ʱ����Ҫ������ĿҪ���д�ж�˳������Ҫ�жϿռ��Ƿ�������
�Ƿ�λ��p>L->last+1,��Ϊp���п��ܲ���L->last֮��
*/

/*PTA-��ʽ��İ���Ų���
ע�����浥����һ��û��ͷ���
�������õ��㷨˼���Ƕ���ȷ�����Ψһ���ǣ���������ͳһ����error
*/
while(L)
{
	++i;
	if(i==k)return L->data;
	l=l->next;
}

/*PTA-�������-��ǿ��
����������ı����Ǵ����ӷ����۲��ʽ�ı���
                   A
		          AA
				 AAA
				AAAA
��˿��������ݱ���ÿ��λ�ϵĽ���������ô����ӷ��еĽ�λ֪ʶ���
*/
for(int i=0;i<N;++i)arr[i]=(N-i)*A;//����ÿһλ�Ľ��
while(arr[j]!=0)//arr�����ʼ��Ϊ0
{
	arr[j+1]+=arr[j]/10;
	arr[j]=arr[j]%10;
	++j;
}


