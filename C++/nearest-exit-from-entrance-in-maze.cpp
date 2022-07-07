class Solution {
    //https://leetcode.com/problems/nearest-exit-from-entrance-in-maze
public:
    struct rc{int r;int c;};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<char>>& g=maze;
        vector<vector<int>> exits;
        int m = g.size(), n =g[0].size();

        //Step 1. set 'x' to mean exist
        int i=0, j=0;
        for(auto &d:dirs) {
            while(true) {
                if(g[i][j]=='.') g[i][j] = 'x';
                int r = d[0]+i, c = d[1]+j;
                if(r<0||r>=m||c<0||c>=n) break;
                i=r; j=c;
            }
        }
        //Step 2. Use BFS to run from entrance to all possible 'x' in g 
        //but ignore it if entrance part is near board.
        queue<rc> currQ, nextQ;
        int len = 1;
        g[entrance[0]][entrance[1]]='+';
        currQ.push({entrance[0], entrance[1]});
        while(!currQ.empty()) {
            rc e = currQ.front();
            currQ.pop();
            for(auto &d:dirs) {
                int r = e.r+d[0], c=e.c+d[1];
                if(r<0||r>=m||c<0||c>=n) continue;
                if(g[r][c]=='x') return len;
                if(g[r][c]=='.') {
                    g[r][c]='+';
                    nextQ.push({r,c});
                }
            }
            if(currQ.empty()) {
                swap(currQ,nextQ);
                len++;
            }
        }
        return -1;
    }
};