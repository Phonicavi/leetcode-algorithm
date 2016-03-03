class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, n = digits.size();
        digits[n-1] += 1;
        for (int i=n-1; i>0; --i) {
            digits[i-1] += digits[i]/10;
            digits[i] %= 10;
        } // i=0

        carry = digits[0]/10;
        digits[0] %= 10;
        if (carry) {
            vector<int> ans(n+1, 0);
            ans[0] = carry;
            for (int j=1; j<=n; ++j) {
                ans[j] = digits[j-1];
            }
            return ans;
        } else {
            vector<int> ans(n, 0);
            for (int j=0; j<n; ++j) {
                ans[j] = digits[j];
            }
            return ans;
        }
    }

    // another function with different type
    void plusone(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return;
            }
        }
        digits[0] =1;
        digits.push_back(0);
    }
};