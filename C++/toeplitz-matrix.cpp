class Solution {
    //https://leetcode.com/problems/toeplitz-matrix
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(j-1>=0 && i-1>=0)
                    if(matrix[i][j]!=matrix[i-1][j-1])
                        return false;
        return true;
    }
};