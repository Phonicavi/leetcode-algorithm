class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
    
    bool isPowerOfThree2(int n) {
        if (n == 1) return true;
        if (n <= 0) return false;
        return n%3 ? false : isPowerOfThree(n/3);
    }
};