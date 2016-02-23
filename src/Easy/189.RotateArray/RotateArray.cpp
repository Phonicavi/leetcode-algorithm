#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for (int i=0; i<n-k; ++i) nums.push_back(nums[i]);
        
        auto itr = nums.begin()+(n-k);
        vector<int> ans;
        for (int i=0; i<n; ++i) ans.push_back(*(itr++));
        
        nums = ans;
    }

    void rotate1_5(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if (n < 2||k == 0) return;
        // copy nums

        // 复制可以被省略 直接 ans = nums; 就可以了
        // for (int i=0; i<n; ++i) ans.push_back(nums[i]);
        vector<int> ans = nums;
		// jump
		auto itr = ans.end();
        int i;
        for (i=0; i<k; ++i) --itr;
        // connect
        auto st = nums.begin();
        for (; itr != ans.end(); ++itr) *(st++) = *itr;
        for (itr = ans.begin(); i<n; ++i) *(st++) = *(itr++);
    }
    
    void rotate2(vector<int>& nums, int k) {
        /** with O(1) extra space, but TLE... **/
        int n = nums.end()-nums.begin();
        if (n < 2) return;
        k = k%n;
        if (k <= n/2) {
            for (int i=0; i<k; ++i) {
                auto itr = nums.end()-1;
                int tmp = *itr;
                while (itr != nums.begin()) {
                    *itr = *(itr-1);
                    --itr;
                }
                *itr = tmp;
            }
        }
        else {
            for (int i=0; i<n-k; ++i) {
                auto itr = nums.begin();
                int tmp = *itr;
                while (itr != nums.end()-1) {
                    *itr = *(itr+1);
                    ++itr;
                }
                *itr = tmp;
            }
        }
    }
};

int main()
{
	Solution a = Solution();
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	a.rotate(v, 1);

	vector<int>::iterator itr = v.begin();
	while (itr != v.end()) {
		cout<<"\t"<<*itr;
		itr++;
	}
	cout<<endl;

	return 0;
}