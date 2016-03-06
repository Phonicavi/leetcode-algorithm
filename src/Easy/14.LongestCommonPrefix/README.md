###找出一堆字符串的公共prefix  
	给了一个字符串的数组  

```cpp
string prefix = "";
for (int j=0; j<strs[0].size(); prefix+=strs[0][j++]) {
    for (int i=1; i<strs.size(); ++i) {
        if (j >= strs[i].size()||strs[i][j] != strs[i-1][j]) return prefix;
    }
}
return prefix;
```

	因为公共开头一定也是第一个string的开头，所以从第一个string上取字符  
	每拿到一个字符 都会去strs的后续string中检查是否符合  