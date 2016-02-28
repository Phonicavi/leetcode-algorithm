class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashmap(256, -1);
        
        int max_length = 0;
        int j = 0;
        // 循环第i次时 max_length表示i及以前的最大长度
        for (int i=0; i<s.size(); ++i) {
            j = max(hashmap[s[i]] + 1, j);// 如果一直出现新的字母 j就一直保持不动，一旦出现重复过的字母 j就变成上一次重复字母出现过的后一位
            																					// 比如 "abcdeabc" 再次出现a时 j就变成hashmap['a']+1 即'b'的位置
            max_length = max(max_length, i - j + 1);// 由于i j之间没有重复字母 所以每次可行的长度都是 i-j+1
            hashmap[s[i]] = i;// 每次循环都刷新当前字母的最近一次出现位置
        }
        
        return max_length;
    }
};