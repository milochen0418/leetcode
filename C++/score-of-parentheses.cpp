class Solution {
    //https://leetcode.com/problems/score-of-parentheses
public:
    int scoreOfParentheses(string s) {
        //stack<int> stk;
        int stk_idx=-1;
        int sum = 0;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                //stk.push( stk.empty()?1:stk.top()*2);
                s[++stk_idx] = stk_idx==-1?0:s[stk_idx]+1;
            } else {//s[i]==')'
                //sum +=stk.top();
                //sum +=s[stk_idx];
                sum += 1<<s[stk_idx];
                //stk.pop();
                --stk_idx;
                while(i+1<n && s[i+1]==')') {
                    i++;
                    //stk.pop();
                    --stk_idx;
                }
            }
        }
        return sum;
    }


    int answer1(string s) {
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
    int answer2(string s) {
        //stack<int> stk;
        int stk_idx=-1;
        int sum = 0;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                //stk.push( stk.empty()?1:stk.top()*2);
                s[++stk_idx] = stk_idx==-1?1:s[stk_idx]*2;
            } else {//s[i]==')'
                //sum +=stk.top();
                sum +=s[stk_idx];
                //stk.pop();
                --stk_idx;
                while(i+1<n && s[i+1]==')') {
                    i++;
                    //stk.pop();
                    --stk_idx;
                }
            }
        }
        return sum;
    }
      
};