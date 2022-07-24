class Solution {
    //https://leetcode.com/problems/search-a-2d-matrix-ii/
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = target;
        for(auto&a: matrix) {
            int L =0,R=a.size()-1;
            while(L<=R) {
                int M = L+(R-L)/2;
                if(a[M]==t) {
                    return true;
                }
                if(t<a[M]) R=M-1; else L=M+1;
            }
        }
        return false;
    }
};