class Solution {
    //https://leetcode.com/problems/check-if-the-number-is-fascinating
public:
    bool isFascinating(int n) {
        string A = to_string(n) + to_string(2*n) + to_string(3*n);
        unordered_set<char> s; 
        for(auto &c: A) s.insert(c);
        return s.size()==9 && s.find('0')==s.end() && A.length()==9;
    }
};