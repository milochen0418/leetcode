class Solution {
    //https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts
public:
    string generateTheString(int n) {
        string ans = string(n,'a');
        if(n%2==0) ans[0]='b';
        return ans;
    }
};