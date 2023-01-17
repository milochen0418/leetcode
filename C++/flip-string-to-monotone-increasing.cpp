class Solution {
    //https://leetcode.com/problems/flip-string-to-monotone-increasing/
public:
    int minFlipsMonoIncr(string s) {
        int v = 0, zcnt=0, n = s.length(), minv = 0;
        for(int i = 0;i<n; i++) {
            zcnt+=(s[i]=='0');
            v+=2*(s[i]=='1')-1;
            minv = min(minv, v);
        }
        return minv+zcnt;
    }

    int minFlipsMonoIncr_v03(string s) {
        int v = 0, n = s.length(), ans = INT_MAX;
        for(auto &c:s) v+=c=='0';
        ans = min(ans, v);
        for(int i = 0;i<n; i++) {
            v+=2*(s[i]=='1')-1;
            ans = min(ans, v);
        }
        return ans;
    }

    int minFlipsMonoIncr_v02(string s) {
        int v = 0, n = s.length(), ans = INT_MAX;
        for(auto &c:s) v+=c=='0';
        ans = min(ans, v);
        for(int i = 0;i<n; i++) {
            if(s[i]=='0')
                v--;
            else
                v++;
            ans = min(ans, v);
        }
        return ans;
    }
    int minFlipsMonoIncr_v01(string s) {
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