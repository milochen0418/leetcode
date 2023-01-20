class Solution {
    //https://leetcode.com/problems/reverse-words-in-a-string-iii
public:
    string reverseWords(string s) {
        int L = 0,R=0,n=s.length();
        for(int i = 0;i<n;i++) {
            if(s[i]==' ' || i==n-1) {
                R=i==n-1?i:i-1;
                while(L<=R)swap(s[L++],s[R--]);
                L=i+1;
            }
        }
        return s;
    }
};