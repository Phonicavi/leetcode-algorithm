class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> summary;
        if (n==0) return summary;
        string item = "";
        for (int i=0; i<n;) {
            int head = i, tail = i;
            while (tail<n-1&&nums[tail+1]==nums[tail]+1) tail++;
            if (tail>head) summary.push_back(to_string(nums[head])+"->"+to_string(nums[tail]));
            else summary.push_back(to_string(nums[head]));
            i = tail+1;
        }
        return summary;
    }
};