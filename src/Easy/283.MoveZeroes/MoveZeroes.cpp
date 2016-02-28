#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int head = 0;
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i]) {
        		nums[head] = nums[i];
        		head++;
        	}
        }
        for (; head<nums.size(); head++) {
        	nums[head] = 0;
        }
    }

    void moveZeroes2(vector<int>& nums) {
        int last = 0;
        if (nums.size()<2) return;
        for (int i=0; i<nums.size(); ++i) {
        	if (nums[i]) swap(nums[last++], nums[i]);
        }
    }
};

int main(int argc, char const *argv[])
{
	Solution a = Solution();

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(12);

	a.moveZeroes(v);

	for (int i=0; i<v.size(); ++i) {
		cout<<v[i]<<'\t';
	}
	cout<<endl;
	return 0;
}