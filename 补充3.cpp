/*
PTA-�Ƿ��Ƕ���������
�㷨������
�Ը����Ķ������������������
�����ǰ�ڵ�С������ǰ���ڵ㣬��ö�����
���Ƕ���������
*/

bool isBST(BinTree T)
{
	bool flag1,flag2;
	static int pre=-1;
	if(T==NULL)return true;
	else
	{
		flag1=isBST(T->left);
		if(flag1==false||pre>T->data)return false;
		pre=T->data;
		flag2=isBST(T->right);
		return flag2;
	}
}


/*
PTA--�����ϸ��
�������䣬while(newpos&&strcmp(newpos->data,key))������ȷ���,
����newpos��strcmpһ������һֱ��ʾ�δ���
ԭ����newpos���ڿ�ָ�����������strcmp����ǰ����newpos->data���Ƕδ���
������Ҫ�ж�ָ���Ƿ�Ϊ�գ���Ϊ�յ���������ж���ֵ�Ƿ���ȣ�������Ҫ�����
*/