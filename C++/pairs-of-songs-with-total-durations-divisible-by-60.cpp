class Solution {
    //https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        typedef long long ll;
        vector<ll> mp = vector<ll>(60,0);
        for(auto &t:time) mp[(t%60)]++;
        int ans = 0;
        ans+=(int) ((mp[0]*(mp[0]-1) )/2);
        ans+=(int) ((mp[30]*(mp[30]-1) )/2);
        for(int i = 1;i<=29;i++) ans+=mp[i]*mp[60-i];
        return ans;
    }
};