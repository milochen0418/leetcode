class Solution {
    //https://leetcode.com/problems/search-a-2d-matrix
    //article https://leetcode.com/problems/search-a-2d-matrix/discuss/1895843/C%2B%2B-or-binary-search-or-O(logN)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5193837967305319/
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), L=0,R=m*n-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(target == matrix[M/n][M%n]) return true;
            if(target > matrix[M/n][M%n]) L=M+1; else R=M-1;
        } 
        return false;
    }

    bool searchMatrixAnswer2(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int n = matrix.size() * cols;
        int L=0, R=n-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            int v = matrix[M/cols][M%cols];
            if (target > v) 
                L = M + 1;
            else if (target < v ) 
                R = M - 1;
            else
                return true;
        }
        return false;
    }
};