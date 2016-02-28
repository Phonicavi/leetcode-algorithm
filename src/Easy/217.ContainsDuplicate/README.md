###无范围哈希 C++ stdlib  
	C++自己的set可以做到 但效率可能不如维护一个专有的数据结构好  

```cpp
bool containsDuplicate1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i=0; i<int(nums.size())-1; i++) {
        if (nums[i]==nums[i+1])
            return true;
    }
    return false;    
}

bool containsDuplicate2(vector<int>& nums) {
    map<int, bool> myMap;
    // unordered_map<int, bool> myMap;
    for (auto& num: nums) {
        if (myMap.find(num) != myMap.end())
            return true;
        else
            myMap[num] = true;
    }
    return false;
}

bool containsDuplicate3(vector<int>& nums) {
    multimap<int, bool> myMap;
    // unordered_multimap<int, bool> myMap;
    for (auto& num: nums) {
        if (myMap.find(num) != myMap.end())
            return true;
        myMap.insert(make_pair(num, true));
    }
    return false;
}

bool containsDuplicate4(vector<int>& nums) {
    set<int> mySet;
    // unordered_set<int> mySet;
    // multiset<int> mySet;
    // unordered_multiset<int> mySet;
    for (auto& num: nums) {
        if (mySet.find(num) != mySet.end())
            return true;
        mySet.insert(num);
    }
    return false;
}
```

```cpp
// 用了一个匿名set
// 方法是给一个set的构造函数传入整个nums数组 利用set维护排去重复的特点
return nums.size() > set<int>(nums.begin(), nums.end()).size(); 
```


###最直接的方法  
	- 直接比较数组中任意两个数 需要O(n^2)时间复杂度和O(1)空间复杂度  
	- 对全部数进行排序 需要至少O(nlogn)时间复杂度和O(1)空间复杂度 之后检查临近两个数是否想等即可  
