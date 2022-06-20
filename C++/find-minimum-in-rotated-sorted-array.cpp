class Solution {
    //https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
    //article https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/2174061/C%2B%2B-or-binary-search-or-easy-understand
public:
    int findMin(vector<int>& nums) {
        vector<int> &a = nums;
        int n=a.size(), L = 0, R=n-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            //printf("L=%d, R=%d, -> M=%d\n",L,R, M);
            if(a[M] >= a[(M+1)%n]) return a[(M+1)%n];
            //change > into >= to process the testcase [1]
            if(a[M]<a[R] && a[R]<a[L]) R=M-1; else L=M+1;
            //printf("Finally, L=%d, R=%d\n",L,R);
        }
        return -1;
    }
};