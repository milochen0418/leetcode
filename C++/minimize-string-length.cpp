class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> set;
        for(auto &c: s) 
            set.insert(c);
        return (int)set.size();
    }
};