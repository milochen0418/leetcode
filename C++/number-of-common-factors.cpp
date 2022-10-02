class Solution {
    //https://leetcode.com/problems/number-of-common-factors/
public:
    int commonFactors(int a, int b) {
        int q = gcd(a,b);
        int ans = 0;
        for(int i = 1; i <= q; i++) {
            if(q%i==0) ans++;
        }
        return ans;
    }
};