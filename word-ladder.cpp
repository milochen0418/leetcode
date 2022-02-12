class Solution {
    //https://leetcode.com/problems/word-ladder/
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<int>> mp;
        int n = wordList.size();
        for(int i=0; i<n; i++) {
            string& str = wordList[i];
            int m = str.length();
            string key = str;
            for(int j = 0; j<m; j++) {
                char orig_char = s[j];
                for(int k=0;k<26;k++) {
                    char new_char = k + 'a';
                    if(new_char != orig_char)
                    key[j]=new_char
                    mp[key].push_back();
                }
                s[j] = orig_char;
            }
        }
        
        
    }
};