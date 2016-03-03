###stack模仿queue  
	queue: FIFO  stack: LIFO  

	主要是两个stack 一个in模拟queue的前半部分 一个out模拟queue的后半部分  
	一般地，in的top是queue的队尾 是最后一个放入的元素；out的top是队首 是最先放入的元素  
	四个基本操作：
		- push: 直接向in中push即可  
		- pop: 弹出队首的元素，先检查out是不是empty的 是的话说明元素全都在in里 要先把in中的东西反向倒入out中 再把out的top弹出来，如果out不是empty的 说明前面已经移动过一些了 直接弹出out的top即可  即out.pop()  
		- peek: 返回队首的元素 检查操作和pop一样 只不过最后return out.top()  
		- empty: in和out拼接起来才是整个queue 所以只有当in和out均为空 整个queue才为空  
