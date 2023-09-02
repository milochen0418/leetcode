class Solution {
    //https://leetcode.com/problems/furthest-point-from-origin/
public:
    int furthestDistanceFromOrigin(string moves) {
        int L=0,R=0, cnt=0;
        for(auto &c:moves) {
            L+=c=='L';
            R+=c=='R';
            cnt+=c=='_';
        }
        return abs(R-L) + cnt;
    }
};