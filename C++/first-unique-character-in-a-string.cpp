class Solution {
    //https://leetcode.com/problems/first-unique-character-in-a-string
public:
    int firstUniqChar(string s) {
        vector<int> v = vector<int>(256,0);
        for(auto&c:s) v[c]++;
        for(int i = 0;i<s.length();i++) {
            if(v[s[i]]==1) return i;
        }
        return -1;
            
    }
};