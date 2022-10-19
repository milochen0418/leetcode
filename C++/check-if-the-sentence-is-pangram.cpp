class Solution {
    //https://leetcode.com/problems/check-if-the-sentence-is-pangram
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(auto &c: sentence) s.insert(c);
        return s.size()==26;
    }
};