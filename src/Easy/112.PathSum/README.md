###判断二叉树是否存在一条根到叶的路径 结点和等于sum  
	注意sum没说正负 所以不用管大小 不用剪枝提前结束  
	判断一下root是否为空 root是不是叶结点（左右子树是不是都已经空了）  
	递归左右子树时传入sum-(root->val)  