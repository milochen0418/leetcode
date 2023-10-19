class Solution {
    //https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array
    //article https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/discuss/4186023/C%2B%2B-One-Pass-O(N)-simple-8-lines
public:
    typedef long long ll;
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> conver = vector<ll>(n,0);
        ll maxv = (ll)(INT_MIN);
        for(int i = 0; i<n; i++) {
            maxv = max(maxv, (ll)nums[i]);
            conver[i] = (ll)nums[i] + maxv;
            if(i>0)conver[i] += conver[i-1];
        }
        return conver;
    }
};