class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        string prefix = "";
        for (int j=0; j<strs[0].size(); prefix+=strs[0][j++]) {
            for (int i=1; i<strs.size(); ++i) {
                if (j >= strs[i].size()||strs[i][j] != strs[i-1][j]) return prefix;
            }
        }
        return prefix;
    }
};