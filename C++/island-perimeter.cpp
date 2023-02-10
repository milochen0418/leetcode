class Solution {
    //https://leetcode.com/problems/island-perimeter
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n= grid[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        function<void(int,int)> dfs = [&](int row, int col) {
            grid[row][col] = -1;
            for(auto &d:dirs){
                int r = row+d[0], c = col+d[1];
                if(r<0 || c<0 || r>=m || c>=n) {
                    ans+=1;
                    continue;
                }
                if(grid[r][c]==0) ans+=1;
                if(grid[r][c]==1) dfs(r,c);
            }
        };
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) 
                if(grid[i][j]==1) {
                    dfs(i,j);
                    return ans;
                }
        return 0;
    }
};