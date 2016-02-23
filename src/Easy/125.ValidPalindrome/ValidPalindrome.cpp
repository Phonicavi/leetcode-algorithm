#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i=0, j=s.size()-1;
		for (; i<j; ++i, --j) {
			while (!isalnum(s[i])&&i<j) ++i; // until s[i] is 'al' or 'num'
			while (!isalnum(s[j])&&i<j) --j; // until s[j] is 'al' or 'num'
			if (tolower(s[i]) != tolower(s[j])) return false;
		}
		return true;
	}
    bool isPalindrome2(string s) {
        // pre-processing
        int length = s.size();
        if (length<2) return true;
        int L;
        char *ch = getChar(s, length, L);
        
        int i=0, j=L-1;
        while (i<j) {
            if (ch[i]!=ch[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    
private:
    char *getChar(string s, int len, int &L) {
    	char *ch = new char[len];
    	// strcpy(ch, s.c_str());
    	L = 0;
    	for (int i=0; i<len; ++i) {
    		char tc = s[i];
    		// cout<<tc<<endl;
    		if (isNumeric(tc)) {
    			ch[L++] = tc;
    		} else if (isAlpha(tc)) {
    			ch[L++] = (tc>='a')?(char(tc-32)):tc;
    		}
    	}
    	return ch;
    }
    bool isNumeric(char tc) { return tc>='0'&&tc<='9'; }
    bool isAlpha(char tc) { return (tc>='A'&&tc<='Z')||(tc>='a'&&tc<='z'); }
};


int main(int argc, char const *argv[])
{
	string s = "A man, a plan, a canal: Panama";
	// string s = "0P";
	// string s = "race a car";

	Solution a = Solution();
	cout<<a.isPalindrome(s)<<endl;

	return 0;
}