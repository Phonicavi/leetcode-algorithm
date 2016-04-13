###交换链表的两两相邻结点 返回新的头指针  
隐藏条件是链表为空或者只有一个 则直接返回、链表长度为奇数的话最后一个不用管  

需要同时四个指针协作: ppre -> pre -> cur -> nxt  
	初始时ppre是NULL 结尾时nxt可能是NULL 需要判断  
	每次操作是:  
		if (ppre!=NULL) ppre->next = cur  
		pre->next = nxt  
		cur->next = pre  
		// 此时的顺序是 ppre -> cur -> pre -> nxt  
		ppre = pre  
		随后转入下一次循环 循环前判断nxt和nxt->next是否是NULL  
		(是的话就说明结束了 直接跳出)  