class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        
        int M[n+1] = {0};
        M[1] = 1; M[2] = 2;
        for (int i=3; i<=n; ++i) {
            M[i] = M[i-1] + M[i-2];
        }
        return M[n];
    }
};