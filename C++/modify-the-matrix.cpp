class Solution {
    //https://leetcode.com/problems/modify-the-matrix
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v=vector<int>(n, -2);
        for(int i = 0; i<m; i++) 
            for(int j = 0; j<n;j++)
                v[j] = max(v[j], matrix[i][j]);
        for(int i = 0; i<m; i++) 
            for(int j = 0; j<n;j++)
                if(matrix[i][j]==-1) matrix[i][j]=v[j];        
        return matrix;
    }
};