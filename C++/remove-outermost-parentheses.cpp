class Solution {
    //https://leetcode.com/problems/remove-outermost-parentheses
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans;
        for(auto &c:s) {
            if(c=='(') {
                if(cnt!=0) ans.push_back(c);
                cnt = cnt + 1;
            } else {//c is ')'
                if(cnt!=1) ans.push_back(c);
                cnt = cnt - 1;
            }
        }
        return ans;
    }
};