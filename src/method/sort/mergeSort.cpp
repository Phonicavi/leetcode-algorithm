#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void merge_sort(vector<int>& nums) {
    	merge_sort(nums, 0, nums.size()-1);
    }

    void merge_sort(vector<int>& nums, int left, int right) {
    	if (left >= right) return;
    	int mid = (left+right)/2;
    	merge_sort(nums, left, mid);
    	merge_sort(nums, mid+1, right);
        merge(nums, left, mid+1, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int k = 0, i = left, j = mid;
        vector<int>* tmp = new vector<int>(right-left+1);
    	while (i < mid&&j <= right) {
            if (nums[i] < nums[j]) (*tmp)[k++] = nums[i++];
            else (*tmp)[k++] = nums[j++];
    	}
        while (i < mid) (*tmp)[k++] = nums[i++];
        while (j <= right) (*tmp)[k++] = nums[j++];

        for (i = 0, k = left; k <= right;) 
            nums[k++] = (*tmp)[i++];
        delete tmp;
        // 如果tmp不用指针申请的话 则在调用时直接tmp[i]调用index 并且不用delete空间
    }
};

int main(int argc, char const *argv[])
{
	Solution a = Solution();
	vector<int> v;

	v.push_back(3);
	v.push_back(1);
	v.push_back(6);
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(6);

	a.merge_sort(v);

	for (int i=0; i<v.size(); ++i) {
		cout<<v[i]<<'\t';
	}
	cout<<endl;
	return 0;
}