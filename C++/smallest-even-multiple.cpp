class Solution {
    //https://leetcode.com/problems/smallest-even-multiple/
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0) return n;
        return 2*n;
    }
};