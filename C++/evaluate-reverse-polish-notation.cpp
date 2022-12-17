class Solution {
    //https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/2919712/C%2B%2B-or-Stack
public:
    int evalRPN(vector<string>& tokens) {
        typedef long long ll;
        stack<string> stk;
        for(auto &s: tokens) {
            if((s[0]>='0' && s[0]<='9') || (s[0]=='-' && s.length()>1)) {
                stk.push(s);
            } else {
                ll rhs = stoll(stk.top());
                stk.pop();
                ll lhs = stoll(stk.top());
                stk.pop();
                ll result = 0;
                switch(s[0]) {
                    case '+':
                        result = lhs+rhs;
                        break;
                    case '-':
                        result = lhs-rhs;
                        break;
                    case '*':
                        result = lhs*rhs;
                        break;
                    case '/':
                        result = lhs/rhs;
                        break;
                }
                stk.push(to_string(result));
            }
        }
        return stoi(stk.top());
    }
};