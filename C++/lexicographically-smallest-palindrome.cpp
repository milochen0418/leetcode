class Solution {
    //https://leetcode.com/problems/lexicographically-smallest-palindrome/
    /*
     e f c f e
     |       |
       |   | 
         |
    abba
    |  |
     ||
     
    */
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        int L = 0, R=n-1;
        while(L<=R) {
            char minc = min(s[L], s[R]);
            s[L++] = minc;
            s[R--] = minc;
        }
        return s;
            
    }
};