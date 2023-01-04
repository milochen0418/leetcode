class Solution {
    //https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses
public:
    int maxDepth(string s) {
        int cntl=0,cntr=0, ans=0;
        for(auto &c:s) {
            if(c=='(')cntl++;
            if(c==')')cntr++;
            ans = max(ans, cntl-cntr);
        }   
        return ans;
    }
};