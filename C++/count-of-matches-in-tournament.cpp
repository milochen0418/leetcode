class Solution {
    //https://leetcode.com/problems/count-of-matches-in-tournament
public:
    int numberOfMatches(int n) {
        int ans=0;
        while(n>1) {
            ans+=n/2;
            n=n/2+n%2;
        }
        return ans;
    }

    int numberOfMatches_v01(int n) {
        int ans=0;
        while(n>1) {
            if(n%2==0) {
                ans+=n/2;
                n=n/2;
            } else {
                ans+=(n-1)/2;
                n=((n-1)/2) + 1;
            }
        }
        return ans;
    }
};