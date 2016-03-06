class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1, length = 0;
        // 结尾可能有0 要先扫一遍把结尾的0清掉
        while (i >= 0&&s[i] == ' ') i--;
        if (i == -1) return 0;
        
        while (i >= 0&&s[i] != ' ') {
            ++length;
            --i;
        }
        return length;
    }
};