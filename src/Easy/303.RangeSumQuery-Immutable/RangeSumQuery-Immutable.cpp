class NumArray {
private:
	vector<int> NUMS;
	vector<int> SUMS;
public:
    NumArray(vector<int> &nums):NUMS(nums) {
        for (int i = 0; i < nums.size(); ++i) {
        	if (i==0) SUMS.push_back(NUMS[1]);
        	else SUMS.push_back(SUMS[i-1]+NUMS[i]);
        }
    }

    int sumRange(int i, int j) {
        if (i > j) return 0;
        return SUMS[j]-SUMS[i]+NUMS[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);