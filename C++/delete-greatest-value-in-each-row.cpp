class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
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