class Solution {
    //https://leetcode.com/problems/word-ladder/
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return answer1(beginWord, endWord, wordList);
        unordered_map<string,vector<int>> mp;
        int n = wordList.size();
        vector<bool> traveled(n, false);
        for(int i=0; i<n; i++) {
            string& str = wordList[i];
            int m = str.length();
            string key = str;
            for(int j = 0; j<m; j++) {
                char orig_char = key[j];
                for(int k=0;k<26;k++) {
                    char new_char = k + 'a';
                    if(new_char != orig_char) {
                        key[j]=new_char;
                        mp[key].push_back(i);
                    }
                }
                key[j] = orig_char;
            }
        }
        
        queue<pair<int,int>> q; //index to string in wordList,len
        for(auto& i:mp[beginWord]) {
            if(traveled[i] == false) {
                if(endWord == wordList[i]) {
                    return 1+1;
                }
                q.push({i,1});
                traveled[i] = true;                
            }
        }
        while(!q.empty()) {
            pair<int,int>& p = q.front();
            string &str = wordList[p.first];
            int len = p.second;
            if(endWord == str) {
                return len+1;
            }

            q.pop();
            for(auto& i:mp[str]) {
                if(traveled[i] == false) {
                    q.push({i,len+1});
                    traveled[i] = true;
                    
                }
            }
        }
        return 0;
    }
    
    int answer1(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<int>> mp;
        int n = wordList.size();
        vector<bool> traveled(n, false);
        for(int i=0; i<n; i++) {
            string& str = wordList[i];
            int m = str.length();
            string key = str;
            for(int j = 0; j<m; j++) {
                char orig_char = key[j];
                for(int k=0;k<26;k++) {
                    char new_char = k + 'a';
                    if(new_char != orig_char) {
                        key[j]=new_char;
                        mp[key].push_back(i);
                    }
                }
                key[j] = orig_char;
            }
        }
        
        queue<pair<int,int>> q; //index to string in wordList,len
        for(auto& i:mp[beginWord]) {
            if(traveled[i] == false) {
                if(endWord == wordList[i]) {
                    return 1+1;
                }
                q.push({i,1});
                traveled[i] = true;                
            }
        }
        while(!q.empty()) {
            pair<int,int>& p = q.front();
            string &str = wordList[p.first];
            int len = p.second;
            if(endWord == str) {
                return len+1;
            }

            q.pop();
            for(auto& i:mp[str]) {
                if(traveled[i] == false) {
                    q.push({i,len+1});
                    traveled[i] = true;
                    
                }
            }
        }
        return 0;
    }
    
};

/* testcase
"hit"
"hot"
["hot","dot","dog","lot","log","cog"]
"hit"
"cog"
["hot","dot","dog","lot","log","cog"]
"hit"
"cog"
["hot","dot","dog","lot","log"]
*/

