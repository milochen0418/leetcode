class Solution {
    //https://leetcode.com/problems/climbing-stairs
public:
    int climbStairs(int n) {
        return sol_backtrace(0,n);   
    }
    int sol_backtrace(int start, int end) {        
        if(end-start==0) return 1;
        if(end-start<0) return 0;
        return sol_backtrace(start+2,end) + sol_backtrace(start+1,end);
    }
};