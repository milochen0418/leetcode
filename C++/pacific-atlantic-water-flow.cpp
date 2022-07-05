class Solution {
    //https://leetcode.com/problems/pacific-atlantic-water-flow
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans = vector<vector<int>>();
        const vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>& h = heights;
        int m = h.size(), n=h[0].size();
        vector<vector<int>> g = vector<vector<int>>(m, vector<int>(n,0));
        
        queue<vector<int>> currQ;
        queue<vector<int>> nextQ;
        for(int j = 0;j<n;j++) {
            int r=0,c=j;
            currQ.push({r,c});
            g[r][c] |= 1;
        }
        for(int i = 0;i<m;i++) {
            int r=i,c=0;
            currQ.push({r,c});
            g[r][c] |= 1;
        }
        
        while(!currQ.empty()) {
            vector<int> e = currQ.front();
            //printf("PO pop{%d,%d}\n",e[0],e[1]);
            currQ.pop();
            
            for(auto &d:dirs){
                int currH = h[e[0]][e[1]]; 
                int r = e[0]+d[0], c = e[1]+d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(h[r][c]>=currH) {
                    if( (g[r][c] & 1) == 0) {
                        g[r][c] |= 1;
                        nextQ.push({r,c});
                        //printf("PO push{%d,%d}\n",r,c);
                    }
                }
            }
            if(currQ.empty()) swap(currQ, nextQ);            
        }
        
        for(int j = 0;j<n-1;j++) {
            //should avoid case == n-1 to avoid repeat in final element
            int r= m-1,c=j;
            currQ.push({r,c});
            g[r][c] |= 2;
            if((g[r][c] & 3) == 3) {
                ans.push_back({r,c});
                //printf("L1: ans push_back{%d,%d}\n",r,c);
            }
        }
        for(int i = 0;i<m;i++) {
            int r= i,c=n-1;
            currQ.push({r,c});
            g[r][c] |= 2;
            if((g[r][c] & 3) == 3) {
                ans.push_back({r,c});
                //printf("L2: ans push_back{%d,%d}\n",r,c);
            }
        }
        
        while(!currQ.empty()) {
            vector<int> e = currQ.front();
            currQ.pop();
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
                        nextQ.push({r,c});
                    }
                }
            }
            if(currQ.empty()) swap(currQ, nextQ);            
        }
        return ans;

    }
    
    
};