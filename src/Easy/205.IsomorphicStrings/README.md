###判断两个字符串是否是同构  
	同构 即可以建立一个一一映射，使得这两个字符串通过该映射互相转换  

	“扫两遍” 建一个长度为256（实际上相当于用两个128长度的即可）数组保存映射有没有建立过  

```cpp
int mp[256] = {0};
for (int i=0; i<s.size(); ++i) {
    // if () return false;
    if (mp[int(s[i])] == 0) mp[int(s[i])] = int(t[i]);
    else {
        if (mp[int(s[i])] != int(t[i])) return false;
    }
}

for (int i=0; i<s.size(); ++i) {
    // if () return false;
    if (mp[int(t[i])+128] == 0) mp[int(t[i])+128] = int(s[i]);
    else {
        if (mp[int(t[i])+128] != int(s[i])) return false;
    }
}
// 这两段for循环可以合在一起
return true;
```
