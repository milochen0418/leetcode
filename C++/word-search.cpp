class Solution {
    //https://leetcode.com/problems/word-search
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = { {-1,0}, {1,0}, {0,1}, {0,-1}};
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n,0));
        //1:visited. 0:no-visited
        int found = 0;
        int k = word.length();
        function<void(int,int,int)> backtrack = [&](int row, int col, int idx){
            if(found || idx>=k) {
                found = 1;
                return;
            }
            
            for(auto &d:dirs) {
                int r=row+d[0], c=col+d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(visited[r][c]) continue;
                if(board[r][c] != word[idx]) continue;
                visited[r][c]=1;
                backtrack(r,c,idx+1);
                visited[r][c]=0;
                if(found) return;
            }
        };
        
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(board[i][j] != word[0]) continue;
                visited[i][j]=1;
                backtrack(i,j,1);
                visited[i][j]=0;
                if(found) return true;
            }
        }
        return false;
    }
};