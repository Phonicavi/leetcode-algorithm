class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0}, col[9][9] = {0}, sqr[9][9] = {0};
        
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') continue;
                int idx = (board[i][j]-'0')-1;
                int k = (i/3)*3+j/3;
                if (row[i][idx]||col[j][idx]||sqr[k][idx]) return false;
                row[i][idx] = col[j][idx] = sqr[k][idx] = true;
            }
        }
        return true;
    }
};