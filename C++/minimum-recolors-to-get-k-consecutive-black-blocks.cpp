class Solution {
    //https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks
public:
    int minimumRecolors(string blocks, int k) {
        int maxv = 0, cur=0, n=blocks.size();
        for(int i = 0; i<k;i++) cur+=(blocks[i]=='B');
        maxv = cur;
        
        for(int i=k;i<n;i++) {
            cur = cur -(blocks[i-k]=='B') + (blocks[i]=='B');
            maxv = max(maxv, cur);
        }
        return k-maxv;
    }
};