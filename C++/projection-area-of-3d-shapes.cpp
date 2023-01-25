class Solution {
    //https://leetcode.com/problems/projection-area-of-3d-shapes
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int upface = 0;
        for(int i = 0; i<m;i++) 
            for(int j = 0; j<n;j++) 
                if(grid[i][j]>0)upface++;
        
        int ans = upface;
        for(int i = 0; i<m;i++) {
            int maxv = 0;
            for(int j = 0; j<n;j++) 
                maxv = max(maxv, grid[i][j]);
            ans+=maxv;
        }
        for(int j = 0; j<n;j++) {
            int maxv = 0;
            for(int i = 0; i<m;i++) 
                maxv = max(maxv, grid[i][j]);
            ans+=maxv;
        }
        
        return ans;
    }
};