class Solution {
    //https://leetcode.com/problems/word-pattern/
    //article https://leetcode.com/problems/word-pattern/discuss/2981633/C%2B%2B-or-TC%3AO(N)-by-Hash-Set
public:
    bool wordPattern(string pattern, string s) {
        unordered_set<string> ss;
        int n = s.length(),j = 0;
        vector<string> vs =vector<string>(256,"");
        string w="";
        for(int i=0;i<n;i++) {
            w.push_back(s[i]);
            if(i+1>=n || s[i+1]==' ') {
                if(vs[pattern[j]]=="") {
                    if(ss.find(w) != ss.end()) return false;
                    vs[pattern[j]] = w;
                    ss.insert(w);
                } else {
                    if(vs[pattern[j]] != w) return false;
                }
                w="";
                j++,i++;
            } 
        }
        if(j<(int)pattern.size()) return false;
        return true;
    }

    bool wordPattern_v01(string pattern, string s) {
        
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