class Solution {
    //https://leetcode.com/problems/pacific-atlantic-water-flow
    //article https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/2242975/C%2B%2B-or-BFS-or-explanation-or-easy-understand
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans = vector<vector<int>>();
        const vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>& h = heights;
        int m = h.size(), n=h[0].size();
        vector<vector<int>> g = vector<vector<int>>(m, vector<int>(n,0));
        
        queue<vector<int>> Q;
        
        for(int j = 1;j<n;j++) {
            //j should start from j to avoid push {0,0} double times
            int r=0,c=j;
            Q.push({r,c});
            g[r][c] |= 1;
        }
        for(int i = 0;i<m;i++) {
            int r=i,c=0;
            Q.push({r,c});
            g[r][c] |= 1;
        }
        
        while(!Q.empty()) {
            vector<int> e = Q.front();
            //printf("PO pop{%d,%d}\n",e[0],e[1]);
            Q.pop();
            
            for(auto &d:dirs){
                int currH = h[e[0]][e[1]]; 
                int r = e[0]+d[0], c = e[1]+d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(h[r][c]>=currH) {
                    if( (g[r][c] & 1) == 0) {
                        g[r][c] |= 1;
                        Q.push({r,c});
                        //printf("PO push{%d,%d}\n",r,c);
                    }
                }
            }
        }
        
        for(int j = 0;j<n-1;j++) {
            //j should stop in n-2 to avoid {m-1,n-1} process in double time.
            int r= m-1,c=j;
            Q.push({r,c});
            g[r][c] |= 2;
            if((g[r][c] & 3) == 3) {
                ans.push_back({r,c});
                //printf("L1: ans push_back{%d,%d}\n",r,c);
            }
        }
        for(int i = 0;i<m;i++) {
            int r= i,c=n-1;
            Q.push({r,c});
            g[r][c] |= 2;
            if((g[r][c] & 3) == 3) {
                ans.push_back({r,c});
                //printf("L2: ans push_back{%d,%d}\n",r,c);
            }
        }
        
        while(!Q.empty()) {
            vector<int> e = Q.front();
            Q.pop();
            //printf("AO pop{%d,%d}\n",e[0],e[1]);
            for(auto &d:dirs){
                int currH = h[e[0]][e[1]]; 
                int r = e[0]+d[0], c = e[1]+d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(h[r][c]>=currH) {
                    if( (g[r][c] & 2) == 0) {
                        //printf("AO push{%d,%d}\n",r,c);
                        g[r][c] |= 2;
                        if((g[r][c] & 3) == 3) {
                            ans.push_back({r,c});
                            //printf("L3: ans push_back{%d,%d}\n",r,c);
                        }
                        Q.push({r,c});
                    }
                }
            }
        }
        return ans;
    }
};