class Solution {
    //https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array
public:
    int minimumPossibleSum(int n, int target) {
        //7,15
        //1 ,2 ,3 ,4 ,5, 6, 7
        //14,13,12,11,10,9, 8
        //ans = 28

        //8,15
        //1 ,2 ,3 ,4 ,5, 6, 7
        //14,13,12,11,10,9, 8
        //ans = 28+15=43
        
        //9,15
        //1 ,2 ,3 ,4 ,5, 6, 7
        //14,13,12,11,10,9, 8
        //ans = 43+16=59
        //28 + ((15+16)*2)/2

        //9,15
        //1,2,3,4,5,6,7
        
        
        //7,16
        //1 ,2 ,3 ,4 ,5, 6, 7, "_"
        //15,14,13,12,11,10,9,
        //ans is 28

        //8,16
        //1 ,2 ,3 ,4 ,5, 6, 7, "8"
        //15,14,13,12,11,10,9,
        //ans is 36
        
        typedef long long ll;
        const ll MOD = 1e9+7;
        ll ans = 0;
        ll Lcnt = 0; //total count of the selected number before target 
        Lcnt = (target-1)/2 - 1 + 1;
        ll downwidth = 1, upwidth = (target-1)/2; 
        if(target%2==0) {
            Lcnt++;
            upwidth += 1;
        }
       
        if(n<=Lcnt) {
            downwidth = 1;
            upwidth = n;
            ll high = n; 
            ll updown = ((upwidth%MOD) + (downwidth%MOD)) % MOD;
            ll twoarea = ((updown%MOD) * (high%MOD)) % MOD;
            return twoarea/2;
        } else {
            downwidth = 1;
            upwidth = Lcnt;
            ll high = Lcnt; 
            ll updown = ((upwidth%MOD) + (downwidth%MOD)) % MOD;
            ll twoarea = ((updown%MOD) * (high%MOD)) % MOD;
            n-=Lcnt;
            ans = twoarea; 
        }

        downwidth = target;
        upwidth = target -1+ n;
        ll newhigh = n;
        ll newupdown = ((upwidth%MOD) + (downwidth%MOD)) % MOD;
        ll newtwoarea = ((newupdown%MOD) * (newhigh%MOD)) % MOD;
        ans = ((ans%MOD) + (newtwoarea%MOD)) %MOD;
        return ans/2;
        
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