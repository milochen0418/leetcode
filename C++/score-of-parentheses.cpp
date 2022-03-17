class Solution {
    //https://leetcode.com/problems/score-of-parentheses
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int sum = 0;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                stk.push( stk.empty()?1:stk.top()*2);
            } else {//s[i]==')'
                sum +=stk.top();
                stk.pop();
                while(i+1<n && s[i+1]==')') {
                    i++;
                    stk.pop();
                }
            }
        }
        return sum;
    }
};