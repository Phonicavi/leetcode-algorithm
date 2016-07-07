###找两个array的交集 和349题一样 只不过不用去除重复  
    
    sort & scan  


```cpp

sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
vector<int> inter;
int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
while (i < m && j < n) {
    if (nums1[i] < nums2[j]) ++i;
    else if (nums1[i] > nums2[j]) ++j;
    else {
        inter.push_back(nums1[i]);
        ++i;
        ++j;
    }
}
return inter;

```
