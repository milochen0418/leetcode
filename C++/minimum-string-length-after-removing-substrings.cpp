class Solution {
    //https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
public:
    int minLength(string s) {
        int flag=1;
        while(flag) {
            flag = 0;
            if(removeAB(s)) flag = 1;
            if(removeCD(s)) flag = 1;
        }
        return (int)s.length();
    }
    int removeAB(string &s) {
        string newStr = "";
        int n = s.length();
        int retV = 0;
        for(int i = 0; i<n;i++) {
            if(s[i] == 'A' && i+1<n && s[i+1] == 'B') {
                i+=1;
                retV = 1;
            } else {
                newStr.push_back(s[i]);
            }
        }
        s = newStr;
        return retV;
    }
    int removeCD(string &s) {
        string newStr = "";
        int n = s.length();
        int retV = 0;
        for(int i = 0; i<n;i++) {
            if(s[i] == 'C' && i+1<n && s[i+1] == 'D') {
                i+=1;
                retV = 1;
            } else {
                newStr.push_back(s[i]);
            }
        }
        s = newStr;
        return retV;
    }
};