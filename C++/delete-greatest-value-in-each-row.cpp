class Solution {
    //https://leetcode.com/problems/delete-greatest-value-in-each-row/
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m;i++) sort(grid[i].begin(), grid[i].end());
        for(int j = 0; j<n;j++) {
            int maxv = 0;
            for(int i = 0; i<m;i++) maxv = max(maxv, grid[i][j]);
            ans+=maxv;
        }
        return ans;
    }

    int deleteGreatestValue_V01(vector<vector<int>>& grid) {
        int ans = 0;
        while(grid[0].size()>0) {
            int m = grid.size(), n = grid[0].size();
            int maxv = 0;
            for(int i = 0; i<m;i++) {
                vector<int> &v = grid[i];
                for(int j = 0; j<n;j++) {
                    if(v[n-1] < v[j]) swap(v[n-1],v[j]);
                }
                maxv = max(maxv, v.back());
                v.pop_back();
            }
            ans+=maxv;
        }
        return ans;
    }
};