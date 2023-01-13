class Solution {
    //https://leetcode.com/problems/prime-arrangements
    //article https://leetcode.com/problems/prime-arrangements/discuss/3044291/C%2B%2B-O(1)
public:
    typedef long long ll;
    const ll mod = 1e9+7;
    const vector<int> isPrime={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0
};
    const vector<int> isPrimePrefix = {0,0,1,2,2,3,3,4,4,4,4,5,5,6,6,6,6,7,7,8,8,8,8,9,9,9,9,9,9,10,10,11,11,11,11,11,11,12,12,12,12,13,13,14,14,14,14,15,15,15,15,15,15,16,16,16,16,16,16,17,17,18,18,18,18,18,18,19,19,19,19,20,20,21,21,21,21,21,21,22,22,22,22,23,23,23,23,23,23,24,24,24,24,24,24,24,24,25,25,25,25};
    const vector<int> factorial_tbl ={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,227020758,178290591,674358851,789741546,425606191,660911389,557316307,146326063,72847302,602640637,860734560,657629300,440732388,459042011,394134213,35757887,36978716,109361473,390205642,486580460,57155068,943272305,14530444,523095984,354551275,472948359,444985875,799434881,776829897,626855450,954784168,10503098,472639410,741412713,846397273,627068824,726372166,318608048,249010336,948537388,272481214,713985458,269199917,75195247,286129051,595484846,133605669,16340084,996745124,798197261,286427093,331333826,536698543,422103593,280940535,103956247,172980994,108669496,715534167,518459667,847555432,719101534,932614679,878715114,661063309,562937745,472081547,766523501,88403147,249058005,671814275,432398708,753889928,834533360,604401816,187359437,674989781,749079870,166267694,296627743,586379910,119711155,372559648,765725963,275417893,990953332,104379182,437918130};
    int numPrimeArrangements(int n) {
        int cnt_prime = isPrimePrefix[n];
        //return mul(factorial(cnt_prime), factorial(n-cnt_prime));
        return mul(factorial_tbl[cnt_prime], factorial_tbl[n-cnt_prime]);
    }
    int numPrimeArrangements_v04(int n) {
        //Solution of pre-built prime prefix table
        int cnt_prime = isPrimePrefix[n];
        //for(int i =1;i<=100;i++) printf("%d,", factorial(i));
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