class Solution {
    //https://leetcode.com/problems/minimum-operations-to-make-array-equal
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i+=2) ans+=(n-i);
        return ans;
    }
};