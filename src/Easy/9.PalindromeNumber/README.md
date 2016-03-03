###判断一个int x是不是回文  
	取x的后半 倒序赋给一个新的int half  

```cpp
int half = 0;
while (x>half) {
	half = half*10 + x%10;
	x /= 10;
}
```
	
	只要判断`(x == half||x == half/10)`  

