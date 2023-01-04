class Solution {
    //https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters
public:
    string modifyString(string s) {
        int n = s.length();
        for(int i = 0; i<n;i++) {
            if(s[i]=='?') {
                char prev=i-1>=0?s[i-1]:'#';
                char next=i+1<n?s[i+1]:'#';
                for(char c='a';c<='z';c++) 
                    if(c!=prev && c!=next) {
                        s[i] = c;
                        break;
                    }                
            }
        }
        return s;
    }
};