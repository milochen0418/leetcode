class Solution {
    //https://leetcode.com/problems/maximum-score-after-splitting-a-string
public:
    int maxScore(string s) {
        int n = s.length();
        int L = 0,R=0; 
        for(int i = 1; i<n;i++) R+=s[i]=='1';
        L = s[0]=='0';
        
        int maxv = L+R;
        for(int i = 1; i<n-1;i++) {
            if(s[i]=='1') 
                R--;
            else 
                L++;
            maxv = max(maxv, L+R) ;
        }
        return maxv;
        
    }
};