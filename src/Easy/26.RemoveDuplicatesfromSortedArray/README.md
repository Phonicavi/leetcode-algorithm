###vector的迭代器iterator  
	c++11 auto关键字可以推断变量类型  

```cpp
auto itr = nums.begin();
```

	相当于  

```cpp
std::vector<int>::iterator itr = nums.begin();
```


###算法  
	两个迭代器 一快一慢  
	快的itr负责遍历完所有的元素 慢的word负责确定实际不重复的元素  
	检查(*itr > *word)为true说明遇到一个新的元素了，则

```cpp
length+=1;
// 下面两句可以简写为 *(++word) = *itr; 
word++;
*word = *itr;
```



