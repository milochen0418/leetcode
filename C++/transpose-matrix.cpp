class Solution {
    //https://leetcode.com/problems/transpose-matrix/
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(n==m) {
            for(int i = 0; i<m;i++) {
                for(int j = i+1;j<n;j++) {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            return matrix;
        }
        vector<vector<int>> ans = vector<vector<int>>(n,vector<int>(m,0));
        for(int i = 0; i<m;i++) {
            for(int j = 0;j<n;j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};