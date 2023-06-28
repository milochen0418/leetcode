class Solution {
    //https://leetcode.com/problems/find-the-width-of-columns-of-a-grid
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> minv=vector<int>(n,0),maxv=vector<int>(n,0),ans=vector<int>(n,0);
        for(int j = 0; j<n;j++) {
            for(int i = 0; i<m;i++) {
                minv[j] = min(minv[j], grid[i][j]);
                maxv[j] = max(maxv[j], grid[i][j]);
            }
            ans[j] = max(to_string(minv[j]).length(), to_string(maxv[j]).length());
        }
        return ans;
    }
};