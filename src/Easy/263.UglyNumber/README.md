###取商递归  
	Ugly的定义是：  
		- 1是ugly  
		- 非负不考虑 不是ugly  
		- 质因数中没有 2, 3, 5 以外的数 是ugly  

	简单的原理是：  
		- num是5的倍数 => num是ugly 则 num/5也是ugly  
		- num是3的倍数 => num是ugly 则 num/3也是ugly  
		- num是2的倍数 => num是ugly 则 num/2也是ugly  

```cpp
if(num == 0) return false;
while(num%2 == 0) num/=2; // 分解所有 2 这个因数
while(num%3 == 0) num/=3; // 分解所有 3 这个因数
while(num%5 == 0) num/=5; // 分解所有 5 这个因数
return num == 1;
```