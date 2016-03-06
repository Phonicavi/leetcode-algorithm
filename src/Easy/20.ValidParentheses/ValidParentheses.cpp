class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) return false;
        stack<char> st;
        
        for (int i=0; i<s.size(); ++i) {
        	auto ch = s[i];
        	if (ch == '('||ch == '['||ch == '{') st.push(ch);
        	else {
        		if (st.empty()) return false;
        		auto hc = st.top();
        		if (hc == '('&&ch != ')') return false;
        		if (hc == '['&&ch != ']') return false;
        		if (hc == '{'&&ch != '}') return false;
        		st.pop();
        	}
        }

        if (st.empty()) return true;
        else return false;
    }
};