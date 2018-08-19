/*
PTA-是否是二叉搜索树
算法描述：
对给定的二叉树进行中序遍历，
如果当前节点小于它的前驱节点，则该二叉树
不是二叉搜索树
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
PTA--做题的细节
如这个语句，while(newpos&&strcmp(newpos->data,key))这是正确语句,
但把newpos与strcmp一交换就一直显示段错误
原因是newpos存在空指针的情况，如果strcmp放在前面则newpos->data则是段错误
所以先要判断指针是否为空，不为空的情况下再判断其值是否相等，先来后到要分清白
*/