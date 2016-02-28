class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int tmp_sum = 0;
        for (int i=0; i<n; ++i) {
            tmp_sum += nums[i];
            ans = tmp_sum > ans ? tmp_sum : ans;
            tmp_sum = tmp_sum > 0 ? tmp_sum : 0;
        }
        return ans;
    }
};