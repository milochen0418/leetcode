class Solution {
    //https://leetcode.com/problems/unique-paths
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        return go(0,0,dp);
    }
    int go(int row, int col, vector<vector<int>>& dp) {
        if(row >= dp.size() || col >= dp[0].size()) return 0;
        if(dp[row][col ] >= 0) return dp[row][col];
        dp[row][col] = go(row+1,col,dp) + go(row,col+1,dp);
        return dp[row][col];
    }
};

