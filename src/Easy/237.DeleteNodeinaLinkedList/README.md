###注意理解题意 函数传入的node是指向要删除的那个结点的指针  
	由于传的是node 且要删node 所以想法是：  
		- 暂存tmp = node->next  
		- 把tmp的val赋给node的val  
		- 把node的next指针指向tmp->next  
		- 为tmp清空空间  