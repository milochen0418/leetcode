class Solution {
    //https://leetcode.com/problems/maximum-value-after-insertion
public:
    string maxValue(string s, int x) {
        string ans;
        int n = s.length(), d=x+'0';
        int neg = (s[0]=='-'), i = neg;
        if(neg) ans.push_back('-');
        while(i<n && (neg?(d>=s[i]):(d<=s[i])) ) ans.push_back(s[i++]);
        ans.push_back(d);
        while(i<n) ans.push_back(s[i++]);
        return ans;
    }
    string maxValue_v01(string s, int x) {
        string ans;
        int n = s.length();
        if(s[0]=='-') {
            int i = 1;
            ans.push_back('-');
            while(i<n) {
                if(x < s[i]-'0' ) {
                    ans.push_back(x+'0');
                    break;
                } 
                ans.push_back(s[i++]);
            }
            if(i<n) 
                while(i<n) ans.push_back(s[i++]);
            else 
                ans.push_back(x+'0');
        } else {
            int i = 0;
            while(i<n) {
                if(s[i]-'0' < x) {
                    ans.push_back(x+'0');
                    break;
                } 
                ans.push_back(s[i++]);
            }
            if(i<n)
                while(i<n) ans.push_back(s[i++]);
            else 
                ans.push_back(x+'0');
        }
        return ans;
    }
};