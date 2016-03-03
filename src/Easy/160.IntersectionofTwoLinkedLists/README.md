###可能呈'Y'型的两条链表 在一定结点过后连在一起  
	求公共结点的位置 先过一遍得到两条链表长度  
	再根据长度差diff判断哪一条更长 让更长的一条先移动diff个  
	随后开始同时步进两个指针 找到相等时就是共同结点  


###快慢指针  
	先介绍一下快速找到链表环的入口位置的方法  
	- 快慢两个指针  
		slow = fast = head; slow每次进1 fast每次进2  
		slow fast 相遇时停下，将其中一个搬回head  
		再次移动 每次每个都进1 再次相遇时的位置就是loop入口  

	再说如何利用  
	- 将'Y'的末尾衔接到A或B链表的头部，此时交接公共点就是链表的入口了  
	
	其实更简单的  

```cpp
auto *p1 = headA, *p2 = headB;
if (!p1||!p2) return NULL;
while (p1 != p2) {
	p1 = p1->next;
	p2 = p2->next;
	if (p1 == p2) return p1;
	if (p1 == NULL) p1 = headB; // p2
	if (p2 == NULL) p2 = headA; // p1
}
return p1;
```

	- 不妨假设LA < LB 这样p1先走到NULL，此时p1 p2均走了LA步，这时将p1搬运倒headB  
	- 之后 假设又走了k步 p2也到了NULL，此时p2走了LB步（即LA+k步） 而p1在headB后走了k步，这时将p2搬运倒headA  
	- 看看现在，p1在B链上走了k步 相当于补完了长度差diff 而p2又恰好在A链开头  
	- 之后 只要他们继续都每次步进1 下一次交点就是入口  