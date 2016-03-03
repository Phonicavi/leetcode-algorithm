class Solution {
public:
    int rob(vector<int>& nums) {
    	int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int M[n] = {0};
        M[0] = nums[0];
        M[1] = max(nums[0], nums[1]);
        // M[n] = max(M[n-1], M[n-2]+nums[n]);
        for (int i=2; i<n; ++i) {
        	M[i] = max(M[i-1], M[i-2]+nums[i]);
        }
        return M[n-1];
    }
};