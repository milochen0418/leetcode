class Solution {
    //https://leetcode.com/problems/sparse-matrix-multiplication
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        vector<vector<int>> ans= vector<vector<int>>(m, vector<int>(n,0));
        for(int i = 0; i < m;i++) {
            for(int j = 0; j<n;j++) {
                for(int q = 0; q<k;q++) { 
                    ans[i][j] += mat1[i][q] * mat2[q][j];
                }
            }
        }
        return ans;
    }
};