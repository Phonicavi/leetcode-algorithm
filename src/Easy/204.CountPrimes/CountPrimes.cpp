class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        bool *isPrime;
        isPrime = new bool[n];
        // vector<bool> isPrime(n, true);
        for (int i=2; i<n; ++i) isPrime[i] = 1;
        
        for (int i=2; i*i<n; ++i) {
            if (isPrime[i]) {
                for (int j=i*i; j<n; j+=i) {
                    isPrime[j] = 0;
                }
            }
        }
        
        int count = 0;
        for (int x=2; x<n; ++x) {
            if (isPrime[x]) count++;
        }
        return count;
    }

    // bool isPrime(int x) {
    //     if (x <= 1) return false;
    //     for (int i = 2; i*i <= x; ++i) {
    //         if (!(x%i)) return false;
    //     }
    //     return true;
    // }
};