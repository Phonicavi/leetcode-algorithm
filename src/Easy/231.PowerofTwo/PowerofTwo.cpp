class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
    
    bool isPowerOfTwo2(int n) {
        return fmod(log10(n)/log10(2), 1) == 0;
    }
};