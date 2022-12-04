class Solution {
    //https://leetcode.com/problems/minimum-cuts-to-divide-a-circle
public:
    int numberOfCuts(int n) {
        return n%2==0?n/2:(n==1?0:n);
    }
};