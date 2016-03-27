###经典的TwoSum问题  
    给一个乱序的数组 给定一个整数target 求出这个数组中哪两个数的和正好是这个target  

    需要对数组先进行排序 排好序后两个指针i j 一个放在开头一个放在结尾  
    两头同时步进：  
        如果 nums[i]+nums[j] 大于 target 则 --j  
        如果 nums[i]+nums[j] 小于 target 则 ++i  

    因为说了一定能找到 所以推出时nums[i]和nums[j]就是答案  