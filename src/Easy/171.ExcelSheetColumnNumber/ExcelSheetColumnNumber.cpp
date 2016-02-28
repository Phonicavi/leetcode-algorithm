class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size(), sum = 0, base = 1;
        for (int i=0; i<n; ++i) {
            sum += base*int(s[n-i-1]-'A'+1);
            base *= 26;
        }
        return sum;
    }
};