class WordFilter {
    //https://leetcode.com/problems/prefix-and-suffix-search
public:
    vector<string> *w;
    WordFilter(vector<string>& words) {
        w = &words;
    }
    
    int f(string prefix, string suffix) {
        int i = w->size()-1;
        while(i>=0) {
            string str = (*w)[i--];
            if(str.find(prefix) == 0 ) {
                int rfind_expected_idx = str.size() - suffix.size() ;    
                if(str.rfind(suffix) == rfind_expected_idx) {
                    return i+1;
                }
            }
        }
        return -1;   
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */