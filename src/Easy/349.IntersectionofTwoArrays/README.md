###取两个array的交集  
	函数2 是暴力取nums2中的每个数 去检查nums1中有没有  
	有就加到结果那个vector里  

---  

	比较好的方法是先分别排序 nums1 nums2 各花O(nlogn)  
	再扫一遍 比较nums1[i]和nums2[j]的大小 分别步进 i, j 花费O(n)  
	
	得到一个nums1, nums2共有的x时 注意要判断去重 即当前vector非空的情况下 最后一个如果x和当前vector.back()相同 则不用加入  