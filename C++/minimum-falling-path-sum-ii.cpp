class Solution {
    //https://leetcode.com/problems/minimum-falling-path-sum-ii
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = m-2;i>=0;i--) {
            for(int j = 0;j<n;j++) {
                int minv = INT_MAX;
                for(int k = 0; k<n;k++) {
                    if(k==j) continue;
                    minv = min(minv,grid[i+1][k]);
                }
                grid[i][j] += minv;
            }
        }
        int ans=INT_MAX; 
        for(int j = 0; j<n;j++) ans = min(ans, grid[0][j]);
        return ans;
    }
};