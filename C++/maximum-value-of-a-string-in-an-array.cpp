class Solution {
    //https://leetcode.com/problems/maximum-value-of-a-string-in-an-array
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(auto &s: strs) ans = max(ans, getval(s));
        return ans;
    }
    int getval(string& s) {
        for(auto &c:s) if(c>'9' || c<'0') return s.length();
        return stoi(s);
    }
};