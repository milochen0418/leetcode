class Solution {
    //https://leetcode.com/problems/minimum-falling-path-sum/
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>& M = matrix;
        int m = M.size(), n = M[0].size();
        for(int i = m-2; i >= 0; i--) {        
            for(int j = 0;j<n;j++) {
                int a1 = j-1<0?INT_MAX:M[i+1][j-1];
                int a2 = M[i+1][j];
                int a3 = j+1>=n?INT_MAX:M[i+1][j+1];
                M[i][j] += min(min(a1,a2),a3);
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j<n;j++) {
            ans= min(ans,M[0][j]);
        }
        return ans;
    }
    
};