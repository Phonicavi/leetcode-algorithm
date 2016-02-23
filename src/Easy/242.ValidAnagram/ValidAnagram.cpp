#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
	// strings contain only lowercase alphabets
    bool isAnagram(string s, string t) {
        // int array[26] = {0};
		vector<int> array(26, 0);
		int m = s.size();
		int n = t.size();
		if (m != n) return false;

		for (int i = 0; i < m; ++i) {
			++array[int(s[i]-'a')];
		}
		for (int i = 0; i < n; ++i) {
			--array[int(t[i]-'a')];
		}

		for (int i = 0; i < 26; ++i) {
			if (array[i]) return false;
		}
		return true;
    }
};


int main(int argc, char const *argv[])
{
	string s, t;
	s = "anagram";
	t = "nagrama";

	Solution a = Solution();
	cout<<a.isAnagram(s, t)<<endl;

	return 0;
}