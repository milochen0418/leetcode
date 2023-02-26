class Solution {
    //https://leetcode.com/problems/available-captures-for-rook
    //article https://leetcode.com/problems/available-captures-for-rook/discuss/3233626/C%2B%2B-9-lines-solution
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m=board.size(), n = board[0].size(), ans = 0;
        int row,col;
        for(int k =0;k <m*n;k++) {
            if(board[k/m][k%m] == 'R') {
                row=k/m, col=k%m;
                break;
            }
        }
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &d: dirs) {
            int r=row, c=col;
            while(r>=0 && c>=0 && r<m && c<n) {
                char ch = board[r][c];
                if(ch == 'p') ans++;
                if(ch == 'B' || ch=='p') break;
                r=r+d[0];
                c=c+d[1];
            }
        }
        return ans;
    }
};