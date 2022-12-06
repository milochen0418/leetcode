class Solution {
    //https://leetcode.com/problems/minimum-moves-to-convert-string/
public:
    int minimumMoves(string s) {
        int L=0,R=0,n=s.length(), ans=0;
        while(L<n && R<n) {
            if(s[L]!='X') {
                ++L;
                R=L;
            } else {
                while(R<n && s[R]=='X')++R;
                int gap = R-L;
                ans += (gap/3) + (gap%3>0);
                L=R;
            }
        }
        return ans;
    }
};