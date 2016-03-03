class Solution {
public:
    bool isHappy(int n) { // 据说所有的 {2, ..., 6}的数都不是happy的 且所有的死循环都会掉入这个范围里
// 7 是happy的 7 => 49 => 97 => 130 => 10 => 1
    // 一旦掉入 6及6以下范围 则判断是不是为1: 为1happy 否则不happy
        while(n>6){
            int next = 0;
            while(n){next+=(n%10)*(n%10); n/=10;}
            n = next;
        }
        return n==1;
    }

    bool isHappy2(int n) {
        if (n < 1) return false;
        if (n == 1) return true;

        unordered_set<int> show;

        while (true) {
	        show.insert(n);
        	int sum = 0;
        	while (n) {
        		sum += (n%10)*(n%10);
        		n /= 10;
        	}
        	if (sum == 1) return true;
        	else if (show.find(sum) != show.end()) return false;
        	n = sum;
        }
    }
};