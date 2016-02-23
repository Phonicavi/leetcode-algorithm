###空间O(1) 时间O(n)  
	在第i的循环中 left表示v[i]以左的所有nums的乘积，right表示v[n-i-1]以右的所有nums的乘积  
	对于数组中的任意第k个 v[k]可以在i=k和i=n-k-1两次被扫到，分别被乘了left和right  

###空间O(n)  
	只是把left right两个数展开成数组  
	left[i]和right[i]分别表示第i位以左和以右的所有nums乘积