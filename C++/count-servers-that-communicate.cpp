class Solution {
    //https://leetcode.com/problems/count-servers-that-communicate
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> rs = vector<int>(m,0), cs =vector<int>(n,0);
        for(int i = 0; i<m; i++){
            for(int j = 0;  j<n;j++){
                rs[i] += grid[i][j];
                cs[j] += grid[i][j];
            }
        }
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                ans+=grid[i][j] && ((rs[i]>1) || (cs[j]>1));
        return ans;
        
    }
};