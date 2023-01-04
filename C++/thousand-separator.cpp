class Solution {
    //https://leetcode.com/problems/thousand-separator
public:
    string thousandSeparator(int n) {
        if(n==0) return "0";
        string ans;
        int cnt=0;
        while(n>0) {
            if(cnt%3==0) ans.push_back('.');
            ans.push_back('0'+n%10);
            cnt++;
            n/=10;
        }
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        return ans;
    }
};