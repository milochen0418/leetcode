class Solution {
    //https://leetcode.com/problems/divisible-and-non-divisible-sums-difference
public:
    int differenceOfSums(int n, int m) {
        int ans=0;
        for(int i=1;i<=n;i++) ans += i*((i%m!=0)*2-1);
        return ans;
    }
};