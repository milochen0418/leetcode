class Solution {
    //https://leetcode.com/problems/count-primes/
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int> is_prime = vector<int>(n,1);
        int cnt_prime = is_prime[0] = is_prime[1] = 0;
        for(int i = 2;i<n;i++) if(is_prime[i]) {
            cnt_prime++;
            for(int j = i+i;j<n;j+=i) is_prime[j] = 0;
        }
        return cnt_prime;
    }
};