class Solution {
    //https://leetcode.com/problems/rotting-oranges/
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rotten_time;
        vector<vector<int>> rotten_oranges;
        
        int fresh_oranges_cnt = 0;
        int m = grid.size(), n = grid[0].size();
        rotten_time = vector<vector<int>> (m, vector<int>(n,INT_MAX));
        
        for(int i = 0; i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 2) {
                    rotten_oranges.push_back({i,j});
                } else if(grid[i][j] == 1){
                    fresh_oranges_cnt++;
                }
            }
        }
        if(fresh_oranges_cnt==0) return 0;
        int ans = -1;
        vector<vector<int>> dirs={ {1,0}, {-1,0}, {0,1}, {0,-1}};
        function<void()> bfs = [&]() {
            queue<vector<int>> currQ, nextQ;
            for(auto &v:rotten_oranges) 
                currQ.push(v);
            int time = 0;
            while(!currQ.empty()) {
                vector<int>e = currQ.front();
                rotten_time[e[0]][e[1]] = min(time,rotten_time[e[0]][e[1]]) ;
                grid[e[0]][e[1]] = 0;
                currQ.pop();
                for(auto &d:dirs) {
                    int r = e[0]+d[0], c = e[1]+d[1];
                    if(r<0 || r>=m || c<0 || c>=n) continue;
                    if(grid[r][c]==0) continue;
                    nextQ.push({r,c});
                }
                if(currQ.empty()) {
                    time++;
                    swap(currQ,nextQ);
                }
            }
        };
        vector<vector<int>> copy_grid = grid;
        bfs();
        grid = copy_grid;
        
        //find out maximum number in rotten_time.
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {   
                if(grid[i][j]!=0) {
                    ans = max(ans, rotten_time[i][j]);//find max rotten time    
                }
            }   
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};