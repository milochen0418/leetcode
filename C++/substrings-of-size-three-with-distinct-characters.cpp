class Solution {
    //https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters
public:
    int countGoodSubstrings(string s) {
        int ans =0, n = s.length();
        for(int i = 0;i<n-2;i++) 
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]) ans++;
        return ans;
    }
};