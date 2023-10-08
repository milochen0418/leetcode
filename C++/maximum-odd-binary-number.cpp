class Solution {
    //https://leetcode.com/problems/maximum-odd-binary-number
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0, n = s.length();
        for(auto &c: s) cnt+=(c=='1');
        for(int i = 0; i<n-1;i++) 
            s[i] = i<cnt-1?'1':'0';
        s[n-1] = '1';
        return s;
    }
};