class Solution {
    //https://leetcode.com/problems/count-prefixes-of-a-given-string
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for(auto &w: words) {
            ans++;
            for(int i = 0; i < w.length();i++) {
                if(w[i] != s[i]) {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};