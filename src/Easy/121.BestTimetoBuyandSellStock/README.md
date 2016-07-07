###一个array找出每个元素右边的最大值  
	从右往左动归  
	p[0 ~ len-1]  
	dp[j]表示包括j在内 p[j], ... p[len-1]中的max  

		if p[j-1]<=p[j]:  
			dp[j-1] = dp[j]  
		else:  
			dp[j-1] = max(p[j-1], dp[j])  

	找最大差值的时候只要扫一遍  
		max_profit = 0  
		j = 0:len-1  
		max_profit = max(dp[j]-p[j], max_profit)  

