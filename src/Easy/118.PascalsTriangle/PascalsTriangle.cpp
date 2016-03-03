class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> A(numRows);
        for (int i=0; i<numRows; ++i) {
            vector<int> T(i+1);
            for (int j=0; j<i+1; ++j) {
                if (j == 0||j == i) T[j] = 1;
                else {
                    T[j] = A[i-1][j-1] + A[i-1][j];
                }
            }
            A[i] = T;
        }
        return A;
    }
};