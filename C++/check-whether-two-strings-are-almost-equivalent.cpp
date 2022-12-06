class Solution {
    //https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> v1=vector<int>(26,0),v2=v1;
        for(auto &c:word1) v1[c-'a']++;
        for(auto &c:word2) v2[c-'a']++;
        for(int i = 0; i<26;i++) if(abs(v1[i]-v2[i])>3) return false;
        return true;
    }
};