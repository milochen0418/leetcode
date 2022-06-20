class Solution {
    //https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0; // If there are no valid pairs, return 0.
        for(int i = 0; i<nums1.size();i++) {
            int t = nums1[i], n=nums2.size(), L=i,R=n-1;
            vector<int> &a = nums2;
            while(L<=R) {
                int M = L + (R-L)/2;
                if( (M+1>n-1 || a[M+1] < t) && t<=a[M]) {
                    ans = max(ans,M-i);
                    //printf("i=%d, M=%d, M-i=%d\n",i,M,M-i);
                    break;
                }
                if(t<=a[M]) L=M+1; else R=M-1;
            }
        }
        return ans;
    }
};