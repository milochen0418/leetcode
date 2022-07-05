class Solution {
    //https://leetcode.com/problems/number-of-enclaves
public:
    //This solution is combination of the 
    //C++/max-area-of-island.cpp and C++/number-of-closed-islands.cpp
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m;i++) 
            for(int j=0;j<n;j++) 
                if(grid[i][j] == 1) 
                   ans += dfs(i,j,grid)[1];
        return ans;        
    }
    
    vector<int> dfs(int i, int j, vector<vector<int>>& grid) {
        //printf("dfs(%d,%d) start \n", i,j);
        const vector<vector<int>> dirs = { {1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = grid.size(), n = grid[0].size();
        vector<int> ret = {1,1}; //ret[0] is 1 if it is closed island ,ret[1] is sum
        grid[i][j] = -1;
        for(auto &d: dirs) {
            int r = i+d[0];
            int c = j+d[1];
            if(r<0||r>=m || c<0||c>=n) {
                ret[0] = 0;
                continue;
            }
            if(grid[r][c] == 1) {
                vector<int> v = dfs(r,c,grid);
                ret[0] = min(ret[0], v[0]);
                ret[1] += v[1];
            }
        }
        //printf("dfs(%d,%d) return %d\n", i,j,ret);
        if(ret[0]==0) ret[1]=0; //no count up sum when the island is not closed.
        return ret;      
    }
};