class Solution {
    // https://leetcode.com/problems/is-subsequence
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n==0) return true;
        if(n>m) return false;
        int i=0;
        for(int j=0;j<m;j++) {
            if(s[i] == t[j]) {
                i++;
                if(i>=n) return true;
            }
        }
        return false;
    }
};