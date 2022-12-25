class Solution {
    //https://leetcode.com/problems/latest-time-by-replacing-hidden-digits
    //article https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/discuss/2950549/C%2B%2B-or-100-faster
public:
    string& maximumTime(string &time) {
        string &s= time;
        if(s[0] == '?' && s[1] == '?') {
            s[0]='2';
            s[1]='3';
        }
        if(s[0]=='?') {
            if(s[1]<='3')
                s[0]='2';
            else
                s[0]='1';
        }
        if(s[1]=='?') {
            if(s[0]<'2')
                s[1]='9';
            else
                s[1]='3';
        }
        if(s[3]=='?') s[3]='5';
        if(s[4]=='?') s[4]='9';
        return s;
    }
};