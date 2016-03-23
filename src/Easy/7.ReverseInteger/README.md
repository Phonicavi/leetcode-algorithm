###对一个整数快速翻转操作（也可以用于判断是否是回文串）  
	注意可能会溢出 要先用long接着 溢出(大于INT_MAX或小于INT_MIN 则返回0)  

```cpp
long long reverse = 0;
while (x) {
	reverse = reverse*10 + x%10;
	x /= 10;
}
```