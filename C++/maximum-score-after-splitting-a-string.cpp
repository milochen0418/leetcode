class Solution {
    //https://leetcode.com/problems/maximum-score-after-splitting-a-string
    //article https://leetcode.com/problems/maximum-score-after-splitting-a-string/discuss/3024443/C%2B%2B-Two-Pass-O(N)-9-lines
public:
    int maxScore(string s) {
        int n = s.length(), L=0,R=0; 
        for(int i = 1; i<n;i++) R+=s[i]=='1';
        L = s[0]=='0';
        int maxv = L+R;
        for(int i = 1; i<n-1;i++) {
            s[i]=='1'?R--:L++;
            maxv = max(maxv, L+R) ;
        }
        return maxv;
    }

    int maxScore_v01(string s) {
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