class Solution {
    //https://leetcode.com/problems/count-sub-islands
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();

        int ans=0;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid2[i][j] == 1) {
                    ans+=dfs(i,j, grid1, grid2);
                }
            }
        }
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int ret = 1;
        int m = g2.size(), n = g2[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return 1;
        if(g1[i][j]==0 && g2[i][j]==1) return 0;
        if(g2[i][j]!=1) return 1;
        g2[i][j] = -1;
        const vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        for(auto& d:dirs) {
            ret = min(ret, dfs(i+d[0], j+d[1], g1,g2));
        }
        return ret;
    }
};