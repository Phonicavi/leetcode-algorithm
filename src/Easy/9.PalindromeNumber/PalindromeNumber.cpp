class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (!(x%10)&&x) return false;

        int half = 0;
        while (x>half) {
        	half = half*10 + x%10;
        	x /= 10;
        }
        return (x == half)||(x == half/10);
    }
};