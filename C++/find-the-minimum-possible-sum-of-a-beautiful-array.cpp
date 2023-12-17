class Solution {
    //https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array
public:
    int minimumPossibleSum(int n, int target) {
        typedef long long ll;
        unordered_set<ll> imset; //impossible set
        unordered_set<ll> selset;//selected set
        for(int i = 1; i<2*n;i++) {
            if(imset.find(i) != imset.end()) continue;
            selset.insert(i);
            if(target-i>i) imset.insert(target-i);
            if(selset.size()>=n) break;
        }
        ll ans = 0;
        const ll MOD = 1e9+7;
        for(auto &i:selset) {
            ans = ((ans%MOD) + ((ll)i%MOD)) % MOD;
            //ans+=(ans + (ll)i)%MOD ;
        }
        return (int)ans;
    }
};