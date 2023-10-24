class Solution {
    //https://leetcode.com/problems/number-of-ways-to-split-array
    //article https://leetcode.com/problems/number-of-ways-to-split-array/discuss/4203016/C%2B%2B-or-Two-Pass-or-simple-8-lines
public:
    int waysToSplitArray(vector<int>& nums) {
        typedef long long ll;
        ll sum = 0,total=0,n = nums.size(), ans=0;
        for(auto &i: nums) total+=i;
        for(ll i = 0;i<n-1;i++) {
            ll val = nums[i];
            sum+=val, total-=val;
            if(sum>=total) ans++;
        }
        return (int)ans;
    }
};