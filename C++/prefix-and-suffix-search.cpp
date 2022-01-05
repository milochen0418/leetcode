class WordFilter {
    //https://leetcode.com/problems/prefix-and-suffix-search
    //refer Solution 2 in this address https://www.cnblogs.com/grandyang/p/8331660.html 
private:
    unordered_map<string, vector<int>> pre_map;
    unordered_map<string, vector<int>> suf_map;    
public:
    WordFilter(vector<string> words) {
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                pre_map[words[k].substr(0, i)].push_back(k);
            }
            for (int i = 0; i <= words[k].size(); ++i) {
                suf_map[words[k].substr(words[k].size() - i)].push_back(k);
            }
        }
    }

    int f(string prefix, string suffix) {
        if (!pre_map.count(prefix) || !suf_map.count(suffix)) {
            return -1;
        }
        vector<int> pre = pre_map[prefix];
        vector<int> suf = suf_map[suffix];
        int i = pre.size() - 1, j = suf.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pre[i] < suf[j]) { 
                --j;
            }
            else if (pre[i] > suf[j]) {    
                --i;
            }
            else {
                return pre[i];
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