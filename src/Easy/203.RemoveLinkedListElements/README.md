###删除链表中特定值的结点  
	返回时要注意 如果头结点被删除是不能返回head的  
	可以用一个暂时的头HD  

```cpp
// 两个临时指针 pre tmp
// pre = &HD, tmp = pre->next
while (tmp) {
	if (tmp->val == val) {
		pre->next = tmp->next;
		delete tmp;
		tmp = pre->next;
	} else {
		pre = tmp;
		tmp = tmp->next;
	}
}
```

	指针操作要注意顺序  


###优雅的递归方法  
	性能貌似没有前者快  

	函数递归 返回一个剔除了val的剩余链表的头结点  
	只需要看head结点的值是否是要剔除的val 如果是则返回head的next给上一级，不是则返回head给上一级  

```cpp
if (head == NULL) return head;
head->next = removeElements(head->next, val);
return head->val == val ? head->next : head;
```
