class Solution {
    //https://leetcode.com/problems/to-lower-case
public:
    string toLowerCase(string s) {
        for(int i = 0; i<s.length();i++) if(s[i]>='A' && s[i]<='Z') s[i] = s[i]-'A'+'a';
        return s;        
    }
};