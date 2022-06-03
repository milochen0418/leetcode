class NumMatrix {
    //https://leetcode.com/problems/range-sum-query-2d-immutable/
    //article https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/2107372/C%2B%2B-or-O(1)-space-O(N)-time-or-Explanation
public:
    vector<vector<int>>& M;
    NumMatrix(vector<vector<int>>& matrix):M(matrix) {
        int m = M.size(), n = M[0].size();
        /*
        for(int i = 0; i<m;i++) {
            for(int j = 0; j<n;j++) {
                printf("%2d, ", M[i][j]);
            }
            printf("\n");
        }*/
        
        for(int i = 0; i<m;i++) 
            for(int j = 0; j<n;j++) 
                M[i][j] = j-1>=0? M[i][j-1] + M[i][j]:M[i][j];
        for(int j = 0; j<n;j++) 
            for(int i = 0; i<m;i++) 
                M[i][j] = i-1>=0? M[i-1][j] + M[i][j]:M[i][j];
    }
    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        int A = M[row2][col2];
        int U = row1==0?0:M[row1-1][col2];
        int L = col1==0?0:M[row2][col1-1];
        int R = col1==0||row1==0?0:M[row1-1][col1-1];
        sum = A-U-L+R;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */