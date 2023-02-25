class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0, m = board.size(), n = board[0].size();
        for(int i = 0;i<m;i++) 
            for(int j = 0;j<n;j++) 
                if(
                    board[i][j]=='X' && 
                    (j-1<0||board[i][j-1]=='.') && 
                    (i-1<0|| board[i-1][j]=='.')
                ) ans++;
        return ans;
    }
};