###不用 + - 符号做整数加减运算  
	递归处理两部分  
		- a^b 按位异或 不考虑溢出位  
		- a&b 按位和 保留1的就是溢出位: (a&b)<<1 左移一位后就是应该进位的位置  
	当进位部分没有值的时候 说明此时可以用单纯的异或求解了  

```cpp

int getSum(int a, int b) {
	return a?getSum((a&b)<<1, a^b):b;
}

or:

int getSum(int a, int b) {
	return b?getSum(a^b, (a&b)<<1):a;
}

```