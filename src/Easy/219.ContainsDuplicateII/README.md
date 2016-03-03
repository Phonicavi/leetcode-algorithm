###问有没有连续k及以内的数中出现过重复  
	类比ContainsDuplicate这个题 用unordered_set  

```cpp
unordered_set<int> mp;
for (int i=0; i<nums.size(); ++i) {
    if (i > k) mp.erase(nums[i-k-1]);
    if (mp.find(nums[i]) != mp.end()) return true;
    mp.insert(nums[i]);
}
return false;
```

	当遍历超过k个时 开始删东西，用mp.erase(nums[i])  