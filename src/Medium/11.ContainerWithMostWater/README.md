###左右两个指针标识水池的左右壁  
	左右位置left和right初始值置为0和n-1  
	收缩两个边界  
		当靠内侧的左边height 即height[left]比当前高度还小时 继续右移left  
		当靠内侧的右边height 即height[right]比当前高度还小时 继续左移right  
	当两个while循环都结束时 得到的left和right已经有：`height[left] > hgt && height[right] > hgt`   
	
	此时虽然宽度(right - left)变短了 但由于高度min(height[left], height[right])变长了 所以有可能获得更大的容量  

```cpp
while (left < right) {
	int h1 = height[left];
	int h2 = height[right];
	int hgt = h1 < h2 ? h1 : h2; // min(h1, h2)

	int tmp = (right - left) * hgt;
	volume = volume > tmp ? volume : tmp; // max(volume, tmp)
	while (height[left] <= hgt && left < right) ++left;
	while (height[right] <= hgt && left < right) --right;
}
```
