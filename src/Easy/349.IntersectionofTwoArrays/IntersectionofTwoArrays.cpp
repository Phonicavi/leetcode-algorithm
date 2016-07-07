class Solution {
public:
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> n;
        for (auto x : nums2) {
            if (m.count(x)) {
                n.push_back(x);
                m.erase(x);
            }
        }
        return n;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> inter;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                if (inter.empty() || nums1[i] != inter.back()) {
                    inter.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }
        return inter;
    }
};