class Solution {
    //https://leetcode.com/problems/find-first-palindromic-string-in-the-array
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &w:words) {
            int L = 0, R=w.length()-1;
            bool is_palindrome = true;
            while(L<=R) {
                if(w[L++] != w[R--]) {
                    is_palindrome = false;
                    break;
                }
            }
            if(is_palindrome) return w;
        }
        return "";
    }
};