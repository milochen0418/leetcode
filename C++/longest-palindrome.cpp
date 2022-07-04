class Solution {
    //https://leetcode.com/problems/longest-palindrome
public:
    int longestPalindrome(string s) {
        vector<int> cnt_mp (256,0);
        for(auto &c: s) cnt_mp[c]++;
        bool odd = false;
        int ans = 0;
        for(auto &i:cnt_mp) {
            ans+=(i-i%2);
            if(!odd && i%2==1) odd = true;
        }
        ans+=(odd==true);
        return ans;
    }
};