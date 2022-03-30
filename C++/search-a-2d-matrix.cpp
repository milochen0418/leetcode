class Solution {
    //https://leetcode.com/problems/search-a-2d-matrix
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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