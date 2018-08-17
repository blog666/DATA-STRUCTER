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

