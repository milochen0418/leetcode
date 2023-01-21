class Solution {
    //https://leetcode.com/problems/binary-number-with-alternating-bits
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n>0) {
            if(n%2==prev) {
                return false;
            } else {
                prev=n%2;
            }
            n/=2;
        }
        return true;
    }
};