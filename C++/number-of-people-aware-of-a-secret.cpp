class Solution {
    //https://leetcode.com/problems/number-of-people-aware-of-a-secret
    //article https://leetcode.com/problems/number-of-people-aware-of-a-secret/discuss/2233104/C%2B%2B-or-simulate-approach-or-easy-to-understand
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> a(n+forget,0);
        a[1]=1;
        for(int i = 1;i<=n;i++) 
            for(int j = delay; j<forget;j++) 
                a[i+j] = mod_add(a[i+j], a[i]);
        for(int i=1;i<=n;i++) 
            a[i] = mod_add(a[i], a[i-1]);
        return mod_add(a[n], -a[n-forget]);
    }
    int mod_add(int a, int b){
        const int MOD=1e9+7;
        (a+=MOD)%=MOD;
        (b+=MOD)%=MOD;
        return (a+b)%MOD;
    }
};