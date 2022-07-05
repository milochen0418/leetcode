class Solution {
    //https://leetcode.com/problems/max-area-of-island
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m;i++) {
            for(int j =0;j<n;j++) {
                if(grid[i][j]>0) { 
                    ans = max(ans, dfs(i,j, grid));
                }        
            }
        }
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = -1;
        const vector<vector<int>> dirs={{0,-1},{0,1},{1,0},{-1,0}};
        int m = grid.size(), n=grid[0].size();
        int sum = 1;
        for(auto& d:dirs) {
            int r=i+d[0];
            int c=j+d[1];
            if(r<0||r>=m||c<0||c>=n) continue;
            if(grid[r][c]>0) sum+=dfs(r,c,grid);
        }
        return sum;
    }
};