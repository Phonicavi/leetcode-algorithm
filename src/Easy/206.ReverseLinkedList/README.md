###迭代实现  
	两个指针协作 一个curr在前一个tmp在后，再用一个nxt暂时保留tmp->next  
	依次执行：

```cpp
tmp->next = curr;
curr = tmp;
tmp = nxt;
```

	在tmp为NULL时跳出循环，并把最后的`tmp->next = curr;`补上，返回tmp即可  

###递归实现  
	认为函数reverseList(ListNode* head)返回的是以head为输入的链表反转后的新的head  

```cpp
remain = head->next;
ListNode *ans = reverseList(remain);
// 剩下要做的只是把新处理好的部分和head连起来
remain->next = head;
head->next = NULL;
```
	
	最终返回ans即可  