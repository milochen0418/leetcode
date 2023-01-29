class Solution {
    //https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/
public:
    typedef long long ll;
    const ll M = 1e9+7;
    ll qpow(ll a,ll b){
        ll res = 1;
        while(b){
            if(b&1) res = res*a%M;
            a = a*a%M;
            b >>= 1;
        }
        return res;	
    }
    ll PowerOfTwo(int n){
        string x = to_string(n);
        ll M_1 = M-1, k = x[0]-'0';
        for(int i = 1;x[i];i++) {
            k = (k*10+x[i]-'0') % M_1;
        }
        ll ans = qpow(2,k); 
        return ans%M;
    }
    
    int monkeyMove(int n) {        
        ll total = PowerOfTwo(n);
        return ((total%M)-2+M)%M;
    }
};