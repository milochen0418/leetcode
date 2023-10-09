class Solution {
    //https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        //10^6 is similar to 2^20. So we only have 20 bits;
        //The primes are 2,3,5,7,11,13,17,19
        vector<int> is_prime = {
            0,0,1,1,0,1,0,1,0,0,
            0,1,0,1,0,0,0,1,0,1,
        };
        for(int val = left; val<=right; val++) {
            int bitcnt = 0, v=val;
            while(v>0) {
                bitcnt += v%2;
                v/=2;
            }
            if(is_prime[bitcnt]) ans++;
        }
        return ans;
    }
};