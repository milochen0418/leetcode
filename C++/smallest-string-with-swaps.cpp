class Solution {
    //https://leetcode.com/problems/smallest-string-with-swaps/
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const char *cstr = s.c_str();
        char str[(int)(s.length()+1)];         
        for(int i = 0; i<s.length();i++) str[i] = cstr[i];
        str[(int)s.length()] = '\0';
        
        sort(pairs.begin(), pairs.end(), [](auto& lhs, auto& rhs){
           if (lhs[0] == rhs[0]) {
               return lhs[1] > rhs[1];
           } else {
               return lhs[0] < rhs[0];
           }
        });
        for(auto &p: pairs) swap(str[p[0]], str[p[1]]);
        
        return str;
        
    }
};