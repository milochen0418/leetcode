class Solution {
    //https://leetcode.com/problems/minimum-moves-to-convert-string/
public:    
    int minimumMoves(string s) {
        int ans=0, n=s.length();
        for(int i=0;i<n;i++) {
            if(s[i]=='X') {
                ans++;
                i=i+2;
            }
        }
        return ans;
    }
};