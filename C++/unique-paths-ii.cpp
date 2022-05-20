class Solution {
    //https://leetcode.com/problems/unique-paths-ii
    //article https://leetcode.com/problems/unique-paths-ii/discuss/2055929/C%2B%2B-or-Dynamic-Programming-or-Explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5335095856512862/
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>& a = obstacleGrid;
        int m = a.size(), n = a[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n,-1));
        dp[m-1][n-1] = a[m-1][n-1]==1?0:1;
        return go(0,0,a,dp);
    }
    int go(int row, int col,vector<vector<int>>& a, vector<vector<int>>& dp) {
        if(row >= a.size() || col >= a[0].size()) return 0;
        if(dp[row][col ] >= 0) return dp[row][col];
        if(a[row][col] == 1) {
            dp[row][col] = 0;
        } else {
            dp[row][col] = go(row+1,col,a,dp) + go(row,col+1,a,dp);
        }
        return dp[row][col];
    }
};