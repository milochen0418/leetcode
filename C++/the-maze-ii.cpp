class Solution {
    //https://leetcode.com/problems/the-maze-ii/
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<int> V; 
        int m = maze.size(), n = maze[0].size();
        vector<vector<vector<int>>> dir_scale = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(4,-1)));
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}}; ////Directions D,U,R,L
        function<int(vector<int>&)> outbound = [&](vector<int>&p) {
            return (p[0]<0 || p[1]<0 || p[0]>=m || p[1]>=n);
        };
        function<int (vector<int>&, int)> get_dir_scale = [&](vector<int>&p, int didx){
            if( dir_scale[p[0]][p[1]][didx] != -1) return dir_scale[p[0]][p[1]][didx];
            vector<int> q = {p[0] + dirs[didx][0], p[1] + dirs[didx][1]};
            if(outbound(q) || maze[q[0]][q[1]] == 1)
                return dir_scale[p[0]][p[1]][didx] = 0;
            else
                return dir_scale[p[0]][p[1]][didx] = get_dir_scale(q,didx)+1;
        };
        
        bool solution_exist = false;
        function<void(vector<int>&)> dfs = [&](vector<int>& p) {
            V.push_back(p[0]*n + p[1]);
            //printf("{%d,%d}\n", p[0],p[1]);
            if(p == destination) {
                solution_exist = true;
            }
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
        if(!solution_exist) return -1;
        unordered_map<int, vector<vector<int>>>mp;
        unordered_map<int, int> dist;
        unordered_set<int> selV; //all of vertex that have been selected in solution
        unordered_set<int> adjV; //all of vertext that not belong to selV but the adjcency vertetx of v of selV
        const int DIST_MAX = INT_MAX/2;
        for(auto &v: V) {
            dist[v] = DIST_MAX;
            int r=v/n, c=v%n;
            vector<int> p = {r,c};
            for(int i = 0; i<4;i++) {
                vector<int> &d = dirs[i];
                int scale = get_dir_scale(p,i);
                if(scale == 0) continue;
                int ur=r+scale*d[0], uc=c+scale*d[1];
                int u = ur*n + uc;
                int weight = scale; 
                mp[v].push_back({u, weight});
            }
        }
        /*
        for(auto &v:V) {
            for(auto &uw: mp[v]) {
                int u = uw[0], w = uw[1];
                printf("{%d, %d} -> {%d,%d}, w = %d\n", v/n, v%n, u/n, u%n, w);
            }
        }*/
        int s = start[0]*n + start[1];
        int d = destination[0]*n + destination[1];
        dist[s] = 0;
        selV.insert(s);
        int minV=s;
        while(true) {
            for(auto& uw: mp[minV]) {
                int u = uw[0], w = uw[1];
                if(selV.find(u) != selV.end()) continue;
                dist[u] = min(dist[minV]+w , dist[u]);
                if(dist[u] != DIST_MAX) adjV.insert(u);
            }

            if(adjV.size() == 0) {
                break;
            }
            minV = -1;//adjV[0];
            for(auto &v: adjV) {
                if(minV==-1) {
                    minV = v;
                    continue;
                }
                //if(dist[adjV[i]] < dist[minV]) {
                if(dist[v] < dist[minV]) {
                    minV = v;
                }                
            }
            selV.insert(minV);
            adjV.erase(minV);            
        }
        return dist[d];
    }
};