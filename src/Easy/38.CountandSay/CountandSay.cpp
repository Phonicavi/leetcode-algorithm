class Solution {
public:
    string countAndSay(int n) {
        if (!n) return "";
        string s = "1";
        while (--n) {
            string tmp = "";
            for (int i = 0; i<s.size(); ++i) {
                int count = 1;
                while (i<s.size()-1) {
                    if (s[i] == s[i+1]) {
                        count++;
                        i++;
                    } else break;
                }
                tmp += to_string(count)+s[i];
            }
            s = tmp;
        }
        
        return s;
    }
};