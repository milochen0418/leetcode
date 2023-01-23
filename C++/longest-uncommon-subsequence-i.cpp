class Solution {
    //https://leetcode.com/problems/longest-uncommon-subsequence-i
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        return max(a.length(),b.length());
    }
};