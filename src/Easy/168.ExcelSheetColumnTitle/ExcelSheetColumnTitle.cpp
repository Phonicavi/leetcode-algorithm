class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            n--;
            int bit = n%26;
            res = char(bit+int('A'))+res;
            n /= 26;
        }
        return res;
    }
};