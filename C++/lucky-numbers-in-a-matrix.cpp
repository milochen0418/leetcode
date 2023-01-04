class Solution {
    //https://leetcode.com/problems/lucky-numbers-in-a-matrix
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row_mins = vector<int>(m,INT_MAX);
        vector<int> col_maxs = vector<int>(n,INT_MIN);
        vector<int> ans;
        for(int i = 0;i<m;i++) 
            for(int j = 0;j<n;j++) {
                row_mins[i] = min(row_mins[i], matrix[i][j]);
                col_maxs[j] = max(col_maxs[j], matrix[i][j]);
            }
        for(int i = 0;i<m;i++) 
            for(int j = 0;j<n;j++) 
                if(matrix[i][j] == row_mins[i] && matrix[i][j] == col_maxs[j])
                    ans.push_back(matrix[i][j]);
        return ans;
    }
};