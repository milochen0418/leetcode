class Solution {
    //https://leetcode.com/problems/count-the-number-of-consistent-strings
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<int> v = vector<int>(256,0);
        for(auto &c:allowed) v[c]++;
        for(auto &w: words) {
            bool is_break = false;
            for(auto &c: w) if(v[c]==0) {
                is_break = true;
                break;
            }
            if(!is_break) ans++;
        }
        return ans;
    }
};