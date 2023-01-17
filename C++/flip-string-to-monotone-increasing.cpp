class Solution {
    //https://leetcode.com/problems/flip-string-to-monotone-increasing/
public:
    int minFlipsMonoIncr(string s) {
        int L_ocnt = 0, R_zcnt = 0, n = s.length();//left one count, right zero count,        
        int ans = INT_MAX;//find min value min {left ocnt + right zcnt}
        for(auto &c:s) R_zcnt+=c=='0';
        ans = min(ans, L_ocnt+R_zcnt);
        for(int i = 0;i<n; i++) {
            if(s[i]=='0') 
                R_zcnt--;
            else 
                L_ocnt++;
            ans = min(ans, L_ocnt+R_zcnt);
        }
        return ans;
        
    }
};