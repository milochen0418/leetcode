class Solution {
    //https://leetcode.com/problems/01-matrix
public:
    struct rc{int r; int c;};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const vector<vector<int>> dirs ={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>& g = mat;
        int m = g.size(), n = g[0].size();
        queue<rc> currQ, nextQ;
        
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                g[i][j]*=-1;
                if(g[i][j]==0) currQ.push({i,j});
            }
        }
        int len=1;
        while(!currQ.empty()) {
            rc e=currQ.front();
            currQ.pop();
            for(auto &d:dirs) {
                int r = e.r+d[0], c = e.c+d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(g[r][c]==-1) {
                    nextQ.push({r,c});
                    g[r][c] = len;
                }
            }
            if(currQ.empty()){
                swap(nextQ, currQ);
                len++;
            }
        }
        return g;
    }
};