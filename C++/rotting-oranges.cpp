class Solution {
    //https://leetcode.com/problems/rotting-oranges/
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_oranges_cnt = 0;
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> currQ, nextQ;
        for(int i = 0; i<m;i++) { //O(N*M)
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 2) 
                    currQ.push({i,j});
                else if(grid[i][j] == 1)
                    fresh_oranges_cnt++;
            }
        }
        if(fresh_oranges_cnt==0) return 0;
        int ans = -1, time = 0;//
        vector<vector<int>> dirs={ {1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!currQ.empty()) { //O(N*M)
            vector<int>rc = currQ.front();
            currQ.pop();
            int &e = grid[rc[0]][rc[1]];
            if(e == 1) fresh_oranges_cnt--;
            if(e>0) 
                e = -1*time;
            else 
                e = max(e, -1*time);            
            if(e<0)ans = min(ans,e);
            
            for(auto &d:dirs) {
                int r = rc[0]+d[0], c = rc[1]+d[1];
                if(r<0 || r>=m || c<0 || c>=n || grid[r][c]<=0) continue;
                nextQ.push({r,c});
            }
            if(currQ.empty()) {
                time++;
                swap(currQ,nextQ);
            }
        }
        if(fresh_oranges_cnt>0) return -1;
        return ans*-1;
    }

    int orangesRotting_v01(vector<vector<int>>& grid) {
        vector<vector<int>> rotten_time;
        int fresh_oranges_cnt = 0;
        int m = grid.size(), n = grid[0].size();
        rotten_time = vector<vector<int>> (m, vector<int>(n,INT_MAX));
        queue<vector<int>> currQ, nextQ;
        for(int i = 0; i<m;i++) { //O(N*M)
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 2) 
                    currQ.push({i,j});
                else if(grid[i][j] == 1)
                    fresh_oranges_cnt++;
            }
        }
        if(fresh_oranges_cnt==0) return 0;
        int ans = -1, time = 0;
        vector<vector<int>> dirs={ {1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!currQ.empty()) { //O(N*M)
            vector<int>e = currQ.front();
            rotten_time[e[0]][e[1]] = min(time,rotten_time[e[0]][e[1]]) ;
            ans = max(ans, rotten_time[e[0]][e[1]]);
            if(grid[e[0]][e[1]] == 1) fresh_oranges_cnt--;
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
        
        if(fresh_oranges_cnt>0) return -1;
        return ans;
    }
};