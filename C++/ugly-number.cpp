class Solution {
    //https://leetcode.com/problems/ugly-number
    //article: https://leetcode.com/problems/ugly-number/discuss/2862140/C%2B%2B-or-O(N)
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        for(auto &i:{2,3,5}) while(n%i==0) n/=i;
        return n == 1;
    }
};