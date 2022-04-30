class Solution {
    //https://leetcode.com/problems/count-unguarded-cells-in-the-grid
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int cnt=0;
        vector<vector<int>> grid = vector<vector<int>>(m, vector<int>(n, 0));
        //no-guarded 0, guarded 1.  , guards 2, walls 3, 
        for(auto&g : guards) grid[g[0]][g[1]] = 2;
        for(auto&w : walls) grid[w[0]][w[1]] = 3;
        
        //configure guarded place
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto&g: guards) {            
            for(auto& dir:dirs) {
                int i = g[0], j = g[1];       
                while(true) {
                    i += dir[0];
                    j += dir[1];                
                    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]>1) break;
                    cnt += (grid[i][j] == 0);
                    grid[i][j] = 1;
                }                
            }
        }
        return m*n-cnt-guards.size()-walls.size();        
    }
};