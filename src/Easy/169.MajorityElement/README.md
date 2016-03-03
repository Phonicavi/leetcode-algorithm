###快排输给了投票  
	快排 使整个数组从小到大，再定两个指针（初始化为0和n/2+1）  
	同时步进两个指针 如果两个指针指向的值相同 则这个值就是major  


###波义耳-摩尔投票法  
	原理：同时去掉两个不同的数 则剩余数组里大于一半的数依然是这个数  

```cpp
// 选择第一个位置当作major
int major = nums[0];
int count = 1;

// Boyer-Moore Majority Vote
for (int i=1; i<nums.size(); ++i) {
	if (nums[i]==major) {
		count++;
	} else if (count==0) {
		// 舍掉前面这段(相当于递归) 从当前这个位置重新算起
		major = nums[i];
		count = 1;
	} else count--;
}

return major;
```
