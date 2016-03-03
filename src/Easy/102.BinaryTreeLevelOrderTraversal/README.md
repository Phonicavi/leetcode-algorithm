###层次遍历二叉树  
	用递归 包裹一个函数 需要添加一个记录层级的int  
	如果到访了的层数 level 和当前A的size相等，说明没有开新的[] 所以先在A中添加一个空vector  

		A.push_back(vector<int>());  

	把root的val添加到A[level]的这个vector里，随后递归处理root的左右子树（注意height+1）  