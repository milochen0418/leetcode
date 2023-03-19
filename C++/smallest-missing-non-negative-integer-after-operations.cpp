class Solution {
    //https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
public:
    typedef long long ll;
    int findSmallestInteger(vector<int>& nums, int value) {
        ll mod = value;
        ll offset = (ll)INT_MAX; //int_min
        offset = (offset + mod) - offset % mod;        
        //unordered_set<ll> s;
        unordered_map<ll,int> mp;
        for(auto &i:nums) {
            ll v = (ll)i + offset;
            v = v%mod;
            mp[v]++;
        }
        int mincnt = INT_MAX;
        for(ll i=0;i<(ll)value;i++) {
            if(mp.find(i) == mp.end()) return (int)i;
            if(mp[i]<mincnt) mincnt = mp[i];
        }
        
        for(ll i=0;i<(ll)value;i++) {
            if(mp[i] == mincnt) {
                return ((int)i + mincnt*value);
            }
        }
        
        /*
[3,0,3,2,4,2,1,1,0,4]
5

Output 5
Expected 10
        */
        return -1;
    }
};