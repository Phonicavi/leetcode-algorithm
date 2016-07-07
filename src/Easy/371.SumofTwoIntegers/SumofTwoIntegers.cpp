class Solution {
public:
    int getSum(int a, int b) {
        return a?getSum((a&b)<<1, a^b):b;
    }
};