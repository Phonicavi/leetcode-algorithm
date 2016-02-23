###最先想出来的方法  
	因为才做了206.ReverseLinkedList 所以想用一下递归的方法，翻转一遍这个链表  
	由于翻转是把原来的链表拿来了，所以做之前要先复制一份  

```cpp
// 复制一份head 申请新的空间 保存为org
// 用先前的recursive方法翻转这个org 得到反向的anti  
// 用head和anti前进比较 有不同就返回false（如果最后都相同返回true）
```

	显然这不是最好的方法  



###翻转一半列表的方法   
	时间效率有了比较大的提升  
	主要技巧是 ***快速找到未知长度的链表*** 的中点  

```cpp
ListNode *s, *f; // s:slow, f:fast
s = f = head;
while (f&&f->next) { // 当fast或fast->next悬空时停住
	s = s->next;
	f = (f->next)-next;
}
// “快慢指针法” 每次slow前进一位 fast前进两位（所以fast指针一定挺在奇数位）

if (f) { // 说明f不为空 而f->next为空 所以f正好停留在最后一位，且说明整个链表有奇数(设2k+1)个结点
	s->next = reverseList(s->next); // 此时s应该正好停留在正中间 即第k+1位，将后k个结点翻转 并把s->next赋成这个翻转后的半段
	s = s->next;
	// now 'head' is the first one of the first k nodes, 's' is the first one of the last k nodes
} else { // 说明f和f->next均为空，说明整个链表有偶数个(设2k)个结点 且s在第k+1位即后k个结点的第一位
	s = reverseList(s); // 直接翻转后半段
}


// 剩下只要从head和s开始往后比较就好了

```
