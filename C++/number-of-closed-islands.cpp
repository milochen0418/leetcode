class Solution {
    //https://leetcode.com/problems/number-of-closed-islands
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++) 
            for(int j=0;j<n;j++) 
                if(grid[i][j] == 0) 
                   ans += dfs(i,j,grid);
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        //printf("dfs(%d,%d) start \n", i,j);
        const vector<vector<int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = grid.size(), n = grid[0].size();
        int ret = 1;
        grid[i][j] = -1;
        for(auto &d: dirs) {
            int r = i+d[0];
            int c = j+d[1];
            if(r<0||r>=m || c<0||c>=n) {
                ret = 0;
                continue;
            }
            if(grid[r][c] == 0) ret = min(ret, dfs(r,c,grid));
        }
        //printf("dfs(%d,%d) return %d\n", i,j,ret);
        return ret;
    }
};