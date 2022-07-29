class Solution {
    //https://leetcode.com/problems/ransom-note/
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v = vector<int>(256,0);
        for(auto &c:magazine) v[c]++;
        for(auto &c:ransomNote) if(--v[c]<0) return false;
        return true;
    }
};