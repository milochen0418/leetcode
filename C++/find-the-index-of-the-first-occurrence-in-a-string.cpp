class Solution {
    //https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        return ans==string::npos?-1:ans;
    }
};