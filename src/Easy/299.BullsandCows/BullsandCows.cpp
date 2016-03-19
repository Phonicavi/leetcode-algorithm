class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.size() != guess.size()) return "0A0B";
        // two numbers
        // secret + guess
        int cntA = 0, cntB = 0;
        vector<int> vecS(10, 0);
        vector<int> vecG(10, 0);

        for (int i = 0; i < secret.size(); ++i) {
        	if (secret[i] == guess[i]) {
        		++cntA;
        	} else {
        		++vecS[int(secret[i]-'0')];
        		++vecG[int(guess[i]-'0')];
        	}
        }
        for (int i = 0; i < 10; ++i) {
        	cntB += min(vecS[i], vecG[i]);
        }
        return to_string(cntA)+'A'+to_string(cntB)+'B';
    }
};