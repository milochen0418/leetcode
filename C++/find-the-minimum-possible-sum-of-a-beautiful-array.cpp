class Solution {
    //https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array
public:
    int minimumPossibleSum(int n, int target) {
    }
    int minimumPossibleSum_v02(int n, int target) {
        //7,15
        //1 ,2 ,3 ,4 ,5, 6, 7
        //14,13,12,11,10,9, 8
        //15-1/2
        
        //7,16
        //1 ,2 ,3 ,4 ,5, 6, 7, "8"
        //15,14,13,12,11,10,9,
        
        //The solution is Time Limit Exceeded
        typedef long long ll;
        const ll MOD = 1e9+7;
        ll ans = 0;
        int cnt = 0;
        for(int i = 1; i<=(target-1)/2; i++) {
            ans = ((ans%MOD) + ((ll)i%MOD)) % MOD;
            cnt++;
            if(cnt>=n) return ans;
        }
        if(target%2==0) {
            ans+=target/2;
            cnt++;
            if(cnt>=n) return ans;
        }
        
        for(int i = target;i<n+target;i++){
            ans = ((ans%MOD) + ((ll)i%MOD)) % MOD;
            cnt++;
            if(cnt>=n) return ans;
        }
        return (int)ans;    
    }
    int minimumPossibleSum_v01(int n, int target) {
        //Memory Limit Exceeded
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