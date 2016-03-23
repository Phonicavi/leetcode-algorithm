###二分查找  
	唯一需要注意的地方 就是 mid的取法  
	
		mid = (left+right)/2; // left+right 会溢出  
		mid = left+(right-left)/2;  

	推荐用第二种做法 可以保证不溢出  