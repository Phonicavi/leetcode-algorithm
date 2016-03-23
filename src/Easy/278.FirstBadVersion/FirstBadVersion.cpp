// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        if (n==1) return 1;
        if (n==2) return isBadVersion(1)?1:2;
        while (left<right) {
            // mid = (left+right)/2; // left+right 会溢出 
            mid = left+(right-left)/2;
            bool f1 = isBadVersion(mid), f2 = isBadVersion(mid+1);
            if (!f1&&f2) return mid+1;
            else if (f1&&f2) right = mid;
            else if (!f1&&!f2) left = mid;
        }
        return left;
    }
};