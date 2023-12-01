class Solution {
    //https://leetcode.com/problems/max-increase-to-keep-city-skyline
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rmax = vector<int>(m,-1);
        vector<int> cmax = vector<int>(n,-1);
        for(int i = 0; i<m ;i++) 
            for(int j = 0; j<n;j++) {
                rmax[i] = max(rmax[i], grid[i][j]);
                cmax[j] = max(cmax[j], grid[i][j]);
            } 
        int ans = 0;
        for(int i = 0; i<m;i++)
            for(int j = 0; j<n;j++)
                ans+=min(rmax[i],cmax[j])-grid[i][j];
        return ans;
    }
};