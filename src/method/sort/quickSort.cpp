#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void quick_sort(vector<int>& nums) {
    	core_quick_sort(nums, 0, nums.size()-1);
    }

    void core_quick_sort(vector<int>& nums, int left, int right) {
    	if (left >= right) return;
    	int mid = divide_nums(nums, left, right);
    	core_quick_sort(nums, left, mid-1);
    	core_quick_sort(nums, mid+1, right);
    }

    int divide_nums(vector<int>& nums, int i, int j) {
    	int pivot = nums[i];
    	while (i < j) {
    		while (i < j&&nums[j] >= pivot) --j;
    		if (i < j) nums[i++] = nums[j]; // since (nums[j]<pivot), we put nums[j] into the first-half part
    		while (i < j&&nums[i] <= pivot) ++i;
    		if (i < j) nums[j--] = nums[i]; // since (nums[i]>pivot), we put nums[i] into the last-half part
    	}
    	nums[i] = pivot;
    	return i;
    }
};


void quick_sort(vector<int>& v, int l, int r)
{
    int i = l, j = r, mid = v[r];
    do {
        while (v[i] < mid) ++i;
        while (v[j] > mid) --j;
        if (i <= j) {
            swap(v[i], v[j]);
            // int tmp = v[j]; v[j] = v[i]; v[i] = tmp;
            ++i; --j;
        }
    } while (i < j);
    if (j > l) quick_sort(v, l, j);
    if (i < r) quick_sort(v, i, r);
}

int main(int argc, char const *argv[])
{
	// Solution a = Solution();
	vector<int> v;

	v.push_back(3);
	v.push_back(1);
	v.push_back(6);
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(6);

	// a.quick_sort(v);
    quick_sort(v, 0, v.size()-1);

	for (int i=0; i<v.size(); ++i) {
		cout<<v[i]<<'\t';
	}
	cout<<endl;
	return 0;
}