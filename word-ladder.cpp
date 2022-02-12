class Solution {
    //https://leetcode.com/problems/word-ladder/
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<int>> mp;
        int n = wordList.size();
        vector<bool> traveled(n, false);
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
                    mp[key].push_back(i);
                }
                s[j] = orig_char;
            }
        }
        
        queue<tuple<int,int,bool>> q;
        for(auto& i:mp[beginWord]) q.push({i,1});
        while(!q.empty()) {
            pair<int,int> p = q.top();
            string &str = wordList[i];
            int len = p.second;
            q.pop();
            //for(auto& i:mp[str]) q.push({})
            
        }
    }
};