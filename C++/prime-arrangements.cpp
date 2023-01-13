class Solution {
    //https://leetcode.com/problems/prime-arrangements
public:
    typedef long long ll;
    int numPrimeArrangements(int n) {
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
        ll a = _a;
        ll b = _b;
        const ll mod = 1e9+7;
        return (int)(((a%mod)*(b%mod))%mod);
    }
    int factorial(int k) {
        int ans = 1;
        for(int i = 1;i<=k;i++) 
            ans = mul(i,ans);
        return ans;
    }
};