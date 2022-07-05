class Solution {
    //https://leetcode.com/problems/as-far-from-land-as-possible
public:
    const vector<vector<int>> dirs ={{0,1},{0,-1},{1,0},{-1,0}};
    struct rc{int r;int c;};
    int maxDistance(vector<vector<int>>& grid) {
        int ans = -1;
        int n = grid.size();
        queue<rc> currQ;
        queue<rc> nextQ;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1) currQ.push(rc{i,j});
            }
        }
        while(!currQ.empty()) {
            rc e = currQ.front();
            currQ.pop();
            for(auto &d:dirs) {
                int r = e.r+d[0];
                int c = e.c+d[1];
                if(r<0||r>=n||c<0||c>=n) continue;
                if(grid[r][c]==0) {
                    nextQ.push(rc{r,c});
                    grid[r][c]=1;
                }
            }
            if(currQ.empty()) {
                ans++;
                swap(currQ, nextQ);
            }
        }
        return ans==0?-1:ans;
    }
};