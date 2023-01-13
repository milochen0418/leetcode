class Solution {
    //https://leetcode.com/problems/prime-arrangements
public:
    typedef long long ll;
    const ll mod = 1e9+7;
    const vector<int> isPrime={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0
};
    const vector<int> isPrimePrefix = {0,0,1,2,2,3,3,4,4,4,4,5,5,6,6,6,6,7,7,8,8,8,8,9,9,9,9,9,9,10,10,11,11,11,11,11,11,12,12,12,12,13,13,14,14,14,14,15,15,15,15,15,15,16,16,16,16,16,16,17,17,18,18,18,18,18,18,19,19,19,19,20,20,21,21,21,21,21,21,22,22,22,22,23,23,23,23,23,23,24,24,24,24,24,24,24,24,25,25,25,25};
    
    int numPrimeArrangements(int n) {
        //Solution of pre-built prime prefix table
        int cnt_prime = isPrimePrefix[n];
        return mul(factorial(cnt_prime), factorial(n-cnt_prime));
    }
    int numPrimeArrangements_v03(int n) {
        //Solution of pre-built prime table
        int cnt_prime=0;
        /*
        for(int i = 1;i<=100;i++) isPrime[i]+=isPrime[i-1];
        for(int i = 0;i<=100;i++) printf("%d,",isPrime[i]);
        */
        for(int i = 1;i<=n;i++) if(isPrime[i]) cnt_prime++;
        return mul(factorial(cnt_prime), factorial(n-cnt_prime));
    }
    
    int numPrimeArrangements_v02(int n) {
        //Solution of prime alogrithm
        vector<int> is_prime = vector<int>(101,1);
        int cnt_prime = is_prime[0] = is_prime[1] = 0;
        for(int i = 2;i<=n;i++) if(is_prime[i]) {
            cnt_prime++;
            for(int j = i+i;j<=n;j+=i) is_prime[j] = 0;
        }
        //for(int i = 0;i<=100;i++) printf("%d,",is_prime[i]);
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