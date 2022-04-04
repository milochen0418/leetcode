class Solution {
    //https://leetcode.com/problems/search-insert-position/
public:
    int searchInsert(vector<int>& a, int target) {
        int L=0, R=a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(target > a[M]) {
                L=M+1;
            } else if(target < a[M]) {
                R=M-1;
            } else { //a[M]==target
                return M;
            }
        }
        return L;
    }
};