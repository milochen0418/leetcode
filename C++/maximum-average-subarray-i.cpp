class Solution {
    //https://leetcode.com/problems/maximum-average-subarray-i
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        typedef long long ll;
        vector<ll> A = vector<ll>(n,(ll)nums[0]);
        for(int i = 1;i<n;i++) 
            A[i]=A[i-1] +(ll)nums[i];
        //Assume k=3, n=6
        //[0,1,2,3,4,5] ->  [0,1,2], [1,2,3], [2,3,4],[3,4,5]
        ll maxv = (ll)INT_MIN;
        for(int i=n-1;i>=k-1;i--) {
            ll Ai_k = i-k<0?0:A[i-k];
            maxv = max(maxv, A[i] - Ai_k);
        }
        double ans = double(maxv)/double(k);
        return ans;
    }
};