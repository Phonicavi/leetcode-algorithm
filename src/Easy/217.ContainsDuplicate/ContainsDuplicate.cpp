class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int length = nums.size();
        if (!length) return false;

        unordered_map<int, int> mp;
        for (int i:nums) {
        	if (++mp[i] > 1) {
        		return true;
        	}
        }
        return false;
    }
};