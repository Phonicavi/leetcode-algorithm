###DP  
	求一个字符串里 最长的没有重复字母的连续子串的长度  
	hashmap[s[i]]表示s[i]这个字符串最近一次出现的位置-->每次循环时更新hashmap[s[i]] = i;  
	
	保持开始下标j 和结束下标i之间没有重复字母 很有技巧....  
	j = max(hashmap[s[i]]+1, j);
	// 如果一直出现新的字母 则由于hashmap初始化为-1 所以j可以一直保持不变
	// 一旦出现重复的字母 则此时 hashmap[s[i]] （记为k）、当前位置i、上一次开始的位置j  
			// 此时"...k, k+1... ...i..." k和i位都是同一个字母，则j要从较前的这个位置的后一位 也就是k+1位重新开始   
	可以表示为  

```cpp
j = 0;
for (int i=0; i<n; ++i) {
	if (isRepeated(s[i])) { // 出现过了
		j = lastPosi[s[i]]+1;
	} else { // 没出现过
		// j = j;
		addToHashmap(s[i]);
	}
	max_length = max(max_length, i-j+1);
	lastPosi[s[i]] = i;
}
```
