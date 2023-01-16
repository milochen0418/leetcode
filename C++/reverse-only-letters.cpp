class Solution {
    //https://leetcode.com/problems/reverse-only-letters
    //article https://leetcode.com/problems/reverse-only-letters/discuss/3057687/C%2B%2B-One-Pass-O(N)-9-lines
public:
    #define is_letter(c)  ( ('Z'>=(c)&&(c)>='A') || ('z'>=(c)&&(c)>='a') )
    string reverseOnlyLetters(string s) {
        int n = s.length(), L = 0, R=n-1;
        while(L<R) {
            while(L<n && !is_letter(s[L]))L++;
            while(R>=0 && !is_letter(s[R]))R--;
            if(R<0 || L>=n) break;
            if(L>=R) break;
            swap(s[L++],s[R--]);
        }
        return s;
    }
};