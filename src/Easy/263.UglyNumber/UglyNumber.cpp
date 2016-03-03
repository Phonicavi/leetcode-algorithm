class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (!(num%5)) return isUgly(num/5);
        else if (!(num%3)) return isUgly(num/3);
        else if (!(num%2)) return isUgly(num/2);
        else return (num == 1);
    }
};
