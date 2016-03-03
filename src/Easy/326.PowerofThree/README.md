###快速判断一个数是不是3的幂  
	我只想出来了递归方法 就是不断除  

```cpp
if (n == 1) return true;
if (n <= 0) return false;
return n%3 ? false : isPowerOfThree(n/3);
```

###非递归 无loop的方法是用log  

```cpp
// log3(n) = log10(n)/log10(3)
return fmod(log10(n)/log10(3), 1)==0;
// fmod(float x, float y)
// return x - n*y; // n = [x/y]
// 即 假设n是3^k, 用log10(n)/log10(3)取出k 检查k是不是一个整数
```
