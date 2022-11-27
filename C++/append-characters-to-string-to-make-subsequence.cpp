class Solution {
    //https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
public:
    int appendCharacters(string s, string t) {
        int m = s.length(), n = t.length();
        int i =0 , j=0;
        
        while(i<m && j<n) {
            if(s[i] == t[j]) {
                j++;
                i++; 
            } else {
                i++;
            }
        }
        return n-j;
        
    }
};