class Solution {
    //https://leetcode.com/problems/check-if-point-is-reachable
    //article https://leetcode.com/problems/check-if-point-is-reachable/discuss/3082600/C%2B%2B-Two-Pass-O(logN)-3-lines
public:
    bool isReachable(int targetX, int targetY) {
        while(targetX%2==0)targetX/=2;
        while(targetY%2==0)targetY/=2;
        return gcd(targetX, targetY)==1;
    }
};