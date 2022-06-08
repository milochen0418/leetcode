class Solution {
    //https://leetcode.com/problems/remove-palindromic-subsequences
    //article https://leetcode.com/problems/remove-palindromic-subsequences/discuss/2125167/C%2B%2B-or-two-pointers-or-explanation
public:
    int removePalindromeSub(string s) {
        int L = 0, R=s.length()-1;
        if(L>R) return 0;
        while(L<=R) if(s[L++]!=s[R--])return 2;
        return 1;
    }
};