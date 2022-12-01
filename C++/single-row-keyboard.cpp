class Solution {
    //https://leetcode.com/problems/single-row-keyboard
public:
    int calculateTime(string keyboard, string word) {
        vector<int> v = vector<int>(26,0); //map of char to index
        for(int i = 0; i<26;i++) v[keyboard[i]-'a'] = i;
        int n = word.size(), ans = v[word[0]-'a'];
        for(int i = 1;i<n;i++) ans += abs(v[word[i]-'a'] - v[word[i-1]-'a']);
        return ans;
    }
};