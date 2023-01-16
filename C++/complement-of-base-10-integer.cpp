class Solution {
    //https://leetcode.com/problems/complement-of-base-10-integer
public:
    int bitwiseComplement(int n) {
        int ans=0, base = 1;
        if(n==0) return 1;
        while(n>0) {
            ans+=base*(n%2==0);
            base*=2;
            n/=2;
        }
        return ans;
    }
};