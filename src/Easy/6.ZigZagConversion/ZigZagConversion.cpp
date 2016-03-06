class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        
        int rim = 2*(numRows-1);
        string ans = "";
        for (int line=0; line<numRows; ++line) {
            int k = 0; // number of periods
            for (int i=line; i<s.size();) {
                ans += s[i];
                if (line == 0||line == numRows-1) i += rim;
                else {
                    k++;
                    i = k*rim - i;
                }
            }
        }
        return ans;
    }
};