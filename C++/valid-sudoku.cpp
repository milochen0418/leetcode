class Solution {
    //https://leetcode.com/problems/valid-sudoku
    //article https://leetcode.com/problems/valid-sudoku/discuss/2351601/C%2B%2B-or-Hash-Set-or-Simple
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_set<char>>> vs = vector<vector<unordered_set<char>>>(3,vector<unordered_set<char>>(3,unordered_set<char>()));
        for(int i = 0; i<9;i++) {
            unordered_set<char> sr, sc;            
            for(int j = 0; j<9;j++) {
                int row = i/3, col = j/3;
                if(!isValid(board[i][j],vs[row][col])) return false;
                if(!isValid(board[j][i],sc)) return false;
                if(!isValid(board[i][j],sr)) return false;
            }
        }
        return true;
    }
    bool isValid(char c, unordered_set<char>& s) {
        if(c < '0' || c>'9' ) return true;
        if(s.find(c) != s.end()) return false;
        s.insert(c);
        return true;
    }
};