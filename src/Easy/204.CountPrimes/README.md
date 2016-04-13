###找出小于一个数n的所有质数的个数  
	Sieve of Eratosthenes 算法基本思想：  
		一个数 设为p 不管他是不是质数 它的平方p*p、以上的p*p+p, p*p+2p, p*p+k*p 都不是质数  

	解题思路：  
		上来先假设n以内的所有数都是质数 然后从小往大排除以此推得的合数  
		向上遍历 遇到已经是合数的就可以直接跳过了，遇到之前没判断的（还是初始设定的“都是质数”的这些数 就可以确定真的就是质数了）  