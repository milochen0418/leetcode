class WordDictionary {
    //https://leetcode.com/problems/design-add-and-search-words-data-structure/
public:
    unordered_map<char, unordered_set<string>> mp[501];
    WordDictionary() {
    }
    
    void addWord(string word) {
        const char* str = word.c_str();
        int i=0;
        while(str[i]!='\0') {
            if(mp[i].find(str[i]) == mp[i].end()) {
                mp[i].insert({str[i], unordered_set<string>()});
            }
            if(mp[i].find('.') == mp[i].end()) {
                mp[i].insert({'.', unordered_set<string>()});
            }
            mp[i][str[i]].insert(word);
            mp[i]['.'].insert(word);            
            i++;
        }
    }
    
    bool search(string word) {
        const char* str = word.c_str();
        int i = 0;
        while(str[i]!='\0') {
            char c = str[i];
            if(mp[i].find(c) == mp[i].end()) return false;
            
            if(str[i]!='.') {
                if(mp[i][c].find(word) == mp[i][c].end()) {
                    return false;
                }                
            } else {
                bool is_match_dot_word = false;
                for(auto& dot_word:mp[i][c]) {
                    if(dmatch(dot_word, word)) {
                        is_match_dot_word = true;
                        break;
                    }
                }
                if(is_match_dot_word == false) return false;
            }
             
            i++;
        }
        return true;
    }
    bool dmatch(const string& dot_word, const string& word ) {
        int n = word.length();
        if(dot_word.length() != n) return false;
        const char* dot_str = dot_word.c_str();
        const char* str = word.c_str();
        for(int i=0;i<n;i++) {
            if(dot_str[i]=='.') continue;
            if(dot_str[i]!=str[i]) return false;
        }
        return true;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */