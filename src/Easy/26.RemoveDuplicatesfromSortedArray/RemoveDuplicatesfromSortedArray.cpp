#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.begin() == nums.end()) return 0;
        int length = 1;
        vector<int>::iterator itr, word;
        for (word = nums.begin(), itr = word+1; itr != nums.end(); ++itr) {
            if (*itr > *word) {
                ++length;
                *(++word) = *itr;
            }
        }
        return length;
    }

    int removeDuplicates2(vector<int>& nums) {
        vector<int>::iterator itr = unique(nums.begin(), nums.end());
        return itr-nums.begin();
    }

    int removeDuplicates3(vector<int>& nums) {
        int length = 0;
        vector<int>::iterator itr, wd;
        for (itr = nums.begin(); itr != nums.end(); ++itr) {
            if (length == 0) {
                ++length;
                wd = itr;
            } else {
                if (*itr > *wd) {
                    ++length;
                    *(++wd) = *itr;
                }
            }
        }
        
        return length;
    }
};

int main(int argc, char const *argv[])
{
    Solution a = Solution();

    vector<int> v;
    v.push_back(1);

    int x = a.removeDuplicates(v);

    cout<<x<<endl;

    return 0;
}