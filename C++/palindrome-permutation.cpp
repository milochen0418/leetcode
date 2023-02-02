class Solution {
    //https://leetcode.com/problems/palindrome-permutation
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &c: s) mp[c]++;
        int odd_cnt = ((int)s.length())%2;
        for(auto &[c,cnt]:mp) if(cnt%2==1) odd_cnt-=1;
        return odd_cnt==0;
    }
};