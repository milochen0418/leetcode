class Solution {
    //https://leetcode.com/problems/determine-if-string-halves-are-alike/
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cntA=0,cntB=0;
        for(int i = 0;i<s.length();i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                if(i<s.length()/2) 
                    cntA++;
                else 
                    cntB++;
            }
        }
        return cntA==cntB;
    }
};