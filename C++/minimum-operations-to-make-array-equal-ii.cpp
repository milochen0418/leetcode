class Solution {
    //https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/
public:
    typedef long long ll;
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1==nums2) return 0;
        //Start to find out all possible failed cases.
        if(k==0) return -1;
        int n = nums1.size();
        ll sum1 =0, sum2=0;
        for(auto &i:nums1)sum1+=i;
        for(auto &i:nums2)sum2+=i;
        if(sum1!=sum2) return -1;
        for(int i = 0;i<n;i++) 
            if( abs(nums1[i]-nums2[i])%k !=0) 
                return -1;
        
        //Here , we ensure that the answer can be found.
        vector<int> A = vector<int>(n,0);
        for(int i = 0; i<n;i++) 
            A[i] = nums1[i] - nums2[i];
        for(auto &i:A) i/=k;
        ll poscnt=0;
        for(auto &i:A) if(i>0) poscnt+=i;
        return poscnt;
    }
};