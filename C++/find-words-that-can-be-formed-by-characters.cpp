class Solution {
    //https://leetcode.com/problems/find-words-that-can-be-formed-by-characters
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charsv = vector<int>(26,0);
        for(auto &c: chars) charsv[c-'a']++;
        int ans=0;
        for(auto& w: words) {
            vector<int> v = charsv;
            bool is_break = false;
            for(auto &c:w) {
                if(--v[c-'a']<0) is_break = true;
                if(is_break)break;
            }
            if(is_break==false)ans+=w.length();
        }
        return ans;
    }
};