class Solution {
public:
    int reverse(int x) {
        if (x==0) return x;
        bool f = 0;
        if (x<0) {f=1; x = -x;}
        long long revers = 0;
        while (x) {
            revers = revers*10 + x%10;
            x /= 10;
        }
        revers = f?-revers:revers;
        return (revers>INT_MAX||revers<INT_MIN)?0:revers;
    }
};