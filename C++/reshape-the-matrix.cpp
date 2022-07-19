class Solution {
    //https://leetcode.com/problems/reshape-the-matrix
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size(), size = m*n;
        if(r*c != size) return mat;
        vector<vector<int>> ans = vector<vector<int>>(r, vector<int>(c,0));
        for(int i = 0; i<size;i++) ans[i/c][i%c] = mat[i/n][i%n];
        return ans;
    }
};