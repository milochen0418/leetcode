class Solution {
    //https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i<m;i++) {
            int shift = (i%2!=0)?k:-k;
            shift = (100*n + shift)%n;
            for(int j = 0; j<n;j++) { 
                int pos = (j+shift)%n;
                if(mat[i][pos] != mat[i][j]) return false;
            }
        }
        return true;
     }
};