#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major = 0, count = 0;
		for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
			if (!count) {
				major = *itr;
				count++;
			} else if (major == *itr) count++;
			else count--;
		}
		return major;
	}

    int majorityElementX(vector<int>& nums) {
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
    }
    
	int majorityElement00(vector<int>& nums) {
		int major = nums[0], count = 1;
		for (int i=1; i < nums.size(); ++i) {
			if (major == nums[i]) {
				count++;
			} else if (count == 0) {
				count++;
				major = nums[i];
			} else count--;
		}
		return major;
	}
	
    int majorityElement2xxx(vector<int>& nums) {
    	int n = nums.size();
    	if (n == 1) return nums[0];
        rank(nums);
        for (int i = 0, j = n/2+1; j<n; ++i, ++j) {
        	if (nums[i] == nums[j]) return nums[i];
        }
        return nums[n-1];
    }

    void rank(vector<int>& nums) {
		quickSort(nums, 0, nums.size()-1);
    }

	void quickSort(vector<int>& nums, int left, int right) {
		if (left >= right) return;

		int mid = divideNums(nums, left, right);
		quickSort(nums, left, mid-1);
		quickSort(nums, mid+1, right);
	}

	int divideNums(vector<int>& nums, int i, int j) {
		int tag = nums[i];
		do {
			while (i < j&&nums[j] >= tag) --j;
			if (i < j) {
				nums[i] = nums[j];
				++i;
			}
			while (i < j&&nums[i] <= tag) ++i;
			if (i < j) {
				nums[j] = nums[i];
				--j;
			}
		} while (i < j);
		nums[i] = tag;

		return i;
	}
};

int main(int argc, char const *argv[])
{
	Solution a = Solution();
	vector<int> v;

	v.push_back(3);
	v.push_back(1);
	v.push_back(8);
	v.push_back(4);
	v.push_back(10);
	v.push_back(2);
	v.push_back(6);

	a.rank(v);

	for (int i=0; i<v.size(); ++i) {
		cout<<v[i]<<'\t';
	}
	cout<<endl;
	return 0;
}