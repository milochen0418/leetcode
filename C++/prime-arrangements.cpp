class Solution {
    //https://leetcode.com/problems/prime-arrangements
public:
    typedef long long ll;
    const ll mod = 1e9+7;
    int numPrimeArrangements(int n) {
        vector<int> is_prime = vector<int>(101,1);
        int cnt_prime = is_prime[0] = is_prime[1] = 0;
        for(int i = 2;i<=n;i++) if(is_prime[i]) {
            cnt_prime++;
            for(int j = i+i;j<=n;j+=i) is_prime[j] = 0;
        }     
        return mul(factorial(cnt_prime), factorial(n-cnt_prime));
    }
    
    int numPrimeArrangements_v01(int n) {
        vector<int> is_prime = vector<int>(101,1);
        is_prime[0] = is_prime[1] = 0;
        for(int i = 2;i<=n;i++) 
            if(is_prime[i]==1) 
                for(int j = i+i;j<=n;j+=i) 
                    is_prime[j] = 0;
        int cnt_prime = 0;
        int cnt_combine = 0;
        for(int i = 1; i<=n;i++) 
            (is_prime[i]==1?cnt_prime:cnt_combine)++;
        return mul(factorial(cnt_prime), factorial(cnt_combine));
    }
    int mul(int _a, int _b) {
        ll a = _a, b = _b;
        return (int)(((a%mod)*(b%mod))%mod);
    }
    int factorial(int k) {
        int ans = 1;
        for(int i = 1;i<=k;i++) ans = mul(i,ans);
        return ans;
    }
};