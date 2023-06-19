class Solution {
    //https://leetcode.com/problems/the-maze
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<vector<int>>> dir_scale = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(4,-1)));
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}}; ////Directions D,U,R,L
        function<int(vector<int>&)> outbound = [&](vector<int>&p) {
            return (p[0]<0 || p[1]<0 || p[0]>=m || p[1]>=n);
        };
        function<int (vector<int>, int)> get_dir_scale = [&](vector<int>p, int didx){
            if( dir_scale[p[0]][p[1]][didx] != -1) return dir_scale[p[0]][p[1]][didx];
            vector<int> q = {p[0] + dirs[didx][0], p[1] + dirs[didx][1]};
            if(outbound(q) || maze[q[0]][q[1]] == 1)
                return dir_scale[p[0]][p[1]][didx] = 0;
            else
                return dir_scale[p[0]][p[1]][didx] = get_dir_scale(q,didx)+1;
        };
        
        bool ans = false;
        function<void(vector<int>)> dfs = [&](vector<int> p) {
            //printf("{%d,%d}\n", p[0],p[1]);
            if(p == destination) ans = true;
            visited[p[0]][p[1]] = 1;
            for(int didx = 0; didx<4; didx++) {
                vector<int> q = {
                    p[0] + get_dir_scale(p,didx)*dirs[didx][0], 
                    p[1] + get_dir_scale(p,didx)*dirs[didx][1]
                };//next point 
                if(visited[q[0]][q[1]]) continue;
                if(q==p) continue;
                dfs(q);
            }
        };
        dfs(start);
        return ans;                                                                                            
    }
};