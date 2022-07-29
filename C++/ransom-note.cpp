class Solution {
    //https://leetcode.com/problems/ransom-note/
    //article https://leetcode.com/problems/ransom-note/discuss/2351644/C%2B%2B-or-4-lines-by-Hash-Map
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v = vector<int>(256,0);
        for(auto &c:magazine) v[c]++;
        for(auto &c:ransomNote) if(--v[c]<0) return false;
        return true;
    }
};