class Solution {
    //https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int>mp;
        for(auto &w: words) {
            for(auto &c: w) {
                mp[c]++;
            }
        }
        for(auto &[k,v]:mp) {
            if(v%n!=0)return false;
        }
        return true;
    }
};