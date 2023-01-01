class Solution {
    //https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/
public:
    int minimumPartition(string s, int kk) {
        int ans = 0;
        typedef long long ull;
        ull k = kk;
        ull n = 0;
        for(auto &c:s) {
            int d = c-'0';
            if(n*10+ d <= k) {
                n = n*10+ d;
            } else {
                if(n<=k) {
                    ans++;
                    n=d;
                } else {
                    return -1;
                }
            }
        }
        ans++;
        return ans;
    }
};