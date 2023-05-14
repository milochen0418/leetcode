class Solution {
    //https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp = vector<int>(m*n,-1);
        
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<m*n;i++) {
            int row = i/n;
            int col = i%n;
            int val = grid[row][col];
            if(col+1>=n) continue;
            if(grid[row][col+1] > val) mp[i].push_back(  row*n + col+1 );
            if(row-1>=0) 
                if(grid[row-1][col+1] > val) mp[i].push_back(  (row-1)*n + col+1 );
            if(row+1<m) 
                if(grid[row+1][col+1] > val) mp[i].push_back(  (row+1)*n + col+1 );
        }
        int ans = 0;
        function<int(int)> dfs = [&](int root) {
            if(dp[root] != -1) return dp[root];
            if(mp[root].size()==0) {
                return dp[root]=root%n;
            } else {
                int maxv = 0;
                for(auto &child:mp[root]) 
                    maxv = max(maxv,dfs(child));
                return dp[root]=maxv;
            }
        };
        for(int i = 0; i<m;i++) {
            ans = max(ans, dfs(i*n));
        }
        return ans;
    }
};