class Solution {
    //https://leetcode.com/problems/unique-morse-code-words
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mcode= {
            /*abcde*/".-","-...","-.-.","-..",".",
            /*fghij*/"..-.","--.","....","..",".---",
            /*klmno*/"-.-",".-..","--","-.","---",
            /*pqrst*/".--.","--.-",".-.","...","-",
            /*uvwxy*/"..-","...-",".--","-..-","-.--",
            /*z*/"--.."
        };
        unordered_set<string> ans;
        for(auto &w:words) {
            string s; 
            for(auto &c:w) s.append(mcode[c-'a']);
            ans.insert(s);
        }
        return ans.size();
        
    }
};