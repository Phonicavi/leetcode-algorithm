class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int mp[256] = {0};
        for (int i=0; i<s.size(); ++i) {
            // if () return false;
            if (mp[int(s[i])] == 0) mp[int(s[i])] = int(t[i]);
            else {
                if (mp[int(s[i])] != int(t[i])) return false;
            }
            if (mp[int(t[i])+128] == 0) mp[int(t[i])+128] = int(s[i]);
            else {
                if (mp[int(t[i])+128] != int(s[i])) return false;
            }
        } 
        
        return true;
    }
};