class Solution {
    //https://leetcode.com/problems/counting-bits
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i = 0; i<=n; i++) {
            int cnt=0;
            for(int j = 0; j<30; j++) {
                if( (i & (1<<j)) > 0) {
                    cnt++;
                }
            }
            ans[i] = cnt;  
        }
        return ans;
    }
};

/* testcase 
100000
*/