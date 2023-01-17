class Solution {
    //https://leetcode.com/problems/minimum-path-sum/
public:
    vector<vector<int>> dp;
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        dp[m-1][n-1] = grid[m-1][n-1];
        int ans = dfs(0,0,grid);
        return ans;
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(r>=m || c>=n) return INT_MAX;
        if(dp[r][c] >=0 )return dp[r][c];
        int right = dfs(r,c+1,grid);
        int down = dfs(r+1,c,grid);
        dp[r][c] = grid[r][c] + min(right, down);
        return dp[r][c];
    }
    
};