class Solution {
    //https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case
public:
    string greatestLetter(string s) {
        unordered_set<char> set,SET;
        char ansc=0;
        for(auto &c:s) ((c>='a')?set:SET).insert(c);
        for(auto &C:SET) if(set.find(C-'A'+'a')!=set.end()) ansc=max(ansc, C);
        if(ansc==0) return "";
        return string({ansc});
    }
};