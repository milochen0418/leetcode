class Solution {
    //https://leetcode.com/problems/count-square-submatrices-with-all-ones
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>& M = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        for(int len = 1;len<=min(m,n);len++) {
            //The loop to count how many square that width=len in matrix.
            for(int r=0;r<m-len+1;r++){
                for(int c=0;c<n-len+1;c++) {
                    //(r,c) is left-top corner of square
                    if(check(M,r,c,len)) ans++;
                }
            }
        }
        return ans;
    }
    int check(vector<vector<int>>& M, int r, int c, int len) {
        for(int row = r;row<r+len;row++) {
            for(int col =c; col<c+len;col++) {
                if(M[row][col] == 0) {
                    //printf("M[rc=(%d,%d)] = 0\n",row,col);
                    return 0;
                }
            }
        }
        return 1;
    }  
};