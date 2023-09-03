class Solution {
    //https://leetcode.com/problems/split-strings-by-separator
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        char sep = separator;
        for(auto &w : words) {
            w.push_back(sep);
            string s = "";
            for(auto &c: w) {
                if(c!=sep) {
                    s.push_back(c);
                } else {
                    if(s.length()>0) {
                        ans.push_back(s);
                        s = "";
                    }
                }
            }
        }
        return ans;
    }
};