class Solution {
    //https://leetcode.com/problems/word-pattern/
public:
    bool wordPattern(string pattern, string s) {
        
        /*split s into strs vector<string> by ' '*/
        vector<string> strs; 
        stringstream ss(s);
        string segment;
        while(getline(ss, segment, ' ')) {
           strs.push_back(segment);
        }
        
        if(pattern.size() != strs.size()) {
            return false;
        } 
        int len = strs.size();
        const char* ps = pattern.c_str();
        
        unordered_map<string, char> mp1;
        unordered_map<char, string> mp2;
        for(int i=0; i<len; i++) {
            string str = strs[i];
            char c = ps[i];
            if(mp1.find(str) != mp1.end()){
                if(mp1[str] != c) {
                    return false;
                }
            } else {
                mp1[str] = c;
            }
            if(mp2.find(c) != mp2.end()) {
                if(mp2[c] != str) {
                    return false;
                }
            } else {
                mp2[c] = str;
            }
        }      
        return true;
    }
};