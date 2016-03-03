###合并两个已经排序好的数组  
	其实上就是归并操作  

	如果利用递归 可以写出更简洁的方法  

```cpp
// 有空则返回另一条
if (l1 == NULL) return l2;
if (l2 == NULL) return l1;

// 均不空则比较头结点的值 
// 由于函数返回两个归并后的链表的头 所以将较小的那一条的第二个结点和另一条去归并 返回的值赋给原先较小的那个头
if (l1->val <= l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
} else {
    l2->next = mergeTwoLists(l2->next, l1);
    return l2;
}
```