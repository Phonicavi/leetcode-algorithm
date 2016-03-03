class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // start position, nums1:i nums2:j merged:k
        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0&&j >= 0) {
        	if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        	else nums1[k--] = nums2[j--];
        }
        // if 'while' jump out, it must be: (i < 0&&j >= 0)
        while (j >= 0) nums1[k--] = nums2[j--];
        // if 'while' jump out, with: (i >= 0&&j < 0)
        // then the rest of nums1 have already in nums1
    }
};