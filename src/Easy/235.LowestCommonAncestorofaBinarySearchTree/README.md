###因为是排序树 所以帮了大忙了  
	考虑到Binary Search Tree(BST)的特点 一定有  
		`(root->left)->val < root->val && root->val < (root->right)->val`  
	所以如果要找的p值和q值均小于根值 则递归左子树，均大于根值 则递归右子树  
	有相等时说明其中一个是另一个的根 则直接返回root  

可以有recursive和iterative两种做法  