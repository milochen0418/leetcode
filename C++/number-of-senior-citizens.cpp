class Solution {
    //https://leetcode.com/problems/number-of-senior-citizens
public:
    int countSeniors(vector<string>& details) {
        int ans = 0; //s[11],s[12] is age
        for(auto &s:details) if( (s[11]-'0')*10 + (s[12]-'0') > 60) ans++;
        return ans;
    }
};