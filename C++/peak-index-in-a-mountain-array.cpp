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
    int peakIndexInMountainArrayAnswer2(vector<int>& a) {
        int L = 1, R=a.size()-2;
        while(L<=R) {
            int M = L + (R-L)/2;
            if(a[M-1]<a[M] && a[M]>a[M+1]) return M; //case match  
            if(a[M-1]>a[M]) { //case which is too large
                R = M-1;
            } else { // case which is too small
                L = M+1;
            }
        }
        return -1;
    }
};