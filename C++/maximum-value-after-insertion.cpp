class Solution {
    //https://leetcode.com/problems/maximum-value-after-insertion
    //article https://leetcode.com/problems/maximum-value-after-insertion/discuss/4357387/C%2B%2B-simple-7-lines-O(N)
public:
    string maxValue(string s, int x) {
        string ans;
        int n = s.length(), d=x+'0', neg=(s[0]=='-'), i=(s[0]=='-');
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