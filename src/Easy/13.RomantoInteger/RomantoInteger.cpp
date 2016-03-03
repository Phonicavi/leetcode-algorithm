class Solution {
public:
    int romanToInt(string s) {
        int T[128] = {0};
        int n = s.size();
        T['I'] = 1;
        T['V'] = 5;
        T['X'] = 10;
        T['L'] = 50;
        T['C'] = 100;
        T['D'] = 500;
        T['M'] = 1000;
        
        int total = T[s[n-1]], tmp;
        for (int i=n-2; i>=0; --i) {
            tmp = T[s[i]];
            if (tmp < T[s[i+1]]) total -= tmp;
            else total += tmp;
        }
        return total;
    }

    int romanToInt1(string s) {
        int num[256] = { 0 };
        int result = 0;
        num['I'] = 1; num['V'] = 5; num['X'] = 10; num['L']=50;
        num['C'] = 100; num['D'] = 500; num['M'] = 1000;
        int i = 0;
        while (i < s.size()){
            if (num[s[i]] < num[s[i+1]])
                result -= num[s[i]];
            else
                result += num[s[i]];
            i++;
        }
        return result;
    }

    int romanToInt2(string s) {
        unordered_map<char, int> T = {
        	{'I', 1},
        	{'V', 5},
        	{'X', 10},
        	{'L', 50},
        	{'C', 100},
        	{'D', 500},
        	{'M', 1000}
        };

        // examples.
        //   'I' => 1, 'II' => 2, 'III' => 3, 'IV' => 4, 'V' => 5
        //   'VI' => 6, 'VII' => 7, 'VIII' => 8, 'IX' => 9, 'X' => 10
        int total = T[s.back()];
        for (int i = s.size()-2; i >= 0; --i) {
        	// 
        	if (T[s[i] < T[s[i+1]]) total -= T[s[i]];
        	else total += T[s[i]];
        }
        return total;
    }
};