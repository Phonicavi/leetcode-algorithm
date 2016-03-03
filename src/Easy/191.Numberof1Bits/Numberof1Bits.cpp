class Solution {
public:
	int hammingWeight(uint32_t n) {
		return n ? 1+hammingWeight(n&(n-1)) : 0;
	}

    int hammingWeight2(uint32_t n) {
        uint32_t count = 0;
        for (; n; count++)
        	n &= n-1;
        return count;
    }
};