class Solution {
    //https://leetcode.com/problems/power-of-two
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (0==(1<<30)%n);
    }
};