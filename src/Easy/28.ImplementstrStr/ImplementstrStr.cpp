class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n==0) return 0;
        if (n>m) return -1;
        int i, j, k = -1;
        for (i=0, j=0; i<=m-n&&j<n; ++i) {
            if (haystack[i]==needle[j]) {
                k = i;
                for (j=0; j<n; ++i, ++j) {
                    if (haystack[i]!=needle[j]) {
                        i = k;
                        j = 0;
                        k = -1;
                        break;
                    }
                }
                if (k!=-1) return k;
            }
        }
        return k;
    }
};