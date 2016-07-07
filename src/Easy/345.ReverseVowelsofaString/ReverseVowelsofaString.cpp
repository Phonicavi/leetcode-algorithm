class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (!isVowel(s[i])) ++i;
            while (!isVowel(s[j])) --j;
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
    bool isVowel(char t) {
        t = tolower(t);
        return (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u');
    }
};