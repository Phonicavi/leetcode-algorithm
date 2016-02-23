#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
    	int left, right;
    	left = right = 1;
    	std::vector<int> v(n, 1);

    	for (int i = 0; i < n; ++i) {
    		v[i] = v[i]*left;
    		left = left*nums[i];
    		v[n-i-1] = v[n-i-1]*right;
    		right = right*nums[n-i-1];
    	}

    	return v;
    }

    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        // left[i] = PI{multi_product of the first nums[i]}
        // right[i] = PI{multi_product of the last nums[i]}
        left[0] = right[0] = 1;

        for (int i = 1; i < n; ++i) {
        	left[i] = nums[i-1]*left[i-1];
        	right[i] = nums[n-i]*right[i-1];
        }

		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = left[i]*right[n-i-1];
		}

		return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution a = Solution();

	std::vector<int> v;
	v.push_back(0);
	v.push_back(0);

	cout<<v[0]<<endl;
	cout<<v[1]<<endl;
	cout<<"-------"<<endl;

	auto res = a.productExceptSelf(v);
	cout<<res[0]<<endl;
	cout<<res[1]<<endl;
	return 0;
}