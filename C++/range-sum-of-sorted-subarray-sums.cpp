class Solution {
    //https://leetcode.com/problems/range-sum-of-sorted-subarray-sums
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        typedef long long ll;
        const ll MOD = 1e9+7;
        vector<ll> v;
        for(int i = 0; i<n;i++) {
            ll subarraysum = 0;
            for(int j = i;j<n;j++) {
                subarraysum+=nums[j];
                subarraysum=subarraysum % MOD;
                v.push_back(subarraysum);
            }
        }
        sort(v.begin(), v.end());
        ll ans=0;
        for(int i = left-1;i<right;i++) {
            ans+=v[i];
            ans=ans%MOD;
        }
        return (int)ans;
    }
};