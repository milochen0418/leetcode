class Solution {
    //https://leetcode.com/problems/determine-if-two-strings-are-close/
    //article https://leetcode.com/problems/determine-if-two-strings-are-close/discuss/2868180/C%2B%2B-or-array-approach-or-easy-or-explanation
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        
        vector<int> v1=vector<int>(26,0), v2=vector<int>(26,0);
        vector<int> v1s=vector<int>(26,0), v2s=vector<int>(26,0);
        for(int i = 0; i<word1.length();i++) {
            v1s[word1[i]-'a'] = 1;
            v2s[word2[i]-'a'] = 1;
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }
        if(v1s != v2s) return false;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};