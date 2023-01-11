class Solution {
    //https://leetcode.com/problems/split-a-string-in-balanced-strings
public:
    int balancedStringSplit(string s) {
        int cnt=0,ans=0;
        for(auto &c:s) {
            cnt += c=='R'?-1:1;
            if(cnt==0) ans++;
        }
        return ans;
    }
};