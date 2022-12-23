class Solution {
    //https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros
public:
    bool checkZeroOnes(string s) {
        int c0=0,c1=0,maxc0=0, maxc1=0,n=s.length();
        (s[0]=='0'?c0:c1)=1;
        maxc0=max(maxc0,c0);
        maxc1=max(maxc1,c1);
        for(int i=1;i<n;i++) {
            if(s[i-1]==s[i])
                (s[i]=='0'?c0:c1)++;
            else {
                c0=c1=0;
                (s[i]=='0'?c0:c1)=1;
            } 
            maxc0=max(maxc0,c0);
            maxc1=max(maxc1,c1);
        }
        return maxc1>maxc0;
    }
};