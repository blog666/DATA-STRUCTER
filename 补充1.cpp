/*PTA-单链表的逆转
从结构的角度考虑算法，就是
把这个表的next箭头改变方向
同时把以前的首结点前添加NULL结点
*/

List Reverse( List L )
{
	List p,q,front;//front指向p前的结点，q指向p后的结点
	p=L;
	front=NULL;
	while(p)
	{
		q=p->Next;
		p->Next=front;
		front=p;
		p=q;
	}
	L=front;//front指向最后的结点，即逆转后的头结点
	return L;
}


/*PTA-顺序表的操作
bool Insert( List L, ElementType X, Position P )：
将X插入在位置P并返回true。
若空间已满，则打印“FULL”并返回false；
如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false；

编程时首先要按照题目要求编写判断顺序，首先要判断空间是否已满；
非法位置p>L->last+1,因为p仍有可能插在L->last之后
*/

/*PTA-链式表的按序号查找
注意浙大版单链表一般没有头结点
此题运用的算法思想是对正确的情况唯一考虑，错误的情况统一返回error
*/
while(L)
{
	++i;
	if(i==k)return L->data;
	l=l->next;
}

/*PTA-数列求和-加强版
分析：此题的背景是大数加法，观察加式的背景
                   A
		  AA
	         AAA
因此可以用数据保存每个位上的结果，再利用大数加法中的进位知识求解
*/
for(int i=0;i<N;++i)arr[i]=(N-i)*A;//保存每一位的结果
while(arr[j]!=0)//arr数组初始化为0
{
	arr[j+1]+=arr[j]/10;
	arr[j]=arr[j]%10;
	++j;
}


