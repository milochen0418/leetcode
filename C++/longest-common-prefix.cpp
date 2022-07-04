class Solution {
    //https://leetcode.com/problems/longest-common-prefix
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = INT_MAX;
        for(auto &s: strs) n = min(n, (int)s.length());
        for(int i=0; i<n; i++) {
            char c = '\0';
            for(auto &s: strs) {
                if(c=='\0') 
                    c=s[i];
                else {
                    if(s[i] != c) return ans;
                }
            }
            ans.push_back(c);
        }
        return ans;
        
    }
};