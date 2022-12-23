class Solution {
    //https://leetcode.com/problems/replace-all-digits-with-characters
public:
    string replaceDigits(string s) {
        for(int i = 1,n=s.length();i<n; i+=2) s[i] = s[i-1] + (s[i]-'0');
        return s;
    }
};