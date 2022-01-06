class WordFilter {
    //https://leetcode.com/problems/prefix-and-suffix-search
    //Idea: We want to use prefix_suffix  to search data in hash map  (unordered_map). 
    //
    //for each string in words, there are many kind of pattern prefix_suffix for this one string.
    // So we just need to put all kind of case prefix_suffix into the unordered map. 
    //Then search it by prefix_suffix

private:
    unordered_map<string, int> m;    
public:
    WordFilter(vector<string> words) {
        /*
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                for (int j = 0; j <= words[k].size(); ++j) {
                    m[words[k].substr(0, i) + "_" + words[k].substr(words[k].size() - j)] = k;
                }
            }
        }
        */
        
        for(int k = 0; k < words.size(); k++) {
            string& word = words[k];
            int word_len = word.length();            
            const char * word_array =  (const char*)word.c_str();

            for (int i = 0; i <= word_len; i++) {
                for (int j = 0; j <= word_len; j++) {
                    char str_array[(i+j+1)+1];
                    str_array[(i+j+1)] = '\0';
                    strncpy(str_array, word_array,i);
                    str_array[i] = '_';
                    strncpy(&str_array[i+1],&word_array[word_len - j], j );
                    m[str_array] = k;
                    
                }
            }
        }
        
        
    }

    int f(string prefix, string suffix) {
        return (m.count(prefix + "_" + suffix)) ? m[prefix + "_" + suffix] : -1;
    }

};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */