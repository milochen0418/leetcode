class Solution {
    //surfaceArea of example can view https://codepen.io/ffmaer/pen/xxGgeaE
    //https://leetcode.com/problems/surface-area-of-3d-shapes
public:
    
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int upface = 0;
        for(int i = 0; i<m;i++) 
            for(int j = 0; j<n;j++) 
                if(grid[i][j]>0)upface++;
        int ans = 2*upface;
        for(int i = 0; i<m;i++) {
            for(int j = 0; j<n;j++) {
                int v = grid[i][j];
                int left = j-1<0?0:grid[i][j-1];
                int right = j+1>=n?0:grid[i][j+1];
                int up = i-1<0?0:grid[i-1][j];
                int down = i+1>=n?0:grid[i+1][j];
                if(v>left)ans+=v-left;
                if(v>right)ans+=v-right;
                if(v>up)ans+=v-up;
                if(v>down)ans+=v-down;
            }
        }
        return ans;
    }
};