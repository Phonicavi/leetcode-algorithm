###queue模仿stack  
	queue: FIFO  stack: LIFO  

	为了均摊时间上的尽可能小 我们让push操作时间复杂到O(n) 换来其它操作的O(1)  
		- push: 每次加入一个数后，设当前q.size()为n 则做n-1次旋转操作 使得刚刚加入的队尾的数移动到队头  
		- pop: pop弹出队头  
		- top: 返回q.front()  
		- empty: 返回q.empty()  

注意 push_back() 是vector的操作 不要搞混了  