class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> frs;
    	frs = nums;
    // 	quick_sort(frs);
    sort(frs.begin(), frs.end());
    	int i = 0, j = frs.size()-1;

    	while (i < j&&frs[i]+frs[j] != target) {
    		if (frs[i]+frs[j] > target) --j;
    		if (frs[i]+frs[j] < target) ++i;
    		// if (frs[i]+frs[j] == target) break;
    	}
		int a = frs[i], b = frs[j];

    	// for (i = 0; i < nums.size(); ++i) if (nums[i] == a||nums[i] == b) break;
    	// for (j = i+1; j < nums.size(); ++j) if (nums[j] == b||nums[j] == a) break;

    	// vector<int> ans(2);
    	// ans[0] = i;
    	// ans[1] = j;
        // return ans;

    	vector<int> ans;
        for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
            if (a == *itr) ans.push_back(itr-nums.begin());
            else if (b == *itr) ans.push_back(itr-nums.begin());
            if (ans.size() == 2) break;
        }
    	return ans;
    }

    int divide_seqence(vector<int>& nums, int i, int j) {
    	int pivot = nums[i];
    	while (i < j) {
    		while (i < j&&nums[j] >= pivot) --j;
    		if (i < j) {
    			nums[i++] = nums[j];
    			nums[j] = pivot;
    		}
    		while (i < j&&nums[i] <= pivot) ++i;
    		if (i < j) {
    			nums[j--] = nums[i];
    			nums[i] = pivot;
    		}
    	}
    	nums[i] = pivot;
    	return i;
    }

    void quick_sort(vector<int>& nums, int left, int right) {
    	if (left >= right) return;
    	int mid = divide_seqence(nums, left, right);
    	quick_sort(nums, left, mid-1);
    	quick_sort(nums, mid+1, right);
    }

    void quick_sort(vector<int>& nums) {
    	quick_sort(nums, 0, nums.size()-1);
    }


    vector<int> twoSum2X(vector<int>& nums, int target) {
        vector<int> frs = nums;
        sort(frs.begin(), frs.end());
        int i = 0, j = frs.size()-1;
        while (i < j) {
            if (frs[i]+frs[j]>target) --j;
            else if (frs[i]+frs[j]<target) ++i;
            else break;
        }
        int a = frs[i], b = frs[j];
        vector<int> ans;
        for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
            if (a == *itr) ans.push_back(itr-nums.begin());
            else if (b == *itr) ans.push_back(itr-nums.begin());
            if (ans.size() == 2) break;
        }
        return ans;
    }

};