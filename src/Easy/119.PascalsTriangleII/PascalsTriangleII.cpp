#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        vector<int> old(rowIndex+1);
        result[0] = 1;
        for(int n=1; n<=rowIndex; n++) { // 1-line to rowIndex-line
            old = result;
            result[0] = 1;
            for(int i=1; i<n; i++)
                result[i] = old[i-1]+old[i];
            result[n] = 1;
        }

        return result;
    }

    // 错了 这个不是二项式展开系数...
    vector<int> getRow2(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        // Factorial of rowIndex: R
        int fact[rowIndex+1];
        fact[0] = 1;
        for (int i=1; i<=rowIndex; ++i)
            fact[i] = fact[i-1]*i;

        int R = fact[rowIndex], Fm1, Fm2;
        for (int i=0; i<rowIndex+1; ++i) {
            Fm1 = fact[rowIndex-i];
            Fm2 = fact[i];
            A[i] = R/(Fm1*Fm2);
        }
        return A;
    }
};

int main(int argc, char const *argv[])
{
    Solution a = Solution();
    auto ans = a.getRow(3);

    return 0;
}