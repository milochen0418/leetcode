class Solution {
    //https://leetcode.com/problems/valid-word-abbreviation
    //article https://leetcode.com/problems/valid-word-abbreviation/discuss/3151992/C%2B%2B-100-beats
public:
    bool validWordAbbreviation(string word, string abbr) {
        function<bool(char)> is_digit=[](char c) {
            return ('9'>=c && c>='0');
        };
        function<bool(char)> is_letter=[](char c) {
            return ('z'>=c && c>='a');
        };
        
        int n = word.size();
        vector<string> v;
        string s;
        char prev='-'; 
        for(auto &c:abbr) {
            if((is_digit(c) && is_letter(prev)) 
            ||(is_letter(c) && is_digit(prev)) ){
                v.push_back(s);
                s="";
            }
            s.push_back(c);
            prev = c;
        }
        if(s.length()>0) v.push_back(s);

        
        int i = 0;         
        for(auto &s:v) {
            if(i>=n)return false;
            if(is_digit(s[0])) {
                if(s[0]=='0') return false;
                int len = stoi(s);
                i+=len;
            } else {
                for(int j = 0;j<s.length();j++,i++) 
                    if(i>=n || word[i] != s[j]) 
                        return false;
            }
        }
        return (i==n);
    }
};