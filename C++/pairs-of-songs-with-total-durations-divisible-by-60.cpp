class Solution {
    //https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
    //article https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/4351010/C%2B%2B-time-O(N)-space-O(1)-but-integer-array-only
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mp = vector<int>(60,0);
        for(auto &t:time) mp[(t%60)]++;
        int ans = 0;
        for(int i = 0;i<=30;i+=30) {
            int n=mp[i];
            if(n%2==0) {
                int c = n/2;
                ans+=(c*c*2-c);
            } else {
                int a = (n+1)/2, b = (n-1)/2;
                ans+= (a*b*2-b);
            }
        }
        for(int i = 1;i<=29;i++) ans+=mp[i]*mp[60-i];
        return ans;
    }
    int numPairsDivisibleBy60_v01(vector<int>& time) {
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