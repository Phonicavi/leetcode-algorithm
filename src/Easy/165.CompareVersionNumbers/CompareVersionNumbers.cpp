class Solution {
public:
    // 并没有承诺只有一个dot
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i=0, j=0;
        int ver1=0, ver2=0;
        while (i<n1||j<n2) {
            while (i<n1&&version1[i]!='.') ver1 = ver1*10+int(version1[i++]-'0');
            while (j<n2&&version2[j]!='.') ver2 = ver2*10+int(version2[j++]-'0');
            
            if (ver1>ver2) return 1;
            else if (ver1<ver2) return -1;
            
            i++, j++;
            ver1=0, ver2=0;
        }

        return 0;
    }
};