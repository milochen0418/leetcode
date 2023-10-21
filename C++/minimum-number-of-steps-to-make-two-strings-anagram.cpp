class Solution {
    //https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
public:
    int minSteps(string s, string t) {
        vector<int> mp = vector<int>(26,0);
        int ans=0;
        for(auto &c: s) mp[c-'a']++;
        for(auto &c: t) mp[c-'a']--;
        for(auto &v: mp)ans+=abs(v);
        return ans/2;
    }
};