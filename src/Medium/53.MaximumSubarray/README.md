###DP  
	相当于动态规划，遍历一遍数组即可 用一个数tmp_sum保存当前第i个位置之前的所有数之和  
	如果tmp_sum小于0了 则把tmp_sum重置为0  
	（理解成要找一首一尾夹着的一段，当tmp_sum小于0时 说明舍弃前面这段反而会增大总和 果断舍弃）  

```cpp
int ans = nums[0];
int n = nums.size();
int tmp_sum = 0;
for (int i=0; i<n; ++i) {
    tmp_sum += nums[i];
    ans = tmp_sum > ans ? tmp_sum : ans;
    tmp_sum = tmp_sum > 0 ? tmp_sum : 0;
}
```
	等价意义的动态规划写法  

```cpp
int n = nums.size();
if (!n) return 0;
else if (n == 1) return nums[0];

int local_sum = nums[0], global_sum = nums[0];/*ans*/
for (int i=1; i<n; ++i) { // 注意这里i必须要从1开始 否则nums[0]会计算两遍
	local_sum = max(local_sum+nums[i], nums[i]);
	global_sum = max(local_sum, global_sum);
}
```
