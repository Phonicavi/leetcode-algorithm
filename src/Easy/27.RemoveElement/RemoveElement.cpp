#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int length = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] != val) {
                nums[length] = nums[i];
                length++;
            }
        }
        return length;
    }

    int removeElement2(vector<int>& nums, int val) { // 理解不能-_-
        int n = nums.size();
        int count = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] == val) {
                count++;
            } else {
                nums[i-count] = nums[i];
            }
        }
        return n-count;
    }
};


int main(int argc, char const *argv[])
{
	return 0;
}