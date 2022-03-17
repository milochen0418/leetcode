class Solution {
    //https://leetcode.com/problems/score-of-parentheses
public:
    int scoreOfParentheses(string s) {
        int cnt= 0;
        int sum = 0;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                ++cnt;
            } else if(s[i]==')') {
                --cnt;
            }
            if(i-1>=0 && s[i-1]=='(' && s[i]==')') {
                sum += 1<<cnt;
            }
            
        }
        return sum;
    }
    
    //stack approach
    int answer1(string& s) {
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
    //in-place stack approach but overflow
    //T=O(N), S=O(1)
    int answer2(string& s) {
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
    //in-place stack approach without overflow
    //T=O(N), S=O(1)
    int answer3(string& s) {
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
    //count approach 
    //T=O(N), S=O(1)
    int answer4(string& s) {
        int cnt= 0;
        int sum = 0;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                ++cnt;
            } else if(s[i]==')') {
                --cnt;
            }
            if(i-1>=0 && s[i-1]=='(' && s[i]==')') {
                sum += 1<<cnt;
            }
            
        }
        return sum;
    }
};