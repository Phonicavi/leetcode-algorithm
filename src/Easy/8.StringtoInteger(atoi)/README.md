###注意判断溢出  
	res = res*10+(str[i]-'0') 这时res可能会溢出  
	要在每一次while循环里判断res是否溢出 溢出就提前return掉  