###数组片段和  
	给定数组 给定下标i和下标j 快速求出i到j的元素和  
	用空间O(n)换时间O(1)  
	保存一个额外的数组 sum[i]表示前i个的和  
	则求i到j的和时只要sum[j]-sum[i]+num[i]即可  