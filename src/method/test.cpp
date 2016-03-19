#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& nums, int left, int right);
void merge_into_one(vector<int>& nums, int left, int mid, int right);

void mergeSort(vector<int>& nums) {
	mergeSort(nums, 0, nums.size()-1);
}

void mergeSort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int mid = (left+right)/2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid+1, right);
	merge_into_one(nums, left, mid+1, right);
}

void merge_into_one(vector<int>& nums, int left, int mid, int right) {
	vector<int> tmp(right-left+1);
	int k = 0, i = left, j = mid;
	while (i <= mid-1&&j <= right) {
		if (nums[i] < nums[j]) tmp[k++] = nums[i++];
		else tmp[k++] = nums[j++];
	}
	while (i <= mid-1) tmp[k++] = nums[i++];
	while (j <= right) tmp[k++] = nums[j++];
	for (k = 0, i = left; i <= right; ) {
		nums[i++] = tmp[k++];
	}
}

std::vector<int> v;

int main(int argc, char const *argv[])
{
	v.push_back(8);
	v.push_back(4);
	v.push_back(5);
	v.push_back(-2);
	v.push_back(6);
	v.push_back(1);

	mergeSort(v);

	for (auto itr = v.begin(); itr != v.end(); ++itr) {
		cout<<(*itr)<<endl;
	}
	return 0;
}