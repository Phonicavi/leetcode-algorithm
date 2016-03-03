class Solution {
public:
	// 欧几里得算法求最大公约数 原理gcd(m, n) = gcd(n, m%n)
	int gcd(int m, int n) {
		// return m%n ? gcd(n, m%n): m; // m > n
		return n>0 ? gcd(n, m%n) : m; // no matter which one is larger
	}

	int gcd2(int m, int n) {
		int r;
		while (n>0) {
			r = m%n;
			m = n;
			n = r;
		}
		return m;
	}
};