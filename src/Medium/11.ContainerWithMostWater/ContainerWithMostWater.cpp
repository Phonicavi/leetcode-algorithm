#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume = 0;
        int left = 0;
        int right = height.size()-1; // n-1

        while (left < right) {
        	int h1 = height[left];
        	int h2 = height[right];
        	int hgt = h1 < h2 ? h1 : h2; // min(h1, h2)

        	int tmp = (right - left) * hgt;
        	// 想知道最终答案是哪两个标识时 只要在外围设置一下ansLeft和ansRight
        	// 并在volume被tmp替换掉时赋值 ansLeft = left, ansRight = right; 即可
        	volume = volume > tmp ? volume : tmp; // max(volume, tmp)

        	while (height[left] <= hgt && left < right) ++left;
        	while (height[right] <= hgt && left < right) --right;
        }

        return volume;
    }
};

int main(int argc, char const *argv[])
{
	Solution a = Solution();

	return 0;
}