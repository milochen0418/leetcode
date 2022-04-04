class Solution {
    //https://leetcode.com/problems/peak-index-in-a-mountain-array/
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int L=1,R=a.size()-2;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(a[M+1]>a[M]) {
                L=M+1;
            } else if(a[M-1]>a[M]) {
                R=M-1;
            } else {
                return M;
            }
        }
        return -1;
    }
};