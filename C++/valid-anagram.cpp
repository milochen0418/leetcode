class Solution {
    //https://leetcode.com/problems/valid-anagram
public:
    bool isAnagram(string s, string t) {
        vector<int>mps = vector<int>(256,0);
        vector<int>mpt = vector<int> (256,0);
        for(auto&c:s)mps[c]++;
        for(auto&c:t)mpt[c]++;
        return mps==mpt;
    }
};