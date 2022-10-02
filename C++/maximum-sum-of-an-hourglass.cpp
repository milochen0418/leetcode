class Solution {
    //https://leetcode.com/problems/maximum-sum-of-an-hourglass/
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>>& A=grid;
        for(int i=0;i<=m-3;i++) {
            for(int j=0;j<=n-3;j++) {
                int sum = 
                      A[i][j] +   A[i][j+1] + A[i][j+2] +
                                A[i+1][j+1] +
                    A[i+2][j] + A[i+2][j+1] + A[i+2][j+2];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};