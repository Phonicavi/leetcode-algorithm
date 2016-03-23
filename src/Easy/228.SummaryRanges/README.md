###找出是否是连续整数 给出范围  
	两个指针分别表示head和tail 如果连续(后面的数比前面的数大1就让tail继续前进)  
	如果不连续了就检查head和tail是否已经分离了 分离输出nums[head]->nums[tail]  
	不分离说明这里只有一个数 是一个孤立的点 就输出nums[head]  