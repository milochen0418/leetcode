class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rotten_time;
        vector<vector<int>> rotten_oranges;
        vector<vector<int>> fresh_oranges;
        int m = grid.size(), n = grid[0].size();
        rotten_time = vector<vector<int>> (m, vector<int>(n,INT_MAX));
        
        for(int i = 0; i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 2) {
                    rotten_oranges.push_back({i,j});
                } else if(grid[i][j] == 1){
                    fresh_oranges.push_back({i,j});
                }
            }
        }
        
        vector<vector<int>> dirs={ {1,0}, {-1,0}, {0,1}, {0,-1}};
        function<void(int,int,int)> dfs=[&](int row, int col,int time){
            grid[row][col] = 0;
            rotten_time[row][col] = min(rotten_time[row][col],time);
            for(auto &d:dirs) {
                int r = row+d[0], c = col+d[1];
                if(r<0 || r>=m || c<0 || c >= n) continue;
                if(grid[r][c]==0) continue;
                dfs(r,c,time+1);
            }
        };
                    
        for(auto &o: rotten_oranges) {
            vector<vector<int>> copy_grid = grid;
            dfs(o[0],o[1],0);
            grid = copy_grid;
        }
        
        //find out maximum number in rotten_time.
        int ans = -1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {   
                if(grid[i][j]!=0) {
                    ans = max(ans, rotten_time[i][j]);//find max rotten time    
                }
            }   
        }
        
        if(rotten_oranges.size()==0) {
            if(fresh_oranges.size()==0) 
                return 0;
            else 
                return -1;
        } 
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

/*
[[2,1,1],[1,1,0],[0,1,1]]
[[2,1,1],[0,1,1],[1,0,1]]
[[0,2]]
[[0]]
[[1]]

[[2,1,1],[1,1,1],[0,1,2]] <-- not passed
*/